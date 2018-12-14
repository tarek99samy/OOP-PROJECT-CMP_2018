#include "CTriangle.h"


CTriangle::CTriangle(Point p1, Point p2, Point p3, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	vertices[0] = p1;
	vertices[1] = p2;
	vertices[2] = p3;
}

void CTriangle::Draw(Output * pOut) const
{
	pOut->DrawTriangle(vertices[0], vertices[1], vertices[2], FigGfxInfo, Selected);
}

bool CTriangle::Isinside(int x, int y) {
	double A1 = abs((0.5)*(x*(vertices[1].y - vertices[2].y) + y*(vertices[2].x - vertices[1].x) + (vertices[1].x * vertices[2].y - vertices[1].y * vertices[2].x)));
	double A2 = abs((0.5)*(x*(vertices[0].y - vertices[1].y) + y*(vertices[1].x - vertices[0].x) + (vertices[0].x * vertices[1].y - vertices[0].y * vertices[1].x)));
	double A3 = abs((0.5)*(x*(vertices[0].y - vertices[2].y) + y*(vertices[2].x - vertices[0].x) + (vertices[0].x * vertices[2].y - vertices[2].x * vertices[0].y)));

	double Triangle_Area = abs((0.5)*(vertices[0].x*(vertices[1].y - vertices[2].y) + vertices[0].y*(vertices[2].x - vertices[1].x) + (vertices[1].x * vertices[2].y - vertices[1].y * vertices[2].x)));

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
void CTriangle::ChngFillClrState(bool c) {
	FigGfxInfo.isFilled = 1;
}

Point* CTriangle:: getPoints() {
	return vertices;
}

CTriangle::~CTriangle(){}
