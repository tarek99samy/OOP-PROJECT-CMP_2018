#pragma once

#include"Actions\Action.h"


class AddRhombusAction:public Action
{
private:
	Point center;
	GfxInfo RhombusGfxInfo;
public:
	AddRhombusAction(ApplicationManager* pR);

	virtual void ReadActionParameters();
	virtual void Execute();

	~AddRhombusAction();
};

