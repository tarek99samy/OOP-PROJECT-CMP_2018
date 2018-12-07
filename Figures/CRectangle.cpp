#include "CRectangle.h"

CRectangle::CRectangle(Point P1, Point P2, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	Corner[0] = P1;
	Corner[1] = P2;
}
	

void CRectangle::Draw(Output* pOut) const
{
	//Call Output::DrawRect to draw a rectangle on the screen	
	pOut->DrawRect(Corner[0], Corner[1], FigGfxInfo, Selected);
}

bool CRectangle::Isinside(int x, int y){
	if (Corner[0].x < Corner[1].x) {	// "Corner[0]" is at left
		if ((x >= Corner[0].x && x <= Corner[1].x) && ((y >= Corner[0].y && y <= Corner[1].y) || (y <= Corner[0].y && y >= Corner[1].y))) {
			return true;
		}
		else {
			return false;
		}
	}

	else if (Corner[0].x > Corner[1].x) {	// "Corner[1]" is at left
		if ((x >= Corner[1].x && x <= Corner[0].x) && ((y >= Corner[1].y && y <= Corner[0].y) || (y <= Corner[1].y && y >= Corner[0].y))) {
			return true;
		}
		else {
			return false;
		}
	}
}


Point* CRectangle:: getPoints() {
return Corner;
}


bool CRectangle::isSelected()
{
	if (Selected) {
		return true;
	}
	else {
		return false;
	}

}



//void CFigure::Save(ofstream &OutFile) {
//	
//}