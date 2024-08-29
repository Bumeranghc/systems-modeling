//---------------------------------------------------------------------------

#ifndef mainformH
#define mainformH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Grids.hpp>
//---------------------------------------------------------------------------
class TfMain : public TForm
{
__published:	// IDE-managed Components
        TLabel *lV;
        TEdit *eV;
        TLabel *lA;
        TEdit *eA;
        TLabel *lB;
        TEdit *eB;
        TLabel *lZ;
        TEdit *eZ;
        TLabel *lPeriod;
        TEdit *ePeriod;
        TButton *bProcess;
        TLabel *lHowmanymodels;
        TEdit *eHowmanymodels;
        TPanel *pModel;
        TLabel *lAverage;
        TCheckBox *cbDay;
        TCheckBox *cbMonth;
        TCheckBox *cbYear;
        TUpDown *udHowmanymodels;
        void __fastcall bProcessClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TfMain(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TfMain *fMain;
//---------------------------------------------------------------------------
#endif
