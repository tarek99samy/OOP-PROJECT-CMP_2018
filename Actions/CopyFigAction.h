#include "Action.h"
#include "..\Figures\CTriangle.h"
#include"..\Figures\CEllipse.h"
#include"..\Figures\CLine.h"
#include"..\Figures\CRhombus.h"
#include "..\Figures\CRectangle.h"


class CopyFigAction: public Action
{

private:
	CFigure* SelectedFigure;
	
public:
	CopyFigAction(ApplicationManager *pApp);
	~CopyFigAction();
	//Reads rectangle parameters
	virtual void ReadActionParameters();
	//Add rectangle to the ApplicationManager
	virtual void Execute();


};