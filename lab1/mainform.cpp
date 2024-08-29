//---------------------------------------------------------------------------

#include <math.h>
#include <vcl.h>
#pragma hdrstop

#include "mainform.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfMain *fMain;
void Stoppoints (int iMaxpoints, int iStoppoints, int iCount,  TStringGrid *sgCurrentpoints, TStringGrid *sgResult)
{
 sgCurrentpoints->ColCount=iStoppoints;
 sgResult->ColCount=iStoppoints+1;
 sgResult->RowCount=iCount+3;
 for (int i=iStoppoints-1; i>=0; i--)
 {
  sgCurrentpoints->Cells[i][0]=iMaxpoints;
  sgResult->Cells[i+1][0]=iMaxpoints;
  iMaxpoints=iMaxpoints/2;
 }
 for (int i=1; i<iCount+2; i++)
 {
  sgResult->Cells[0][i]=i;
 }
 sgResult->Cells[0][iCount+1]="МО";
 sgResult->Cells[0][iCount+2]="Дисп.";
}
//---------------------------------------------------------------------------
void MonteCarlo (float fCX, float fCY, float fR, int iCount, int iMaxpoints, int iPrecision, TStringGrid *sgCurrentpoints, TStringGrid *sgResult)
{
 int i=0, j=0, k=0, iCounter=0;
 float fRX=0, fRY=0;
 randomize();
 for (i=0; i<iCount; i++)
 {
  iCounter=0;
  for (j=0; j<=iMaxpoints; j++)
  {
   fRX=fCX+fR-(float)(2*fR)*random(pow(10,iPrecision))/pow(10,iPrecision);
   fRY=fCY+fR-(float)(2*fR)*random(pow(10,iPrecision))/pow(10,iPrecision);
   //ShowMessage((float)random(pow(10,iPrecision))/pow(10,iPrecision));
   if ((powl((fRX-fCX),2) + powl((fRY-fCY),2)) <= powl(fR,2))
   {
    iCounter=iCounter+1;
   }
   for (k=0; k<sgCurrentpoints->ColCount; k++)
   {
    if (j==sgCurrentpoints->Cells[k][0].ToIntDef(0))
    {
     sgResult->Cells[k+1][i+1]=FloatToStr((float)powl(2*fR,2)*iCounter/(j+1));
    }
   }
  }
 }
 float fMO, fVariance;
 for (i=0; i<sgCurrentpoints->ColCount; i++)
 {
  fMO=0;
  for (j=0; j<iCount; j++)
  {
   fMO=fMO+sgResult->Cells[i+1][j+1].ToDouble();
  }
  fMO=(float)fMO/iCount;
  sgResult->Cells[i+1][iCount+1]=fMO;
  for (j=0; j<iCount; j++)
  {
   fVariance=fVariance + powl((sgResult->Cells[i+1][j+1].ToDouble()-fMO),2);
  }
  fVariance=(float)fVariance/(iCount);
  sgResult->Cells[i+1][iCount+2]=fVariance;
 }
}
//---------------------------------------------------------------------------
__fastcall TfMain::TfMain(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TfMain::bCalculateClick(TObject *Sender)
{
 MonteCarlo (eCirclex->Text.ToDouble(), eCircley->Text.ToDouble(), eRadius->Text.ToDouble(), eCount->Text.ToIntDef(0), eMaxpoints->Text.ToIntDef(0), ePrecision->Text.ToIntDef(1), sgCurrentpoints, sgResult);
 lReal->Caption="Площадь круга: "+FloatToStr(M_PI*powl(eRadius->Text.ToDouble(),2));
}
//---------------------------------------------------------------------------

void __fastcall TfMain::udStoppointsClick(TObject *Sender,
      TUDBtnType Button)
{
 Stoppoints(eMaxpoints->Text.ToIntDef(0), eStoppoints->Text.ToIntDef(0), eCount->Text.ToIntDef(0), sgCurrentpoints, sgResult);
}
//---------------------------------------------------------------------------

void __fastcall TfMain::FormCreate(TObject *Sender)
{
 Stoppoints(eMaxpoints->Text.ToIntDef(0), eStoppoints->Text.ToIntDef(0), eCount->Text.ToIntDef(0), sgCurrentpoints, sgResult);
}
//---------------------------------------------------------------------------

void __fastcall TfMain::udCountClick(TObject *Sender, TUDBtnType Button)
{
 Stoppoints(eMaxpoints->Text.ToIntDef(0), eStoppoints->Text.ToIntDef(0), eCount->Text.ToIntDef(0), sgCurrentpoints, sgResult);
}
//---------------------------------------------------------------------------

void __fastcall TfMain::sgCurrentpointsExit(TObject *Sender)
{
 for (int i=0; i<sgCurrentpoints->ColCount; i++)
 {
  sgResult->Cells[i+1][0]=sgCurrentpoints->Cells[i][0];
 }
}
//---------------------------------------------------------------------------

void __fastcall TfMain::eMaxpointsChange(TObject *Sender)
{
 Stoppoints(eMaxpoints->Text.ToIntDef(0), eStoppoints->Text.ToIntDef(0), eCount->Text.ToIntDef(0), sgCurrentpoints, sgResult);        
}
//---------------------------------------------------------------------------

