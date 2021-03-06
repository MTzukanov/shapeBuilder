// ---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Window.h"
#include "Model_with_Matrices.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

using namespace std;

TForm1 *Form1;

// ---------------------------------------------------------------------------

__fastcall TForm1::TForm1(TComponent* Owner) : TForm(Owner) {
	shape = new Model_with_Matrices;
}

// ---------------------------------------------------------------------------

__fastcall TForm1::~TForm1() {
	delete shape;
}

// ---------------------------------------------------------------------------
void __fastcall TForm1::FormClick(TObject *Sender) {
	TPoint P;
	::GetCursorPos(&P);
	P = ScreenToClient(P);

	shape->addPoint(P.X -this->Width / 2, P.Y -this->Height / 2);

	Form1->Invalidate();
}

// ---------------------------------------------------------------------------
void __fastcall TForm1::FormPaint(TObject *Sender) {
	const vector<pair<int, int> >&v = shape->getTransformedPoints();

	if (v.size()) {
		Canvas->Brush->Color = clBlue;
		this->Canvas->FloodFill(1, 1, clRed, fsBorder);

		this->Canvas->MoveTo(translateX(v[0].first), translateY(v[0].second));

		for (unsigned i = 1; i < v.size(); i++) {
			this->Canvas->LineTo(translateX(v[i].first),
				translateY(v[i].second));
		}

		this->Canvas->LineTo(translateX(v[0].first), translateY(v[0].second));

		Canvas->Brush->Color = clWindow;
		this->Canvas->FloodFill(1, 1, clBlack, fsBorder);
	}
}

const WORD UP = 38, DOWN = 40, LEFT = 37, RIGHT = 39;
const int TRANSLATE_STEP = 10;
const float SCALE_STEP = 0.1;
const float ROTATE_STEP_RAD = 0.1;

static void adjustTranslate(AbstractModel &shape, WORD Key) {
	switch (Key) {
	case UP:
		shape.adjustTranslate(axis::Y, -TRANSLATE_STEP);
		break;
	case DOWN:
		shape.adjustTranslate(axis::Y, TRANSLATE_STEP);
		break;
	case LEFT:
		shape.adjustTranslate(axis::X, -TRANSLATE_STEP);
		break;
	case RIGHT:
		shape.adjustTranslate(axis::X, TRANSLATE_STEP);
		break;
	}
}

static void adjustScale(AbstractModel &shape, WORD Key) {
	switch (Key) {
	case UP:
		shape.adjustScale(axis::Y, SCALE_STEP);
		break;
	case DOWN:
		shape.adjustScale(axis::Y, -SCALE_STEP);
		break;
	case LEFT:
		shape.adjustScale(axis::X, -SCALE_STEP);
		break;
	case RIGHT:
		shape.adjustScale(axis::X, SCALE_STEP);
		break;
	}
}

static void adjustRotation(AbstractModel &shape, WORD Key) {
	switch (Key) {
	case UP:
		break;
	case DOWN:
		break;
	case LEFT:
		shape.adjustRotation(-ROTATE_STEP_RAD);
		break;
	case RIGHT:
		shape.adjustRotation(ROTATE_STEP_RAD);
		break;
	}
}

// ---------------------------------------------------------------------------
void __fastcall TForm1::FormKeyDown(TObject *Sender, WORD &Key,
	TShiftState Shift) {

	if (Shift.Contains(ssShift)) {
		adjustScale(*shape, Key);
	}
	else if (Shift.Contains(ssCtrl)) {
		adjustRotation(*shape, Key);
	}
	else {
		adjustTranslate(*shape, Key);
	}

	this->Invalidate();
}

// ---------------------------------------------------------------------------
void __fastcall TForm1::FormCreate(TObject *Sender) {
	this->DoubleBuffered = true;
}
// ---------------------------------------------------------------------------
void __fastcall TForm1::FormResize(TObject *Sender)
{
    this->Invalidate();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormDblClick(TObject *Sender)
{
	shape->reset();
	this->Invalidate();
}
//---------------------------------------------------------------------------

