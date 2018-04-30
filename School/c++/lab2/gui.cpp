#include "gui.h"

// constructor
gui::gui()
{   
    // main window initialisation
    this -> mainWindow = new Fl_Window(500, 200 ,6 * SPACE + 5 * bLength, 9 * SPACE + 8 * bWidth, "calculator"); // default window
    this -> mainWindow -> color(bc2);
    
    // Input Output Windows
	this -> inputWindow = new Fl_Output(SPACE, SPACE * 2 + bWidth * 2, 5 * bLength + 4 * SPACE, bWidth + SPACE);
	this -> outputWindow = new Fl_Output(SPACE, SPACE * 2 + bWidth, 5 * bLength + 4 * SPACE, bWidth);
	
    // buttons initialisation
    this -> b0 = new Fl_Button(SPACE * 2 + bLength, 7 * bWidth + 8 * SPACE, bLength, bWidth, "0");
	this -> b0 -> color(bc);
	this -> b1 = new Fl_Button(SPACE, 6 * bWidth + 7 * SPACE, bLength, bWidth, "1");
	this -> b1 -> color(bc);
	this -> b2 = new Fl_Button(SPACE * 2 + bLength, 6 * bWidth + 7 * SPACE, bLength, bWidth, "2");
	this -> b2 -> color(bc);
	this -> b3 = new Fl_Button(SPACE * 3 + bLength * 2, 6 * bWidth + 7 * SPACE, bLength, bWidth, "3");
	this -> b3 -> color(bc);
	this -> b4 = new Fl_Button(SPACE, 5 * bWidth + 6 * SPACE, bLength, bWidth, "4");
	this -> b4 -> color(bc);
	this -> b5 = new Fl_Button(SPACE * 2 + bLength, 5 * bWidth + 6 * SPACE, bLength, bWidth, "5");
	this -> b5 -> color(bc);
	this -> b6 = new Fl_Button(SPACE * 3 + bLength * 2, 5 * bWidth + 6 * SPACE, bLength, bWidth, "6");
	this -> b6 -> color(bc);
	this -> b7 = new Fl_Button(SPACE, 4 * bWidth + 5 * SPACE, bLength, bWidth, "7");
	this -> b7 -> color(bc);
	this -> b8 = new Fl_Button(SPACE * 2 + bLength, 4 * bWidth + 5 * SPACE, bLength, bWidth, "8");
	this -> b8 -> color(bc);
	this -> b9 = new Fl_Button(SPACE * 3 + bLength * 2, 4 * bWidth + 5 * SPACE, bLength, bWidth, "9");
	this -> b9 -> color(bc);
	this -> bAdd = new Fl_Button(SPACE * 4 + bLength * 3, 7 * bWidth + 8 * SPACE, bLength, bWidth, "+");
	this -> bSub = new Fl_Button(SPACE * 4 + bLength * 3, 6 * bWidth + 7 * SPACE, bLength, bWidth, "-");
	this -> bMul = new Fl_Button(SPACE * 4 + bLength * 3, 5 * bWidth + 6 * SPACE, bLength, bWidth, "*");
	this -> bDiv = new Fl_Button(SPACE * 4 + bLength * 3, 4 * bWidth + 5 * SPACE, bLength, bWidth, "/");
	this -> bDot = new Fl_Button(SPACE * 3 + bLength * 2, 7 * bWidth + 8 * SPACE, bLength, bWidth, ".");
	this -> bDot -> color(bc);
	this -> bLeft = new Fl_Button(SPACE * 4 + bLength * 3, 3 * bWidth + 4 * SPACE, bLength, bWidth, "(");
	this -> bRight = new Fl_Button(SPACE * 5 + bLength * 4, 3 * bWidth + 4 * SPACE, bLength, bWidth, ")");
	this -> bFactorial = new Fl_Button(SPACE * 5 + bLength * 4, 5 * bWidth + 6 * SPACE, bLength, bWidth, "!");
	this -> bANS = new Fl_Button(SPACE, 7 * bWidth + 8 * SPACE, bLength, bWidth, "ANS");
	this -> bANS -> color(bc);
	this -> bClear = new Fl_Button(SPACE, 3 * bWidth + 4 * SPACE, bLength * 2 + SPACE, bWidth, "CE");
	this -> bClear -> color(bc4);
	this -> bEqual = new Fl_Button(SPACE * 5 + bLength * 4, 6 * bWidth + 7 * SPACE, bLength, bWidth * 2 + SPACE, "=");
	this -> bEqual -> color(bc3);
	this -> bDel = new Fl_Button(SPACE * 3 + bLength * 2, 3 * bWidth + 4 * SPACE, bLength, bWidth, "DEL");
	this -> bDel -> color(bc1);
	this -> bRemainder = new Fl_Button(SPACE * 5 + bLength * 4, 4 * bWidth + 5 * SPACE, bLength, bWidth, "%");

	this -> mainWindow -> end(); // stops adding widgets
	
	// callbacks
	b0 -> callback(bNum_call, this);
	b1 -> callback(bNum_call, this);
	b2 -> callback(bNum_call, this);
	b3 -> callback(bNum_call, this);
	b4 -> callback(bNum_call, this);
	b5 -> callback(bNum_call, this);
	b6 -> callback(bNum_call, this);
	b7 -> callback(bNum_call, this);
	b8 -> callback(bNum_call, this);
	b9 -> callback(bNum_call, this);
	bAdd -> callback(bExpression_call, this);
	bSub -> callback(bExpression_call, this);
	bMul -> callback(bExpression_call, this);
	bDiv -> callback(bExpression_call, this);
	bDot -> callback(bNum_call, this);
	bLeft -> callback(bExpression_call, this);
	bRight -> callback(bExpression_call, this);
	bANS -> callback(bANS_call, this);
	bFactorial -> callback(bExpression_call, this);
	bClear -> callback(bClear_call, this);
	bEqual -> callback(bEqual_call, this);
	bDel -> callback(bDel_call, this);
	bRemainder -> callback(bRemainder_call, this);
}

