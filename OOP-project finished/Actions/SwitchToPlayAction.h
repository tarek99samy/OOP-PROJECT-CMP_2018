#pragma once
#include"Action.h"

#include"..\ApplicationManager.h"
#include"..\GUI\Output.h"
#include"..\GUI\Input.h"

class SwitchToPlayAction :public Action {
public:
	SwitchToPlayAction(ApplicationManager*pto);
	void ReadActionParameters();
	void Execute();
	~SwitchToPlayAction();
};

