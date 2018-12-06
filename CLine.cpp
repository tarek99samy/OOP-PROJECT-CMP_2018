#include "CLine.h"

CLine::CLine(Point P1, Point P2, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	start = P1;
	end = P2;
}

void CLine::Draw(Output * pOut) const
{
	//Drawing a line on the drawing area...
	pOut->Drawline(start, end, FigGfxInfo, Selected);
}

bool CLine::Isinside(int x, int y)
{	
	//rememmber that x-axis increasing towards rightside and y-axis towards downside
	double d1 = (x - start.x)*(x - start.x);
	double d2 = (y - start.y)*(y - start.y);
	double dist_to_start = sqrt(d1 + d2);

	double d3 = (x - end.x)*(x - end.x);
	double d4 = (y - end.y)*(y - end.y);
	double dist_to_end = sqrt(d3 + d4);

	double D1 = (start.x - end.x)*(start.x - end.x);
	double D2 = (start.y - end.y)*(start.y - end.y);
	double dist_form_two_ends = sqrt(D1 + D2);

	double dist_after__error1 = dist_to_start + dist_to_end + 10;
	double dist_after__error2 = dist_to_start + dist_to_end - 10;

	if (dist_form_two_ends <= dist_after__error1 && dist_form_two_ends >= dist_after__error2) {
		return true;
	}
	else {
		return false;
	}
}

bool CLine::isSelected(){
	if (Selected) {
		return true;
	}
	else {
		return false;
	}
}

CLine::~CLine(){}
