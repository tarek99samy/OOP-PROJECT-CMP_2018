#include "ApplicationManager.h"
#include "Actions\AddRectAction.h"
#include"Actions\AddLineAction.h"
#include"Actions\AddEllipseAction.h"
#include"Actions\AddTriangleAction.h"
#include"Actions\AddRhombusAction.h"
#include"Actions\select.h"
#include"Actions\CopyFigAction.h"
#include"Actions\PasteFigAction.h"
#include"Actions\CutFigAction.h"
//Constructor
ApplicationManager::ApplicationManager() : Clipboard(NULL),SelectedFig(NULL)
{
	//Create Input and output
	pOut = new Output;
	pIn = pOut->CreateInput();
	
	FigCount = 0;
	
	SelectedFig = NULL;
	//Create an array of figure pointers and set them to NULL		
	for(int i=0; i<MaxFigCount; i++)
		FigList[i] = NULL;	
}

//==================================================================================//
//								Actions Related Functions							//
//==================================================================================//
ActionType ApplicationManager::GetUserAction() const
{
	//Ask the input to get the action from the user.
	//EX : User clicks on “Rectangle” icon in the toolbar  
	return pIn->GetUserAction();
}

////////////////////////////////////////////////////////////////////////////////////
//Creates an action and executes it
void ApplicationManager::ExecuteAction(ActionType ActType) 
{
	Action* pAct = NULL;
	
	//According to Action Type, create the corresponding action object
	switch (ActType)
	{
		case DRAW_RECT:
			pAct = new AddRectAction(this); //Create Object of class AddRectAction 
			break;

		case DRAW_LINE:
			pAct = new AddLineAction(this); //Create Object of class AddLineAction 
			break;

		case DRAW_ELLIPSE:
			pAct = new AddEllipseAction(this);	//Create Object of class AddEllipseAction 
			break;
 
		case DRAW_RHOMBUS:
			pAct = new AddRhombusAction(this);	//Create Object of class AddRhombusAction 
			break;

		case DRAW_TRI:
			pAct = new AddTriangleAction(this);	//Create Object of class AddTriangleAction 
			break;

		case SELECT:
			pAct = new AddSelectAction(this);
			break;
		
		case DRAWING_AREA:
			break;

		case COPY : 
			pAct = new CopyFigAction(this);
			break;

		case PASTE : 
			pAct = new PasteFigAction(this);
			break;

		case CUT : 
			pAct = new CutFigAction(this);
			break;

	
	}
	
	//Execute the created action
	if(pAct != NULL)
	{
		pAct->Execute();//Execute
		delete pAct;	//Action is not needed any more ==> delete it
		pAct = NULL;
	}

}

void ApplicationManager::setSelectedFig(CFigure * x){
	SelectedFig = x;
}
CFigure * ApplicationManager::getSelectedFig() const
{
	return SelectedFig;
}

void ApplicationManager::setClipboard(CFigure * c){
	Clipboard = c;
}
CFigure * ApplicationManager::getClipboard() const
{
	return Clipboard;
}
//==================================================================================//
//						Figures Management Functions								//
//==================================================================================//

//Add a figure to the list of figures
void ApplicationManager::AddFigure(CFigure* pFig)
{
	if(FigCount < MaxFigCount )
		FigList[FigCount++] = pFig;	
}
////////////////////////////////////////////////////////////////////////////////////
CFigure *ApplicationManager::GetFigure(int x, int y) const
{
	//If a figure is found return a pointer to it.
	//if this point (x,y) does not belong to any figure return NULL
	for (int i = FigCount-1; i>=0 ; i--) {
		if (FigList[i]->Isinside(x,y)) {
			return FigList[i];
		}
	}
	return NULL;
	//Add your code here to search for a figure given a point x,y	
	//Remember that ApplicationManager only calls functions do NOT implement it.

}
//==================================================================================//
//							Interface Management Functions							//
//==================================================================================//

//Draw all figures on the user interface
void ApplicationManager::UpdateInterface() const
{	
	for(int i=0; i<FigCount; i++)
		FigList[i]->Draw(pOut);		//Call Draw function (virtual member fn)
		//For each Figure in the list, call Draw function. Each Figure calls the appropriate draw function from Output class.
		//EX : CRectangle ::Draw calls Output::DrawRect -->> Rect. is shown

}
////////////////////////////////////////////////////////////////////////////////////
//Return a pointer to the input
Input *ApplicationManager::GetInput() const
{	return pIn; }
//Return a pointer to the output
Output *ApplicationManager::GetOutput() const
{	return pOut; }

////////////////////////////////////////////////////////////////////////////////////
//Destructor
ApplicationManager::~ApplicationManager()
{
	for (int i = 0; i < FigCount; i++) {
		delete FigList[i];
	}
	delete pIn;
	delete pOut;
	
}