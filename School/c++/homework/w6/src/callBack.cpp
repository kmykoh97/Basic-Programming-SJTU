#include "header.h"

// CallBack Functions
void CbBlack(Fl_Widget *o, void* )
{
	c = FL_BLACK;
	w2 -> redraw();
}

void CbRed(Fl_Widget *o, void* )
{
	c = FL_RED;
	w2 -> redraw();
}

void CbGreen(Fl_Widget *o, void* )
{
	c = FL_GREEN;
	w2 -> redraw();
}

void CbBlue(Fl_Widget *o, void* )
{
	c = FL_BLUE;
	w2 -> redraw();
}

void Cb1(Fl_Widget *o, void* )
{
	v1.clear();
	koch (50,650,950,650,1);
	w2 -> flush();
	w2 -> hide();
	w2 -> show();
}

void Cb2(Fl_Widget *o, void* )
{
	v1.clear();
	koch (50,650,950,650,2);
	w2 -> flush();
	w2 -> hide();
	w2 -> show();
}

void Cb3(Fl_Widget *o, void* )
{
	v1.clear();
	koch (50,650,950,650,3);
	w2 -> flush();
	w2 -> hide();
	w2 -> show();
}

void Cb4(Fl_Widget *o, void* )
{
	v1.clear();
	koch (50,650,950,650,4);
	w2 -> flush();
	w2 -> hide();
	w2 -> show();
}
