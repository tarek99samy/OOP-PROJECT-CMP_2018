#include "ChangeFillColorAction.h"
#include"..\GUI\UI_Info.h"

void ChangeFillColorAction::changaVariatingparameter(bool x) {
	UI.VariatatingFillcolor = x;
}

ChangeFillColorAction::ChangeFillColorAction(ApplicationManager * pch) :Action(pch) {}

void ChangeFillColorAction::ReadActionParameters() {
	pOut = pManager->GetOutput();
	pIn = pManager->GetInput();
	pOut->PrintMessage("Choose any color");
}

void ChangeFillColorAction::Execute() {
	ReadActionParameters();
	ActionType ActType_;
	ActType_ = pIn->GetUserAction();
	CFigure*x = pManager->getSelectedFig();
	if (x == NULL) {
		return;
	}
	else {
		if (ActType_ == WHITE_CLR) {
			changaVariatingparameter(true);
			x->ChngFillClr(WHITE);
			UI.FillColor = WHITE;
		}
		if (ActType_ == BLACK_CLR) {
			changaVariatingparameter(true);
			x->ChngFillClr(BLACK);
			UI.FillColor = BLACK;
		}
		if (ActType_ == GREEN_CLR) {
			changaVariatingparameter(true);
			x->ChngFillClr(GREEN);
			UI.FillColor = GREEN;
		}
		if (ActType_ == RED_CLR) {
			x->ChngFillClr(RED);
			changaVariatingparameter(true);
			UI.FillColor = RED;
		}
		if (ActType_ == BLUE_CLR) {
			changaVariatingparameter(true);
			x->ChngFillClr(BLUE);
			UI.FillColor = BLUE;
		}
	}
}
ChangeFillColorAction::~ChangeFillColorAction() {}
