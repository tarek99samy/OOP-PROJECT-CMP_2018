#include "ChnageDrawColorAction.h"
#include"..\GUI\UI_Info.h"


ChangeDrawColorAction::ChangeDrawColorAction(ApplicationManager * pch) :Action(pch) {}

void ChangeDrawColorAction::ReadActionParameters() {

	pOut = pManager->GetOutput();
	pIn = pManager->GetInput();
	pOut->PrintMessage("Choose any color");
}

void ChangeDrawColorAction::Execute() {
	ReadActionParameters();
	ActionType ActType_;
	CFigure*x = pManager->getSelectedFig();
	ActType_ = pIn->GetUserAction();
	if (x == NULL) {
		return;
	}
	else {
		if (ActType_ == WHITE_CLR) {
			x->ChngDrawClr(WHITE);
			UI.DrawColor = WHITE;
		}
		if (ActType_ == BLACK_CLR) {
			x->ChngDrawClr(BLACK);
			UI.DrawColor = BLACK;
		}
		if (ActType_ == GREEN_CLR) {
			x->ChngDrawClr(GREEN);
			UI.DrawColor = GREEN;
		}
		if (ActType_ == RED_CLR) {
			x->ChngDrawClr(RED);
			UI.DrawColor = RED;
		}
		if (ActType_ == BLUE_CLR) {
			x->ChngDrawClr(BLUE);
			UI.DrawColor = BLUE;
		}
	}
}

ChangeDrawColorAction::~ChangeDrawColorAction() {}
