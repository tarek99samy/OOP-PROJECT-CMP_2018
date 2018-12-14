#include "Action.h"
#include "..\Figures\CTriangle.h"
#include"..\Figures\CEllipse.h"
#include"..\Figures\CLine.h"
#include"..\Figures\CRhombus.h"
#include "..\Figures\CRectangle.h"


class CutFigAction: public Action
{

private:
	CFigure* SelectedFigure;
public:
	CutFigAction(ApplicationManager *pApp);
	~CutFigAction();
	//Reads rectangle parameters
	virtual void ReadActionParameters();
	
	//Add rectangle to the ApplicationManager
	virtual void Execute();


};