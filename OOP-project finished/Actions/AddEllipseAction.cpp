#include "AddEllipseAction.h"
#include "..\ApplicationManager.h"

#include "..\Figures\CEllipse.h"

#include "..\GUI\Input.h"
#include "..\GUI\Output.h"



AddEllipseAction::AddEllipseAction(ApplicationManager * pE):Action(pE)
{}

void AddEllipseAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//Ask user to click on one points (new Ellipse point)
	pOut->PrintMessage("New Ellipse: Click at center point");

	//Read center poinr and store in point center
	pIn->GetPointClicked(center.x,center.y);

	EllipseGfxInfo.isFilled = UI.VariatatingFillcolor;	//default is not filled
									//get drawing, filling colors and pen width from the interface
	EllipseGfxInfo.DrawClr = pOut->getCrntDrawColor();
	EllipseGfxInfo.FillClr = pOut->getCrntFillColor();

	pOut->ClearStatusBar();
}

void AddEllipseAction::Execute()
{
	//This action needs to read some parameters first
	ReadActionParameters();

	//Create a Ellipse with the parameters read from the user
	CEllipse *R = new CEllipse(center, EllipseGfxInfo); 	//Create Object of class CEllipse

												//Add the Ellipse to the list of figures
	pManager->AddFigure(R); //Add the CEllipse object to the list of Figures -->> Ellipse. is saved
}

AddEllipseAction::~AddEllipseAction(){}
