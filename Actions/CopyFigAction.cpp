#include "CopyFigAction.h"
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"

CopyFigAction::CopyFigAction(ApplicationManager * pApp):Action(pApp)
{}

void CopyFigAction::ReadActionParameters() 
{	
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	
	pOut->PrintMessage("Figure Copied !");

	GfxInfo gfx = (pManager->getSelectedFig()->getGfxInfo());
	Point* p = (pManager->getSelectedFig())->getPoints();
	
	if(dynamic_cast<CRectangle*>(pManager->getSelectedFig())) SelectedFigure = new CRectangle(p[0],p[1],gfx);
	else if(dynamic_cast<CRhombus*>(pManager->getSelectedFig())) SelectedFigure = new CRhombus(p[0],gfx);
	else if(dynamic_cast<CTriangle*>(pManager->getSelectedFig())) SelectedFigure = new CTriangle(p[0],p[1],p[2],gfx);
	else if(dynamic_cast<CEllipse*>(pManager->getSelectedFig())) SelectedFigure = new CEllipse(p[0],gfx);
	else if(dynamic_cast<CLine*>(pManager->getSelectedFig())) SelectedFigure = new CLine(p[0],p[1],gfx);

}

//Execute the action
void CopyFigAction::Execute() 
{


	if(pManager->getSelectedFig() == NULL)
		
		pManager->GetOutput()->PrintMessage("You Should select figure first");

	else{
	//This action needs to read some parameters first
	ReadActionParameters();
	pManager->setClipboard(SelectedFigure);
	pManager->getSelectedFig()->SetSelected(false);

}
}


CopyFigAction::~CopyFigAction(){
	if(SelectedFigure != NULL) delete SelectedFigure;
}