#include "Output.h"


Output::Output()
{
	//Initialize user interface parameters
	UI.InterfaceMode = MODE_DRAW;
	
	UI.width = 1250;
	UI.height = 650;
	UI.wx = 5;
	UI.wy =5;

	
	UI.StatusBarHeight = 50;
	UI.ToolBarHeight = 50;
	UI.MenuItemWidth = 80;
	
	UI.DrawColor = BLUE;	//Drawing color
	UI.FillColor = GREEN;	//Filling color
	UI.MsgColor = RED;		//Messages color
	UI.BkGrndColor = LIGHTGOLDENRODYELLOW;	//Background color
	UI.HighlightColor = MAGENTA;	//This color should NOT be used to draw figures. use if for highlight only
	UI.StatusBarColor = TURQUOISE;
	UI.PenWidth = 3;	//width of the figures frames

	
	//Create the output window
	pWind = CreateWind(UI.width, UI.height, UI.wx, UI.wy);
	//Change the title
	pWind->ChangeTitle("Paint for Kids - Programming Techniques Project");
	
	CreateDrawToolBar();
	CreateStatusBar();
}


Input* Output::CreateInput() const
{
	Input* pIn = new Input(pWind);
	return pIn;
}

//======================================================================================//
//								Interface Functions										//
//======================================================================================//

