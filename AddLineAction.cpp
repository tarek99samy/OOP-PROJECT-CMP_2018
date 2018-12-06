#include "AddLineAction.h"
#include "ApplicationManager.h"

#include"CLine.h"

#include "GUI\Input.h"
#include "GUI\Output.h"


AddLineAction::AddLineAction(ApplicationManager*pL) :Action(pL)
{}

void AddLineAction::ReadActionParameters(){
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//Ask user to click on two points (new line points)
	pOut->PrintMessage("New Line: Click at first point");

	//Read 1st poinr and store in point P1
	pIn->GetPointClicked(P1.x, P1.y);

	pOut->PrintMessage("New Line: Click at second point");

	//Read 2nd point and store in point P2
	pIn->GetPointClicked(P2.x, P2.y);

	lineGfxInfo.isFilled = false;	//default is not filled
									//get drawing, filling colors and pen width from the interface
	lineGfxInfo.DrawClr = pOut->getCrntDrawColor();
	lineGfxInfo.FillClr = pOut->getCrntFillColor();

	pOut->ClearStatusBar();
}

void AddLineAction::Execute(){
	//This action needs to read some parameters first
	ReadActionParameters();

	//Create a lint with the parameters read from the user
	CLine *R = new CLine(P1,P2, lineGfxInfo); 	//Create Object of class CRectangle

															//Add the line to the list of figures
	pManager->AddFigure(R); //Add the CLine object to the list of Figures -->> Line. is saved
}

AddLineAction::~AddLineAction(){}
