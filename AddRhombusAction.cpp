#include "AddRhombusAction.h"
#include "ApplicationManager.h"

#include"CRhombus.h"

#include "GUI\Input.h"
#include "GUI\Output.h"


AddRhombusAction::AddRhombusAction(ApplicationManager * pR):Action(pR)
{}

void AddRhombusAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//Ask user to click on one points (new Rhombus point)
	pOut->PrintMessage("New Rhombus: Click at center point");

	//Read center poinr and store in point center
	pIn->GetPointClicked(center.x, center.y);

	RhombusGfxInfo.isFilled = false;	//default is not filled
										//get drawing, filling colors and pen width from the interface
	RhombusGfxInfo.DrawClr = pOut->getCrntDrawColor();
	RhombusGfxInfo.FillClr = pOut->getCrntFillColor();

	pOut->ClearStatusBar();

}

void AddRhombusAction::Execute()
{
	//This action needs to read some parameters first
	ReadActionParameters();

	//Create a Rhombus with the parameters read from the user
	CRhombus *R = new CRhombus(center, RhombusGfxInfo); 	//Create Object of class CRhombus

															//Add the Rhombus to the list of figures
	pManager->AddFigure(R); //Add the CRhombus object to the list of Figures -->> Rhombus. is saved
}

AddRhombusAction::~AddRhombusAction(){}
