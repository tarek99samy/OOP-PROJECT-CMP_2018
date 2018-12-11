#pragma once
#include "CFigure.h"


class CEllipse:public CFigure
{
private:
	int iD;
	Point center[1];
public:
	CEllipse(Point, GfxInfo FigureGfxInfo);
	virtual void Draw(Output* pOut) const;
	bool Isinside(int x, int y);
	virtual Point* getPoints();
	bool isSelected();
	~CEllipse();
};

