#include "AddTriangleAction.h"
#include "..\Figures\CTriangle.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"


AddTriangleAction::AddTriangleAction(ApplicationManager * pT):Action(pT)
{}

void AddTriangleAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//Ask user to click on three points (new triangle points)
	pOut->PrintMessage("New Triangle: Click at first point");
	//Read first point and store in point P1
	pIn->GetPointClicked(P1.x, P1.y);

	pOut->PrintMessage("New Triangle: Click at second point");
	//Read second point and store in point P2
	pIn->GetPointClicked(P2.x, P2.y);

	pOut->PrintMessage("New Triangle: Click at third point");
	//Read first point and store in point P3
	pIn->GetPointClicked(P3.x, P3.y);

	TriangleGfxInfo.isFilled = false;	//default is not filled
										//get drawing, filling colors and pen width from the interface
	TriangleGfxInfo.DrawClr = pOut->getCrntDrawColor();
	TriangleGfxInfo.FillClr = pOut->getCrntFillColor();

	pOut->ClearStatusBar();
}

void AddTriangleAction::Execute()
{

	//This action needs to read some parameters first
	ReadActionParameters();

	//Create a Triangle with the parameters read from the user
	CTriangle *R = new CTriangle(P1, P2, P3, TriangleGfxInfo); 	//Create Object of class CTriangle

															//Add the triangle to the list of figures
	pManager->AddFigure(R); //Add the CTriangle object to the list of Figures -->> Triangle. is saved
}

AddTriangleAction::~AddTriangleAction(){}
