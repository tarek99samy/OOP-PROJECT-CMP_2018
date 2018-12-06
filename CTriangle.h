#pragma once

#include"Figures\CFigure.h"

class CTriangle:public CFigure
{
private:
	int iD;
	Point P1, P2, P3;
public:
	CTriangle(Point, Point, Point, GfxInfo FigureGfxInfo);
	virtual void Draw(Output*pOut)const;
	bool Isinside(int x, int y);
	~CTriangle();
};

