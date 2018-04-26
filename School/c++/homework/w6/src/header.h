#include <vector>
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/fl_draw.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Single_Window.H>
#include <cmath>

using namespace std;

// create type for points
struct points
{
	int firstx;
	int firsty;
	int secondx;
	int secondy;
};

// inheritance from window class to perform draw()
class single_blink_window : public Fl_Single_Window
{
	public:
		void draw();
  		single_blink_window(int x, int y,int w,int h,const char *l)
    		: Fl_Single_Window(x,y,w,h,l) {resizable(this);}
};

void koch (int x1, int y1, int x2, int y2, int it);

//=====================================================================================

// call back functions
void CbBlack(Fl_Widget *o, void* );

void CbRed(Fl_Widget *o, void* );

void CbGreen(Fl_Widget *o, void* );

void CbBlue(Fl_Widget *o, void* );

void Cb1(Fl_Widget *o, void* );

void Cb2(Fl_Widget *o, void* );

void Cb3(Fl_Widget *o, void* );

void Cb4(Fl_Widget *o, void* );
//=======================================================================================

// global declarations
extern vector <points> v1;
extern Fl_Color c;

// declarations of some global pointers
extern single_blink_window *w2;
extern Fl_Window *w1;
