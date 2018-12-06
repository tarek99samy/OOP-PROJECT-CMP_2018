#include "CRectangle.h"

CRectangle::CRectangle(Point P1, Point P2, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;
}
	

void CRectangle::Draw(Output* pOut) const
{
	//Call Output::DrawRect to draw a rectangle on the screen	
	pOut->DrawRect(Corner1, Corner2, FigGfxInfo, Selected);
}

bool CRectangle::Isinside(int x, int y){
	if (Corner1.x < Corner2.x) {	// "corner1" is at left
		if ((x >= Corner1.x && x <= Corner2.x) && ((y >= Corner1.y && y <= Corner2.y) || (y <= Corner1.y && y >= Corner2.y))) {
			return true;
		}
		else {
			return false;
		}
	}

	else if (Corner1.x > Corner2.x) {	// "corner2" is at left
		if ((x >= Corner2.x && x <= Corner1.x) && ((y >= Corner2.y && y <= Corner1.y) || (y <= Corner2.y && y >= Corner1.y))) {
			return true;
		}
		else {
			return false;
		}
	}
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
