//---------------------------------------------------------------------------

#ifndef mainformH
#define mainformH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.Grids.hpp>
#include <Vcl.StdCtrls.hpp>
//---------------------------------------------------------------------------
class TfMain : public TForm
{
__published:	// IDE-managed Components
        TLabel *lCirclex;
        TEdit *eCirclex;
        TLabel *lCircley;
        TEdit *eCircley;
        TLabel *lRadius;
        TEdit *eRadius;
        TButton *bCalculate;
        TPageControl *pcMain;
        TTabSheet *TabSheet1;
        TTabSheet *TabSheet2;
        TLabel *lStoppoints;
        TEdit *eStoppoints;
        TUpDown *udStoppoints;
        TLabel *lMaxpoints;
        TEdit *eMaxpoints;
        TLabel *lCurrentpoints;
        TStringGrid *sgCurrentpoints;
        TLabel *lCount;
        TEdit *eCount;
        TUpDown *udCount;
        TStringGrid *sgResult;
        TLabel *lPrecision;
        TEdit *ePrecision;
        TUpDown *udPrecision;
        TLabel *lReal;
        void __fastcall bCalculateClick(TObject *Sender);
        void __fastcall udStoppointsClick(TObject *Sender,
          TUDBtnType Button);
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall udCountClick(TObject *Sender, TUDBtnType Button);
        void __fastcall sgCurrentpointsExit(TObject *Sender);
        void __fastcall eMaxpointsChange(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TfMain(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TfMain *fMain;
//---------------------------------------------------------------------------
#endif
