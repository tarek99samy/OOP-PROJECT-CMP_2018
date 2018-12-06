#pragma once

#include"Actions\Action.h"


class AddEllipseAction:public Action
{
private:
	Point center;
	GfxInfo EllipseGfxInfo;
public:
	AddEllipseAction(ApplicationManager* pE);

	virtual void ReadActionParameters();
	virtual void Execute();

	~AddEllipseAction();
};

