#include "CRhombus.h"



CRhombus::CRhombus(Point P1, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	center[0] = P1;
}

void CRhombus::Draw(Output * pOut) const
{
	pOut->DrawRhombus(center[0], FigGfxInfo, Selected);
}

bool CRhombus::Isinside(int x, int y){
	// Rhombus function is : (x-x1)/a + (y-y1)/b = 1
	double result = (abs(center[0].x - x) / (120.0)) + (abs(center[0].y - y) / (180.0));
	if (result <= 0.5) {
		return true;
	}
	else {
		return false;
	}
}
Point* CRhombus::getPoints(){return center;}
bool CRhombus::isSelected()
{
	if (Selected) {
		return true;
	}
	else {
		return false;
	}
}

CRhombus::~CRhombus(){}
