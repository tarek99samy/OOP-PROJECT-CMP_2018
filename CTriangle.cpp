#include "CTriangle.h"


CTriangle::CTriangle(Point p1, Point p2, Point p3, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	P1 = p1;
	P2 = p2;
	P3 = p3;
}

void CTriangle::Draw(Output * pOut) const
{
	pOut->DrawTriangle(P1, P2, P3, FigGfxInfo, Selected);
}

bool CTriangle::Isinside(int x, int y){
	double A1 = (0.5)*(x*(P2.y - P3.y) + y*(P3.x - P2.x) + (P2.x * P3.y - P2.y * P3.x));
	double A2 = (0.5)*(x*(P1.y - P2.y) + y*(P2.x - P1.x) + (P1.x * P2.y - P1.y * P2.x));
	double A3 = (0.5)*(x*(P1.y - P3.y) + y*(P3.x - P1.x) + (P1.x * P3.y - P3.x * P1.y));

	double Triangle_Area = (0.5)*(P1.x*(P2.y - P3.y) + P1.y*(P3.x - P2.x) + (P2.x * P3.y - P2.y * P3.x));

	double Total_Area = abs(A1) + abs(A2) + abs(A3);
	double Total_Area_after_error1 = Total_Area + 10;
	double Total_Area_after_error2 = Total_Area - 10;
	
	if (Triangle_Area <= Total_Area_after_error1 && Triangle_Area >= Total_Area_after_error2) {
		return true;
	}
	else {
		return false;
	}
}

CTriangle::~CTriangle(){}
