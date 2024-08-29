//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "mainform.h"
#include "math.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfMain *fMain;
TStringGrid *sgModel;
TPageControl *pcModel;
TTabSheet *tsModel;
TLabel *lModel;
float fEfficient (int iV, int iA, int iB, int iZ, int iPeriod, TStringGrid *sgModel, bool bDay, bool bMonth, bool bYear)
{
 int iBt=0, iP=0, iVnow=iV, iVpast=iV;
 int t=0, iZapas=0, iNastr=0, iShtraf=0, iS=0;
 float fCost=0, fCoeffAll=0, fCoeffReal=0, fOldcoeff=1;
 for (t=0; t<iPeriod; t++)
 {
  fOldcoeff=fCoeffReal;
  sgModel->Cells[5][t+1]=iS;
  iBt=abs(iVnow-iB+random(2*iB)); //определяем текущую реальную производительность
  if (t>0&&iVnow==0) iBt=0;
  iP=abs(iV-iA+random(2*iA)); //определяем потребность
  iNastr=iZ*abs(iVnow-iVpast); //определяем стоимость перенастройки
  if (t>0)
  {
   if ((iS-iP)<0)
   {
    iShtraf=5*iZ*abs(iS-iP);//штраф за недопоставку
    fCost=1.5*iZ*iS; //определение цены за часть поставленной продукции
    fCoeffReal=fCoeffReal+1.5*iZ*iS-iShtraf-iZapas-iNastr; //определение выручки
    iS=0;
   }
   else
   {
    iS=iS-iP;
    iShtraf=0; //вся требуемая продукция поставлена, штрафа нет
    fCost=1.5*iZ*iP; //стоимость поставляемой продукции
    fCoeffReal=fCoeffReal+1.5*iZ*iP-iZapas-iNastr;  //определение выручки
   }
   fCoeffAll=fCoeffAll+1.5*iZ*iP; //определение максимальной выручки
  }
  iVpast=iVnow;
  sgModel->Cells[0][t+1]=iVnow;
  sgModel->Cells[1][t+1]=iBt;
  sgModel->Cells[2][t+1]=iP;
  sgModel->Cells[3][t+1]=iZapas;
  sgModel->Cells[4][t+1]=iNastr;
  sgModel->Cells[6][t+1]=iShtraf;
  sgModel->Cells[7][t+1]=fCost;
  sgModel->Cells[8][t+1]=fCoeffReal-fOldcoeff;
  iZapas=4*iZ*iS; //определяем стоимость хранения запасов
  if (t>0)
  {
   if (bDay==true&&(fCoeffReal/fCoeffAll)>1) iVnow=(iVnow-1-iS);
   if (bDay==true&&(fCoeffReal/fCoeffAll)<1) iVnow=(iVnow+1-iS);
   if (bMonth==true&&((t+1)%20==0)&&(fCoeffReal/fCoeffAll)>1) iVnow=(iVnow-1-iS);
   if (bMonth==true&&((t+1)%20==0)&&(fCoeffReal/fCoeffAll)<1) iVnow=(iVnow+1-iS);
   if (bYear==true&&((t+1)%240==0)&&(fCoeffReal/fCoeffAll)>1) iVnow=(iVnow-1-iS);
   if (bYear==true&&((t+1)%240==0)&&(fCoeffReal/fCoeffAll)<1) iVnow=(iVnow+1-iS);
   if (iVnow<0) iVnow=0;
  }//if (bYear==true&&((t+1)%240==0)) iVnow=abs(iV-iB+random(2*iB));
  iS=iS+iBt; //определяем текущий запас продукции
 }
 sgModel->Cells[0][iPeriod+1]="Итого:";
 sgModel->Cells[8][iPeriod+1]=fCoeffReal;
 return fCoeffReal/fCoeffAll;
}
//---------------------------------------------------------------------------
__fastcall TfMain::TfMain(TComponent* Owner)
        : TForm(Owner)
{

}
//---------------------------------------------------------------------------
void __fastcall TfMain::bProcessClick(TObject *Sender)
{
 int i=0;
 float fCoeff=0, fTemp=0;
 if (pcModel) delete pcModel;
 pcModel=new TPageControl(fMain);
 pcModel->Parent=pModel;
 pcModel->Align=alClient;
 for (i=0; i<eHowmanymodels->Text.ToIntDef(3); i++)
 {
  tsModel=new TTabSheet(fMain);
  tsModel->PageControl=pcModel;
  tsModel->Caption=AnsiString(i+1)+" модель";
  sgModel=new TStringGrid(fMain);
  sgModel->Parent=tsModel;
  sgModel->Align=alClient;
  sgModel->FixedCols=0;
  sgModel->ColCount=9;
  sgModel->RowCount=ePeriod->Text.ToIntDef(240)+2;
  sgModel->Cells[0][0]="План";
  sgModel->Cells[1][0]="Реально";
  sgModel->Cells[2][0]="Потребность";
  sgModel->Cells[3][0]="Цена хранения";
  sgModel->Cells[4][0]="Цена перенастройки";
  sgModel->Cells[5][0]="Текущий запас";
  sgModel->Cells[6][0]="Штраф";
  sgModel->Cells[7][0]="Цена поставки";
  sgModel->Cells[8][0]="Прибыль";
  lModel=new TLabel(fMain);
  lModel->Parent=tsModel;
  lModel->Align=alBottom;
  fTemp=fEfficient (eV->Text.ToIntDef(10), eA->Text.ToIntDef(7), eB->Text.ToIntDef(2), eZ->Text.ToIntDef(1), ePeriod->Text.ToIntDef(240), sgModel, cbDay->Checked, cbMonth->Checked, cbYear->Checked);
  lModel->Caption="Относительный коэффициент эффективности: "+AnsiString(100*fTemp)+" %";
  fCoeff=fCoeff+fTemp;
 }
 lAverage->Caption="Средний относительный коэффициент эффективности: "+AnsiString(100*fCoeff/eHowmanymodels->Text.ToIntDef(3))+" %";
}
//---------------------------------------------------------------------------

