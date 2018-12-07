#include "Action.h"
#include "..\Figures\CRectangle.h"
#include "..\CTriangle.h"
#include"..\CEllipse.h"
#include"..\CLine.h"
#include"..\CRhombus.h"
class PasteFigAction: public Action
{

private:
	Point P;
	CFigure* ClipboardFigure;
	CFigure* PastedFigure;
public:
	PasteFigAction(ApplicationManager *pApp);

	virtual void ReadActionParameters();
	
	virtual void Execute() ;


};