#include "PasteFigAction.h"
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"

PasteFigAction::PasteFigAction(ApplicationManager * pApp):Action(pApp)
{}

void PasteFigAction::ReadActionParameters() 
{	

	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("Click point to paste the figure");
	pIn->GetPointClicked(P.x, P.y);
	pOut->ClearStatusBar();



}

//Execute the action
void PasteFigAction::Execute() 
{
	//This action needs to read some parameters first
	
	ClipboardFigure = pManager->getClipboard();
	
	if(ClipboardFigure == NULL) pManager->GetOutput()->PrintMessage("Clipboard is Empty!");
	
	else{

	ReadActionParameters();
	Point center;
	CRectangle* PastedFigure0 = dynamic_cast<CRectangle*>(ClipboardFigure);
	CRhombus* PastedFigure1 = dynamic_cast<CRhombus*>(ClipboardFigure);
	CTriangle* PastedFigure2 = dynamic_cast<CTriangle*>(ClipboardFigure);
	CEllipse* PastedFigure3 = dynamic_cast<CEllipse*>(ClipboardFigure);
	CLine* PastedFigure4 = dynamic_cast<CLine*>(ClipboardFigure);
	GfxInfo gfx = ClipboardFigure->getGfxInfo();
	
	if(PastedFigure0){

		Point* p = PastedFigure0->getPoints();

		center.x = (p[0].x + p[1].x)/2;
		center.y = (p[0].y + p[1].y)/2;

		Point P1,P2;
		P1.x = P.x - center.x + p[0].x;
		P1.y = P.y - center.y + p[0].y;
		P2.x = P.x - center.x + p[1].x;
		P2.y = P.y - center.y + p[1].y;


		CRectangle *R=new CRectangle(P1, P2, gfx);
		pManager->AddFigure(R);

	}
	else if (PastedFigure1){
	
		CRhombus *R = new CRhombus(P, gfx);
		pManager->AddFigure(R);


	}else if(PastedFigure2){
		Point* p = PastedFigure2->getPoints();
		center.x = ( p[0].x + p[1].x + p[2].x )/3;
		center.y = ( p[0].y + p[1].y + p[2].y )/3;
		
		Point P1,P2,P3;
		P1.x = P.x - center.x + p[0].x;
		P1.y = P.y - center.y + p[0].y;
		P2.x = P.x - center.x + p[1].x;
		P2.y = P.y - center.y + p[1].y;
		P3.x = P.x - center.x + p[2].x;
		P3.y = P.y - center.y + p[2].y;

		CTriangle *R = new CTriangle(P1, P2,P3, gfx);
		pManager->AddFigure(R);

	}else if(PastedFigure3){

		CEllipse *R=new CEllipse(P,gfx);
		pManager->AddFigure(R);

	}else if(PastedFigure4){

		Point* p = PastedFigure4->getPoints();
		center.x = ( p[0].x + p[1].x )/2;
		center.y = ( p[0].y + p[1].y )/2;
		
		Point P1,P2;
		P1.x = P.x - center.x + p[0].x;
		P1.y = P.y - center.y + p[0].y;
		P2.x = P.x - center.x + p[1].x;
		P2.y = P.y - center.y + p[1].y;

		CLine *R=new CLine(P1,P2,gfx);
		pManager->AddFigure(R);
	}
}
}

