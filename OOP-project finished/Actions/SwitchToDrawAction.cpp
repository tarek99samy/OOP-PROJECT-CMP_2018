#include "SwitchToDrawAction.h"

#include"..\ApplicationManager.h"



SwitchToDrawAction::SwitchToDrawAction(ApplicationManager * pto) :Action(pto) {}

void SwitchToDrawAction::ReadActionParameters() {}

void SwitchToDrawAction::Execute() {
	Output*pOut = pManager->GetOutput();
	pOut->CreateDrawToolBar();
}

SwitchToDrawAction::~SwitchToDrawAction() {}
