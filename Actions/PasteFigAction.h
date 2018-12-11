#include "Action.h"
#include "..\Figures\CRectangle.h"
#include "..\Figures\CTriangle.h"
#include"..\Figures\CEllipse.h"
#include"..\Figures\CLine.h"
#include"..\Figures\CRhombus.h"
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