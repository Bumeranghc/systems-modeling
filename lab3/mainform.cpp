//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <math.h>
#include "mainform.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfMain *fMain;
float F(float x, float a, float b)
{
 if (x<a) return 0;
 if ((x>a)&&(x<=b)) return (x-a)/(b-a);
 if (x>b) return 1;
 else return 0;
}
float f(float x, float a, float b)
{
 if ((x>=a)&&(x<=b)) return 1/(b-a);
 else return 0;
}
float *fX;
float *fP;
float fPearson[30][6]={
{6.6, 5.0, 3.8, 0.0039, 0.00098, 0.00016},
{9.2, 7.4, 6.0, 0.103, 0.051, 0.020},
{11.3, 9.4, 7.8, 0.352, 0.216, 0.115},
{13.3, 11.1, 9.5, 0.711, 0.484, 0.297},
{15.1, 12.8, 11.1, 1.15, 0.831, 0.554},
{16.8, 14.4, 12.6, 1.64, 1.24, 0.872},
{18.5, 16.0, 14.1, 2.17, 1.69, 1.24},
{20.1, 17.5, 15.5, 2.73, 2.18, 1.65},
{21.7, 19.0, 16.9, 3.33, 2.70, 2.09},
{23.2, 20.5, 18.3, 3.94, 3.25, 2.56},
{24.7, 21.9, 19.7, 4.57, 3.82, 3.05},
{26.2, 23.3, 21.0, 5.23, 4.40, 3.57},
{27.7, 24.7, 22.4, 5.89, 5.01, 4.11},
{29.1, 26.1, 23.7, 6.57, 5.63, 4.66},
{30.6, 27.5, 25.0, 7.26, 6.26, 5.23},
{32.0, 28.8, 26.3, 7.96, 6.91, 5.81},
{33.4, 30.2, 27.6, 8.67, 7.56, 6.41},
{34.8, 31.5, 28.9, 9.39, 8.23, 7.01},
{36.2, 32.9, 30.1, 10.1, 8.91, 7.63},
{37.6, 34.2, 31.4, 10.9, 9.59, 8.26},
{38.9, 35.5, 32.7, 11.6, 10.3, 8.90},
{40.3, 36.8, 33.9, 12.3, 11.0, 9.54},
{41.6, 38.1, 35.2, 13.1, 11.7, 10.2},
{43.0, 39.4, 36.4, 13.8, 12.4, 10.9},
{44.3, 40.6, 37.7, 14.6, 13.1, 11.5},
{45.6, 41.9, 38.9, 15.4, 13.8, 12.2},
{47.0, 43.2, 40.1, 16.2, 14.6, 12.9},
{48.3, 44.5, 41.3, 16.9, 15.3, 13.6},
{49.6, 45.7, 42.6, 17.7, 16.0, 14.3},
{50.9, 47.0, 43.8, 18.5, 16.8, 15.0}
};
float fAlpha[6]={0.01, 0.025, 0.05, 0.95, 0.975, 0.99};
bool Pearson(float fAlph, int iIntervals, float *fP, TMemo *mStat)
{
 mStat->Lines->Add("Оценка получившегося распределения по критерию Хи квадрат:");
 int s=iIntervals-3, i=0, iN=0;
 mStat->Lines->Add("Число степеней свободы - "+IntToStr(s));
 mStat->Lines->Add("Степень значимости альфа - "+FloatToStrF(fAlph, ffFixed, 3, 3));
 for (i=0; i<iIntervals; i++) iN=iN+fP[i];
 float fNaverage=(float)iN/iIntervals, fHi=0;
 mStat->Lines->Add("Средняя частота - "+FloatToStrF(fNaverage, ffFixed, 5, 5));
 bool bValid=false;
 for (i=0; i<iIntervals; i++)
 {
  fHi=fHi+powl((fP[i]-fNaverage),2)/fNaverage;
 }
 mStat->Lines->Add("Эмпирическое Хи квадрат - "+FloatToStrF(fHi, ffFixed, 5, 5));
 if (fAlph<=0.991&&fAlph>0.976) mStat->Lines->Add("Табличное Хи квадрат - "+FloatToStrF(fPearson[s-1][5], ffFixed, 5, 5));
 if (fAlph<=0.976&&fAlph>0.951) mStat->Lines->Add("Табличное Хи квадрат - "+FloatToStrF(fPearson[s-1][4], ffFixed, 5, 5));
 if (fAlph<=0.951&&fAlph>0.051) mStat->Lines->Add("Табличное Хи квадрат - "+FloatToStrF(fPearson[s-1][3], ffFixed, 5, 5));
 if (fAlph<=0.051&&fAlph>0.026) mStat->Lines->Add("Табличное Хи квадрат - "+FloatToStrF(fPearson[s-1][2], ffFixed, 5, 5));
 if (fAlph<=0.026&&fAlph>0.011) mStat->Lines->Add("Табличное Хи квадрат - "+FloatToStrF(fPearson[s-1][1], ffFixed, 5, 5));
 if (fAlph<=0.011&&fAlph>0) mStat->Lines->Add("Табличное Хи квадрат - "+FloatToStrF(fPearson[s-1][0], ffFixed, 5, 5));

 if (fAlph<=0.991&&fHi<fPearson[s-1][5]) bValid=true;
 if (fAlph<=0.976&&fHi<fPearson[s-1][4]) bValid=true;
 if (fAlph<=0.951&&fHi<fPearson[s-1][3]) bValid=true;
 if (fAlph<=0.051&&fHi<fPearson[s-1][2]) bValid=true;
 if (fAlph<=0.026&&fHi<fPearson[s-1][1]) bValid=true;
 if (fAlph<=0.011&&fHi<fPearson[s-1][0]) bValid=true;

 if (bValid==true) mStat->Lines->Add("Гипотеза о том, что распределение равномерно, верна.");
 else mStat->Lines->Add("Гипотеза о том, что распределение равномерно, НЕ верна.");
 return bValid;
}
//---------------------------------------------------------------------------
__fastcall TfMain::TfMain(TComponent* Owner)
        : TForm(Owner)
{
 int i=0, j=0;
 for (i=0; i<30; i++)
 {
  sgPearson->Cells[0][i+1]=i+1;
  for (j=0; j<6; j++)
  {
   sgPearson->Cells[j+1][i+1]=FloatToStrF(fPearson[i][j], ffFixed, 5, 5);
  }
 }
 for (i=0; i<6; i++)
 {
  sgPearson->Cells[i+1][0]=FloatToStrF(fAlpha[i], ffFixed, 3, 3);
  cbAlpha->Items->Add(FloatToStrF(fAlpha[i], ffFixed, 3, 3));
 }
 cbAlpha->Text=FloatToStrF(fAlpha[0], ffFixed, 3, 3);
}
//---------------------------------------------------------------------------
void __fastcall TfMain::bGenerateClick(TObject *Sender)
{
 try
 {
 randomize();
 Series1->Clear();
 Series2->Clear();
 Series3->Clear();
 Series4->Clear();
 mStat->Lines->Clear();
 int i=0, j=0;
 float h=0, x1=0, x2=0, fMO=0, fD=0;
 if (fX) delete [] fX;
 if (fP) delete [] fP;
 fX=new float[eHowmodels->Text.ToIntDef(200)];
 fP=new float[eIntervals->Text.ToIntDef(10)];
 h=(eB->Text.ToDouble()-eA->Text.ToDouble())/(eIntervals->Text.ToIntDef(10));
 x1=eA->Text.ToDouble();
 x2=x1+h;
 for (i=0; i<eHowmodels->Text.ToIntDef(200); i++)
 {
  fX[i]=eA->Text.ToDouble()+(eB->Text.ToDouble()-eA->Text.ToDouble())*random(powl(10, eAccuracy->Text.ToIntDef(2)))/powl(10, eAccuracy->Text.ToIntDef(2));
 }
 for (i=0; i<eIntervals->Text.ToIntDef(10); i++)
 {
  fP[i]=0;
 }
 for (i=0; i<eIntervals->Text.ToIntDef(10); i++)
 {
  for (j=0; j<eHowmodels->Text.ToIntDef(200); j++)
  {
   if ((fX[j]>=x1)&&(fX[j]<x2)) fP[i]=fP[i]+1;
  }
  x1=x1+h;
  x2=x2+h;
 }
 x1=eA->Text.ToDouble();
 x2=x1+h;
 float fSumm=0;
 for (i=0; i<eIntervals->Text.ToIntDef(10); i++)
 {
  fSumm=fSumm+fP[i];
 }
 for (i=0; i<eIntervals->Text.ToIntDef(10); i++)
 {
  Series2->AddXY(x1, fP[i]/(fSumm*h));
  Series2->AddXY(x2, fP[i]/(fSumm*h));
  fMO=fMO+(x2-h/2)*fP[i];
  x1=x1+h;
  x2=x2+h;
 }
 fMO=fMO/eHowmodels->Text.ToIntDef(200);
 for (float fx=eA->Text.ToDouble()-1; fx<eB->Text.ToDouble()+1; fx=fx+0.01)
 {
  Series1->AddXY(fx, f(fx, eA->Text.ToDouble(), eB->Text.ToDouble()));
 }
 x1=eA->Text.ToDouble();
 x2=x1+h;
 float fCurrent=0;
 for (i=0; i<eIntervals->Text.ToIntDef(10); i++)
 {
  Series4->AddXY(x1, fCurrent+fP[i]/fSumm);
  Series4->AddXY(x2, fCurrent+fP[i]/fSumm);
  fCurrent=fCurrent+fP[i]/fSumm;
  x1=x1+h;
  x2=x2+h;
 }
 for (float fx=eA->Text.ToDouble()-1; fx<eB->Text.ToDouble()+1; fx=fx+0.01)
 {
  Series3->AddXY(fx, F(fx, eA->Text.ToDouble(), eB->Text.ToDouble()));
 }
 Pearson(cbAlpha->Text.ToDouble(), eIntervals->Text.ToIntDef(10), fP, mStat);
 mStat->Lines->Add("Математическое ожидание - "+FloatToStrF(fMO, ffFixed, 3, 3));
 x1=eA->Text.ToDouble();
 x2=x1+h;
 for (i=0; i<eIntervals->Text.ToIntDef(10); i++)
 {
  fD=fD+powl(((x2-h/2)-fMO), 2);
  x1=x1+h;
  x2=x2+h;
 }
 fD=fD/(eIntervals->Text.ToIntDef(10)-1);
 mStat->Lines->Add("Дисперсия - "+FloatToStrF(fD, ffFixed, 3, 3));
 }
 catch(...)
 {
  ShowMessage("Проверьте, чтобы все поля параметров были заполнены!\nНевозможно полностью выполнить операции!");
 }
}
//---------------------------------------------------------------------------
