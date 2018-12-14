#ifndef CRECT_H
#define CRECT_H

#include "CFigure.h"

class CRectangle : public CFigure
{
private:
	int iD;
	Point Corner[2];	

public:
	CRectangle(Point , Point, GfxInfo FigureGfxInfo );
	virtual void Draw(Output* pOut) const;
	virtual Point* getPoints();
	bool Isinside(int x, int y);
	bool isSelected();
};

#endif