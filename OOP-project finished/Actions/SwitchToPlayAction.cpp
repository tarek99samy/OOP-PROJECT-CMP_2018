#include "SwitchToPlayAction.h"

#include "..\ApplicationManager.h"

#include "..\GUI\Output.h"
#include "..\GUI\Input.h"

SwitchToPlayAction::SwitchToPlayAction(ApplicationManager * pto) :Action(pto) {}

void SwitchToPlayAction::ReadActionParameters() {}

void SwitchToPlayAction::Execute() {
	Output*pOut = pManager->GetOutput();
	pOut->CreatePlayToolBar();
}

SwitchToPlayAction::~SwitchToPlayAction(void) {}
