#pragma once

#include"Figures\CFigure.h"

class CTriangle:public CFigure
{
private:
	int iD;
	Point vertices[3];
public:
	CTriangle(Point, Point, Point, GfxInfo FigureGfxInfo);
	virtual void Draw(Output*pOut)const;
	virtual Point* getPoints();
	bool Isinside(int x, int y);
	~CTriangle();
};

