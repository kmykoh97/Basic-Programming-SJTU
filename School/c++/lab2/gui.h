#ifndef GUI_H
#define GUI_H

#include <FL/Fl.H>
#include <FL/Fl_Output.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>
#include <sstream>
#include <string>
#include "header.h"

using namespace std;

class gui
{
    public:
    
    // some constants for buttons' and window size
    // const unsigned int WIN_BACKGROUND = 53U;
	static const int SPACE = 10;
	static const int BTN_LEN = 40;
	static const int BTN_WID = 30;
	
	// constructor and destructor
	gui();
	~gui();
	
	// to show the calculator window
	void show();

    private:

	// declarations of some global window pointers
	Fl_Window *mainWindow;
	Fl_Output *outputWindow;
	Fl_Output *inputWindow;
	
	// widgets------------------------------------------------------------
	
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
	
	/* delete
	// Fl_Button *bAbs; // |
	// Fl_Button *bRemainder; // %
	// Fl_Button *ButtonBck; //
	*/
	
	/* try delete
	// window box
	Fl_Box *box;
	*/
	
	/*delete
	// Fl_Radio_Round_Button *SimRatio;
	// Fl_Radio_Round_Button *LineRatio;
	*/
	
	// widgets------------------------------------------------------------

	/*try to delete
	gui& operator=(const gui&);
	gui(const gui&);
	*/
	
	// callback functions------------------------------------------------------------
	
	// callbacks
	static void bNum_call(Fl_Widget *w, void *data); // integers
	static void bEqual_call(Fl_Widget *w, void *data); // =
	static void bClear_call(Fl_Widget *w, void *data); // CE
	static void bExpression_call(Fl_Widget *w, void *data); // +-*/!()
	static void bANS_call(Fl_Widget *w, void *data);
	
	/*delete
	// static void BtnSigNDel0_Click(Fl_Widget *w, void *data);//运算符（不消去默认的0），在单步计算模式直接得到结果
	// static void BtnBck_Click(Fl_Widget *w, void *data); // <-
	static void RatioSim_Click(Fl_Widget *w, void *data);//step mode
	static void RatioLine_Click(Fl_Widget *w, void *data);//line mode
	*/
	
	// callback functions------------------------------------------------------------
};

#endif
