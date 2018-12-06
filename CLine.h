#pragma once

#include"Figures\CFigure.h"

class CLine: public CFigure
{
private:
	int iD;
	Point start;
	Point end;
public:
	CLine(Point,Point,GfxInfo FigureGfxInfo);
	virtual void Draw(Output* pOut) const;
	bool Isinside(int x, int y);
	bool isSelected();
	~CLine();
};

