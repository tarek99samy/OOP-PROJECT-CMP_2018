#include "Action.h"
#include "..\CTriangle.h"
#include"..\CEllipse.h"
#include"..\CLine.h"
#include"..\CRhombus.h"
#include "..\Figures\CRectangle.h"


class CopyFigAction: public Action
{

private:
	CFigure* SelectedFigure;
public:
	CopyFigAction(ApplicationManager *pApp);

	//Reads rectangle parameters
	virtual void ReadActionParameters();
	
	//Add rectangle to the ApplicationManager
	virtual void Execute();


};