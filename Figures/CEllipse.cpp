#include "CEllipse.h"



CEllipse::CEllipse(Point P1, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo){
	center[0] = P1;
}

void CEllipse::Draw(Output * pOut) const
{
	pOut->DrawEllipse(center[0], FigGfxInfo, Selected);
}

bool CEllipse::Isinside(int x, int y) {
	//Ellipse equation : x^2/a^2 + y^2/b^2 = 1
double result = (((x - center[0].x)*(x - center[0].x)) / (10000.0)) + (((y - center[0].y)*(y - center[0].y)) / (1600.0));
	if (result <= 1) {		return true;	}
	else {		return false;	}
}

Point* CEllipse::getPoints(){return center;}


bool CEllipse::isSelected(){
	if (Selected) {
		return true;
	}
	else {
		return false;
	}
}

CEllipse::~CEllipse(){}
