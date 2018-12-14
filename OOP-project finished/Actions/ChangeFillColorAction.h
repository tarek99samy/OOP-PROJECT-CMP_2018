#pragma once

#include"Action.h"

#include "..\ApplicationManager.h"
#include "..\GUI\Input.h"
#include "..\GUI\Output.h"


class ChangeFillColorAction :public Action {
private:
	Output* pOut;
	Input* pIn;
public:
	void changaVariatingparameter(bool x);
	ChangeFillColorAction(ApplicationManager* pch);
	void ReadActionParameters();
	void Execute();
	~ChangeFillColorAction();

};

