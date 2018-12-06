#pragma once
#include"Figures\CFigure.h"


class CEllipse:public CFigure
{
private:
	int iD;
	Point center;
public:
	CEllipse(Point, GfxInfo FigureGfxInfo);
	virtual void Draw(Output* pOut) const;
	bool Isinside(int x, int y);
	bool isSelected();
	~CEllipse();
};

