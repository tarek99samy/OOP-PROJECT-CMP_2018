#pragma once

#include"Action.h"

class SwitchToDrawAction :public Action {
public:
	SwitchToDrawAction(ApplicationManager* pto);
	void ReadActionParameters();
	void Execute();
	~SwitchToDrawAction();
};