window* Output::CreateWind(int w, int h, int x, int y) const
{ 
	window* pW = new window(w, h, x, y);
	pW->SetBrush(UI.BkGrndColor);
	pW->SetPen(UI.BkGrndColor, 1);
	pW->DrawRectangle(0, UI.ToolBarHeight, w, h);	
	return pW;
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::CreateStatusBar() const
{
	pWind->SetPen(UI.StatusBarColor, 1);
	pWind->SetBrush(UI.StatusBarColor);
	pWind->DrawRectangle(0, UI.height - UI.StatusBarHeight, UI.width, UI.height);
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::ClearStatusBar() const
{
	//Clear Status bar by drawing a filled white rectangle
	pWind->SetPen(UI.StatusBarColor, 1);
	pWind->SetBrush(UI.StatusBarColor);
	pWind->DrawRectangle(0, UI.height - UI.StatusBarHeight, UI.width, UI.height);
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::CreateDrawToolBar() const
{
	UI.InterfaceMode = MODE_DRAW;

	//You can draw the tool bar icons in any way you want.
	//Below is one possible way
	
	


	//First prepare List of images for each menu item
	//To control the order of these images in the menu, 
	//reoder them in UI_Info.h ==> enum DrawMenuItem
	string MenuItemImages[DRAW_ITM_COUNT];
	MenuItemImages[ITM_LINE] = "images\\MenuItems\\line.jpg";
	MenuItemImages[ITM_RECT] = "images\\MenuItems\\DYNAMIC-SCREEN.jpg";
	MenuItemImages[ITM_TRI] = "images\\MenuItems\\paper triangles.jpg";
	MenuItemImages[ITM_RHOMBUS] = "images\\MenuItems\\imagesggg.jpg";
	MenuItemImages[ITM_ELLIPSE] = "images\\MenuItems\\joint-autjointd22-lagostina.jpg";
	MenuItemImages[ITM_CHNG_DRAW_CLR] = "images\\MenuItems\\imagesbbbbb.jpg";
	MenuItemImages[ITM_CHNG_FILL_CLR] = "images\\MenuItems\\84887_bucket_512x512.jpg";
	MenuItemImages[ITM_WHITE_CLR] = "images\\MenuItems\\white.jpg";
	MenuItemImages[ITM_BLACK_CLR] = "images\\MenuItems\\black.jpg";
	MenuItemImages[ITM_GREEN_CLR] = "images\\MenuItems\\green.jpg";
	MenuItemImages[ITM_BLUE_CLR] = "images\\MenuItems\\blue.jpg";
	MenuItemImages[ITM_RED_CLR] = "images\\MenuItems\\red.jpg";
	MenuItemImages[ITM_SELECT] = "images\\MenuItems\\select icon for phase 2.jpg";
	MenuItemImages[ITM_COPY] = "images\\MenuItems\\file_copy_37172-300x300.jpg";
	MenuItemImages[ITM_CUT] = "images\\MenuItems\\Artboard_96-512.jpg";
	MenuItemImages[ITM_PASTE] = "images\\MenuItems\\55.jpg";
	MenuItemImages[ITM_DEL] = "images\\MenuItems\\cesto-de-lixo_318-41524-ed.jpg";
	MenuItemImages[ITM_SAVE] = "images\\MenuItems\\floppy-disk-digital-data-storage-or-save-interface-symbol_318-48442.jpg";
	MenuItemImages[ITM_SAVE_BY_TYPE] = "images\\MenuItems\\file-action-document-filetype-type-sheet-page-paper_05-51---2.jpg";
	MenuItemImages[ITM_LOAD] = "images\\MenuItems\\img_4391-90.jpg";
	MenuItemImages[ITM_RESIZE]= "images\\MenuItems\\resize iocn for phase 2.jpg";
	MenuItemImages[ITM_EXIT] = "images\\MenuItems\\super_imgpower.jpg";
	MenuItemImages[ITM_TO_PLAY] = "images\\MenuItems\\transfer_bold_convert-512.jpg";
	//TODO: Prepare images for each menu item and add it to the list

	//Draw menu item one image at a time
	for(int i=0; i<DRAW_ITM_COUNT; i++)
	pWind->DrawImage(MenuItemImages[i], i*(UI.MenuItemWidth-28), 0, UI.MenuItemWidth-10, UI.ToolBarHeight);

	

	//Draw a line under the toolbar
	/*pWind->SetPen(RED, 1);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);*/

}
//////////////////////////////////////////////////////////////////////////////////////////

void Output::CreatePlayToolBar() const
{
	UI.InterfaceMode = MODE_PLAY;

	pWind->SetPen(WHITE, 3);
	pWind->SetBrush(WHITE);
	pWind->DrawRectangle(0, 0, UI.width, UI.ToolBarHeight, FILLED);


	string MenuItemImages[PLAY_ITM_COUNT];
	MenuItemImages[ITM_ByFigure] = "images\\MenuItems\\BYshape.jpg";
	MenuItemImages[ITM_ByColour] = "images\\MenuItems\\BYcolor.jpg";
	MenuItemImages[ITM_TO_DRAW] = "images\\MenuItems\\transfer_bold_convert-512.jpg";
	MenuItemImages[ITM_EXIT2] = "images\\MenuItems\\super_imgpower.jpg";

	for (int i = 0; i<PLAY_ITM_COUNT; i++)
		pWind->DrawImage(MenuItemImages[i], i*UI.MenuItemWidth, 0, UI.MenuItemWidth - 5, UI.ToolBarHeight);

}
//////////////////////////////////////////////////////////////////////////////////////////

void Output::ClearDrawArea() const
{
	pWind->SetPen(UI.BkGrndColor, 1);
	pWind->SetBrush(UI.BkGrndColor);
	pWind->DrawRectangle(0, UI.ToolBarHeight, UI.width, UI.height - UI.StatusBarHeight);
	
}
//////////////////////////////////////////////////////////////////////////////////////////

void Output::PrintMessage(string msg) const	//Prints a message on status bar
{
	ClearStatusBar();	//First clear the status bar
	
	pWind->SetPen(UI.MsgColor, 50);
	pWind->SetFont(20, BOLD , BY_NAME, "Arial");   
	pWind->DrawString(10, UI.height - (int)(UI.StatusBarHeight/1.5), msg);
}
//////////////////////////////////////////////////////////////////////////////////////////

color Output::getCrntDrawColor() const	//get current drawing color
{	return UI.DrawColor;	}
//////////////////////////////////////////////////////////////////////////////////////////

color Output::getCrntFillColor() const	//get current filling color
{	return UI.FillColor;	}
//////////////////////////////////////////////////////////////////////////////////////////
	
int Output::getCrntPenWidth() const		//get current pen width
{	return UI.PenWidth;	}

//======================================================================================//
//								Figures Drawing Functions								//
//======================================================================================//

void Output::DrawRect(Point P1, Point P2, GfxInfo RectGfxInfo, bool selected) const
{
	P1.y = P1.y >= UI.ToolBarHeight ? P1.y : UI.ToolBarHeight;
	P2.y = P2.y >= UI.ToolBarHeight ? P2.y : UI.ToolBarHeight;

	color DrawingClr;
	if(selected)	
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else			
		DrawingClr = RectGfxInfo.DrawClr;
	
	pWind->SetPen(DrawingClr,1);
	drawstyle style;
	if (RectGfxInfo.isFilled)	
	{
		style = FILLED;		
		pWind->SetBrush(RectGfxInfo.FillClr);
	}
	else	
		style = FRAME;

	
	pWind->DrawRectangle(P1.x, P1.y, P2.x, P2.y, style);
	
}
void Output::DrawTriangle(Point P1, Point P2,Point P3, GfxInfo RectGfxInfo, bool selected) const
{
	P1.y = P1.y >= UI.ToolBarHeight ? P1.y : UI.ToolBarHeight;
	P2.y = P2.y >= UI.ToolBarHeight ? P2.y : UI.ToolBarHeight;
	P3.y = P3.y >= UI.ToolBarHeight ? P3.y : UI.ToolBarHeight;

	color DrawingClr;
	if(selected)	
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else			
		DrawingClr = RectGfxInfo.DrawClr;
	
	pWind->SetPen(DrawingClr,1);
	drawstyle style;
	if (RectGfxInfo.isFilled)	
	{
		style = FILLED;		
		pWind->SetBrush(RectGfxInfo.FillClr);
	}
	else	
		style = FRAME;

	
	pWind->DrawTriangle(P1.x, P1.y, P2.x, P2.y,P3.x,P3.y, style);

}

void Output::DrawEllipse(Point P1, GfxInfo RectGfxInfo, bool selected) const
{
	P1.y = P1.y >= UI.ToolBarHeight + 40 ? P1.y : UI.ToolBarHeight + 40;

	color DrawingClr;
	if(selected)	
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else			
		DrawingClr = RectGfxInfo.DrawClr;
	
	pWind->SetPen(DrawingClr,1);
	drawstyle style;
	if (RectGfxInfo.isFilled)	
	{
		style = FILLED;		
		pWind->SetBrush(RectGfxInfo.FillClr);
	}
	else	
		style = FRAME;

	
	pWind->DrawEllipse(P1.x-100, P1.y-40, P1.x+100, P1.y+40, style);

}
void Output::Drawline(Point P1, Point P2, GfxInfo lineGfxInfo, bool selected) const
{
	P1.y = P1.y >= UI.ToolBarHeight ? P1.y : UI.ToolBarHeight;
	P2.y = P2.y >= UI.ToolBarHeight ? P2.y : UI.ToolBarHeight;

	color DrawingClr;
	if (selected) {
		DrawingClr = UI.HighlightColor;
	}
	else
	{
		DrawingClr = lineGfxInfo.DrawClr;
	}
	pWind->SetPen(DrawingClr,1);
	drawstyle style;
	if (lineGfxInfo.isFilled) {
		style = FILLED;
		pWind->SetBrush(lineGfxInfo.FillClr);
	}
	else
	{
		style = FRAME;
	}

	pWind->DrawLine(P1.x, P1.y, P2.x, P2.y, style);

}

void Output::DrawRhombus(Point P1, GfxInfo RectGfxInfo, bool selected) const
{

	int h = 90; // h is the half of the vertical diagonal
	int w = 60; // w is the half of the horizontal diagonal
	P1.y = P1.y >= UI.ToolBarHeight + h ? P1.y : UI.ToolBarHeight + h;

	Point Pr1, Pr2, Pr3, Pr4;
	Pr1.x = P1.x - w;
	Pr1.y = P1.y;
	Pr2.x = P1.x;
	Pr2.y = P1.y + h;
	Pr3.x = P1.x + w;
	Pr3.y = P1.y;
	Pr4.x = P1.x;
	Pr4.y = P1.y - h;

	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = RectGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, 1);
	drawstyle style;
	if (RectGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(RectGfxInfo.FillClr);
	}
	else
		style = FRAME;


	pWind->DrawRhombus(Pr1.x, Pr1.y, Pr2.x, Pr2.y, Pr3.x, Pr3.y, Pr4.x, Pr4.y, style);
}

//////////////////////////////////////////////////////////////////////////////////////////
Output::~Output()
{
	delete pWind;
}

