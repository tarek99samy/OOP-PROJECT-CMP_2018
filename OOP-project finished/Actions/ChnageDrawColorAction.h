#pragma once

#include"Action.h"

#include "..\ApplicationManager.h"
#include "..\GUI\Input.h"
#include "..\GUI\Output.h"
#include"..\Figures\CFigure.h"

class ChangeDrawColorAction :public Action {
private:
	Output* pOut;
	Input* pIn;
public:
	ChangeDrawColorAction(ApplicationManager* pch);
	void ReadActionParameters();
	void Execute();
	~ChangeDrawColorAction();
};

