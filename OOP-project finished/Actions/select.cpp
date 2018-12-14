#include "select.h"
#include"..\ApplicationManager.h"
#include"..\Figures\CFigure.h"
#include"..\GUI\Output.h"
#include"..\GUI\Input.h"


AddSelectAction::AddSelectAction(ApplicationManager * ps):Action(ps){}

void AddSelectAction::ReadActionParameters(){
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("please select any figure");
	pIn->GetPointClicked(p.x, p.y);

	pOut->ClearStatusBar();
}

void AddSelectAction::Execute(){
	ReadActionParameters();
	CFigure* selected = pManager->GetFigure(p.x, p.y);
	if (selected != NULL) {
		if (pManager->getSelectedFig() == NULL) {
			selected->SetSelected(true);
			pManager->setSelectedFig(selected);
		}
		else {
			if (pManager->getSelectedFig() == selected) {
				selected->SetSelected(false);
				pManager->setSelectedFig(NULL);
			}
			else {
				pManager->getSelectedFig()->SetSelected(false);
				selected->SetSelected(true);
				pManager->setSelectedFig(selected);
			}
		}
	}
	else {
		if (pManager->getSelectedFig() != NULL) {
			pManager->getSelectedFig()->SetSelected(false);
		}
	}
}

AddSelectAction::~AddSelectAction(){}
