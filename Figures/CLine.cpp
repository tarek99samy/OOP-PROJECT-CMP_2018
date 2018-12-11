#include "CLine.h"

CLine::CLine(Point P1, Point P2, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	terminal[0] = P1;
	terminal[1] = P2;
}

void CLine::Draw(Output * pOut) const
{
	//Drawing a line on the drawing area...
	pOut->Drawline(terminal[0], terminal[1], FigGfxInfo, Selected);
}

bool CLine::Isinside(int x, int y)
{	
	//rememmber that x-axis increasing towards rightside and y-axis towards downside
	double d1 = (x - terminal[0].x)*(x - terminal[0].x);
	double d2 = (y - terminal[0].y)*(y - terminal[0].y);
	double dist_to_start = sqrt(d1 + d2);

	double d3 = (x - terminal[1].x)*(x - terminal[1].x);
	double d4 = (y - terminal[1].y)*(y - terminal[1].y);
	double dist_to_end = sqrt(d3 + d4);

	double D1 = (terminal[0].x - terminal[1].x)*(terminal[0].x - terminal[1].x);
	double D2 = (terminal[0].y - terminal[1].y)*(terminal[0].y - terminal[1].y);
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

Point* CLine::getPoints(){return terminal;}

bool CLine::isSelected(){
	if (Selected) {
		return true;
	}
	else {
		return false;
	}
}

CLine::~CLine(){}
