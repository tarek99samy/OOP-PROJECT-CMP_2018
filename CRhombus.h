#pragma once

#include"Figures\CFigure.h"


class CRhombus:public CFigure
{
private:
	int iD;
	Point center;
public:
	CRhombus(Point, GfxInfo FigureGfxInfo);
	virtual void Draw(Output* pOut) const;
	bool Isinside(int x, int y);
	bool isSelected();
	~CRhombus();
};

