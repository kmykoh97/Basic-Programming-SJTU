#ifndef GUI_H
#define GUI_H

#include <FL/Fl.H>
#include <FL/Fl_Output.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Window.H>
#include <sstream>
#include <string>
#include "calculator.h"

using namespace std;

class gui
{
    public:
    
    // some constants for buttons' and windows' size
	static const int SPACE = 10;
	static const int bLength = 40;
	static const int bWidth = 30;
	static const Fl_Color bc = FL_WHITE;
	Fl_Color bc1 = fl_rgb_color(238, 154, 176);
	Fl_Color bc2 = fl_rgb_color(244, 241, 251);
	Fl_Color bc3 = fl_rgb_color(185, 245, 180);
	Fl_Color bc4 = fl_rgb_color(250, 202, 180);
	
	
	// constructor and destructor
	gui();
	~gui();
	
	// method to show the calculator window
	void show();

    private:

	// declarations of some global window pointers
	Fl_Window *mainWindow;
	Fl_Output *outputWindow;
	Fl_Output *inputWindow;
	
	// buttons
	Fl_Button *b0; // 0
	Fl_Button *b1; // 1
	Fl_Button *b2; // 2
	Fl_Button *b3; // 3
	Fl_Button *b4; // 4
	Fl_Button *b5; // 5
	Fl_Button *b6; // 6
	Fl_Button *b7; // 7
	Fl_Button *b8; // 8
	Fl_Button *b9; // 9
	Fl_Button *bDot; // .
	Fl_Button *bAdd; // +
	Fl_Button *bSub; // -
	Fl_Button *bMul; // *
	Fl_Button *bDiv; // /
	Fl_Button *bEqual; // =
	Fl_Button *bFactorial; // !
	Fl_Button *bClear; // CE 
	Fl_Button *bLeft; // (
	Fl_Button *bRight; // )
	Fl_Button *bANS; // ANS
	Fl_Button *bDel; // DEL
	Fl_Button *bRemainder; // %
	
	// callbacks
	static void bNum_call(Fl_Widget *w, void *data); // integers
	static void bEqual_call(Fl_Widget *w, void *data); // =
	static void bClear_call(Fl_Widget *w, void *data); // CE
	static void bExpression_call(Fl_Widget *w, void *data);// +-*/!()
	static void bANS_call(Fl_Widget *w, void *data); // ANS
	static void bDel_call(Fl_Widget *w, void *data); // DEL
	static void bRemainder_call(Fl_Widget *w, void *data); // %
};

#endif
