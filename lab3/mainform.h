//---------------------------------------------------------------------------

#ifndef mainformH
#define mainformH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Grids.hpp>
#include <Vcl.StdCtrls.hpp>
#include <VCLTee.Chart.hpp>
#include <VCLTee.Series.hpp>
#include <VclTee.TeeGDIPlus.hpp>
#include <VCLTee.TeEngine.hpp>
#include <VCLTee.TeeProcs.hpp>
//---------------------------------------------------------------------------
class TfMain : public TForm
{
__published:	// IDE-managed Components
        TPageControl *pcMain;
        TTabSheet *TabSheet1;
        TTabSheet *TabSheet2;
        TLabel *lA;
        TEdit *eA;
        TLabel *lB;
        TEdit *eB;
        TLabel *lHowmodels;
        TEdit *eHowmodels;
        TChart *tcf;
        TButton *bGenerate;
        TLabel *llAccuracy;
        TEdit *eAccuracy;
        TLabel *lIntervals;
        TEdit *eIntervals;
        TLineSeries *Series1;
        TAreaSeries *Series2;
        TTabSheet *TabSheet3;
        TChart *tcff;
        TLineSeries *Series3;
        TAreaSeries *Series4;
        TUpDown *udIntervals;
        TStringGrid *sgPearson;
        TUpDown *udAccuracy;
        TLabel *lHi;
        TLabel *lAlpha;
        TComboBox *cbAlpha;
        TTabSheet *TabSheet4;
        TMemo *mStat;
        void __fastcall bGenerateClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TfMain(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TfMain *fMain;
//---------------------------------------------------------------------------
#endif