// to show windows and elements in them
void gui::show()
{
	this -> mainWindow -> show();
	Fl::run();
}

// callbacks
void gui::bNum_call(Fl_Widget *w, void *data)
{
	// declarations
	Fl_Button *btn = (Fl_Button *)w;
	gui *inputW = (gui *)data;
	string temp = inputW -> inputWindow -> value();
	temp += btn -> label();
	inputW -> inputWindow -> value(temp.c_str());
}

// callbacks
void gui::bExpression_call(Fl_Widget *w, void *data)
{
	Fl_Button *btn = (Fl_Button *)w;
	gui *inputW = (gui *)data;
	string temp = inputW -> inputWindow -> value();
	temp += btn -> label();
	inputW -> inputWindow -> value(temp.c_str());
}

// callbacks
void gui::bClear_call(Fl_Widget *w, void *data)
{
	gui *inputW = (gui *)data;
	inputW -> inputWindow -> value("");
}

// callbacks
void gui::bANS_call(Fl_Widget *w, void *data)
{
	Fl_Button *btn = (Fl_Button *)w;
	gui *inputW = (gui *)data;
	string temp = inputW -> inputWindow -> value();
	temp += btn -> label();
	inputW -> inputWindow -> value(temp.c_str());
}

// callbacks
void gui::bRemainder_call(Fl_Widget *w, void *data)
{
	Fl_Button *btn = (Fl_Button *)w;
	gui *inputW = (gui *)data;
	string temp = inputW -> inputWindow -> value();
	temp += btn -> label();
	inputW -> inputWindow -> value(temp.c_str());
}

// callbacks(equal)
void gui::bEqual_call(Fl_Widget *w, void *data)
{
	try
	{
		gui *inputW = (gui *)data;
		Fl_Button *btn = (Fl_Button *)w;
		string temp = inputW -> inputWindow -> value();
		double val = calculate(temp+";");
		
		// to prevent double overbound
		stringstream tempss;
		tempss.precision(10);
		tempss << val;
		tempss >> temp;
		inputW -> outputWindow -> value(temp.c_str());
		inputW -> inputWindow -> value("");
	}
	catch(badToken) // catch error returned by extra.cpp
	{
		gui *inputW = (gui *)data;
		inputW -> inputWindow -> value("error!");
	}
}

// callbacks(delete character)
void gui::bDel_call(Fl_Widget *w, void *data)
{
	gui *inputW = (gui *)data;
	string temp = inputW -> inputWindow -> value();
	temp.erase(temp.end() - 1);
	inputW -> inputWindow -> value(temp.c_str());
}

// destructor
gui::~gui()
{
	// delete all pointers used
	delete this -> b0;
	delete this -> b1;
	delete this -> b2;
	delete this -> b3;
	delete this -> b4;
	delete this -> b5;
	delete this -> b6;
	delete this -> b7;
	delete this -> b8;
	delete this -> b9;
	delete this -> bAdd;
	delete this -> bSub;
	delete this -> bMul;
	delete this -> bDiv;
	delete this -> bDot;
	delete this -> bLeft;
	delete this -> bRight;
	delete this -> bFactorial;
	delete this -> bEqual;
	delete this -> bClear;
	delete this -> bRemainder;
	delete this -> bANS;
	delete this -> bDel;
	delete this -> outputWindow;
	delete this -> inputWindow;
	delete this -> mainWindow;
}
