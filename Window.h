//---------------------------------------------------------------------------

#ifndef WindowH
#define WindowH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
//---------------------------------------------------------------------------
#include "AbstractModel.h"
using namespace model;

class TForm1 : public TForm
{
__published:	// IDE-managed Components
	void __fastcall FormClick(TObject *Sender);
	void __fastcall FormPaint(TObject *Sender);
	void __fastcall FormKeyDown(TObject *Sender, WORD &Key, TShiftState Shift);
	void __fastcall FormCreate(TObject *Sender);
private:	// User declarations
	AbstractModel *shape;

	// translates coorditates to the middle of the window
	int translateX(int x) { return x + this->Width / 2; };
	int translateY(int y) { return y + this->Height / 2; };
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
    __fastcall ~TForm1();
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
