#pragma once

#include"Actions\Action.h"

class AddLineAction:public Action
{
private:
	Point P1, P2;
	GfxInfo lineGfxInfo;
public:
	AddLineAction(ApplicationManager *pL);
	virtual void ReadActionParameters();
	virtual void Execute();

	~AddLineAction();
};


