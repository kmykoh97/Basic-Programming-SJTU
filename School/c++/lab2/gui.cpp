#include "gui.h"

// constructor
gui::gui()
{
    // windows----------------------------------------------------------------------------------
    
    // main window initialisation
    this -> mainWindow = new Fl_Window(500, 200 ,6 * SPACE + 5 * BTN_LEN, 9 * SPACE + 8 * BTN_WID, "calculator"); // default window
    // this -> mainWindow -> color(WIN_BACKGROUND);
    
    // Input Output Windows
	this -> inputWindow = new Fl_Output(SPACE, SPACE * 2 + BTN_WID * 2, 5 * BTN_LEN + 4 * SPACE, BTN_WID + SPACE);
	// this -> inputWindow -> value("0");
	this -> outputWindow = new Fl_Output(SPACE, SPACE * 2 + BTN_WID, 5 * BTN_LEN + 4 * SPACE, BTN_WID);
	
	/* try delete
	this -> Box = new Fl_Box(SPACE, SPACE, 5 * BTN_LEN + 4 * SPACE, BTN_WID);
	this -> Box -> box(FL_THIN_UP_BOX);
	this -> Box -> color(WIN_BACKGROUND);*/

	/*this -> SimRatio = new Fl_Radio_Round_Button (SPACE + BTN_WID / 2, SPACE, BTN_LEN * 2 , BTN_WID,"step mode");
	this -> LineRatio = new Fl_Radio_Round_Button (SPACE * 4 + BTN_WID * 7 / 2, SPACE, BTN_LEN * 2, BTN_WID,"line mode");
	this -> LineRatio->value(1);//使它选中*/
	
	// windows----------------------------------------------------------------------------------
    
    // widgets---------------------------------------------------------------------------
    
    // buttons initialisation
    this -> b0 = new Fl_Button(SPACE, 7 * BTN_WID + 8 * SPACE, BTN_LEN * 2 + SPACE, BTN_WID, "0");
	// this -> b0 -> color(FL_GREY);
	this -> b1 = new Fl_Button(SPACE, 6 * BTN_WID + 7 * SPACE, BTN_LEN, BTN_WID, "1");
	// this -> Button1 -> color(WIN_BACKGROUND);
	this -> b2 = new Fl_Button(SPACE * 2 + BTN_LEN, 6 * BTN_WID + 7 * SPACE, BTN_LEN, BTN_WID, "2");
	// this -> Button2 -> color(WIN_BACKGROUND);
	this -> b3 = new Fl_Button(SPACE * 3 + BTN_LEN * 2, 6 * BTN_WID + 7 * SPACE, BTN_LEN, BTN_WID, "3");
	// this -> Button3 -> color(WIN_BACKGROUND);
	this -> b4 = new Fl_Button(SPACE, 5 * BTN_WID + 6 * SPACE, BTN_LEN, BTN_WID, "4");
	// this -> Button4 -> color(WIN_BACKGROUND);
	this -> b5 = new Fl_Button(SPACE * 2 + BTN_LEN, 5 * BTN_WID + 6 * SPACE, BTN_LEN, BTN_WID, "5");
	// this -> Button5 -> color(WIN_BACKGROUND);d
	this -> b6 = new Fl_Button(SPACE * 3 + BTN_LEN * 2, 5 * BTN_WID + 6 * SPACE, BTN_LEN, BTN_WID, "6");
	// this -> Button6 -> color(WIN_BACKGROUND);
	this -> b7 = new Fl_Button(SPACE, 4 * BTN_WID + 5 * SPACE, BTN_LEN, BTN_WID, "7");
	// this -> Button7 -> color(WIN_BACKGROUND);
	this -> b8 = new Fl_Button(SPACE * 2 + BTN_LEN, 4 * BTN_WID + 5 * SPACE, BTN_LEN, BTN_WID, "8");
	// this -> Button8 -> color(WIN_BACKGROUND);
	this -> b9 = new Fl_Button(SPACE * 3 + BTN_LEN * 2, 4 * BTN_WID + 5 * SPACE, BTN_LEN, BTN_WID, "9");
	// this -> Button9 -> color(WIN_BACKGROUND);
	this -> bAdd = new Fl_Button(SPACE * 4 + BTN_LEN * 3, 7 * BTN_WID + 8 * SPACE, BTN_LEN, BTN_WID, "+");
	// this -> ButtonAdd -> color(WIN_BACKGROUND);
	this -> bSub = new Fl_Button(SPACE * 4 + BTN_LEN * 3, 6 * BTN_WID + 7 * SPACE, BTN_LEN, BTN_WID, "-");
	// this -> ButtonSub -> color(WIN_BACKGROUND);
	this -> bMul = new Fl_Button(SPACE * 4 + BTN_LEN * 3, 5 * BTN_WID + 6 * SPACE, BTN_LEN, BTN_WID, "*");
	// this -> ButtonMul -> color(WIN_BACKGROUND);
	this -> bDiv = new Fl_Button(SPACE * 4 + BTN_LEN * 3, 4 * BTN_WID + 5 * SPACE, BTN_LEN, BTN_WID, "/");
	// this -> ButtonDiv -> color(WIN_BACKGROUND);
	this -> bDot = new Fl_Button(SPACE * 3 + BTN_LEN * 2, 7 * BTN_WID + 8 * SPACE, BTN_LEN, BTN_WID, ".");
	// this -> ButtonDot -> color(WIN_BACKGROUND);
	this -> bLeft = new Fl_Button(SPACE * 4 + BTN_LEN * 3, 3 * BTN_WID + 4 * SPACE, BTN_LEN, BTN_WID, "(");
	// this -> ButtonLeft -> color(WIN_BACKGROUND);
	this -> bRight = new Fl_Button(SPACE * 5 + BTN_LEN * 4, 3 * BTN_WID + 4 * SPACE, BTN_LEN, BTN_WID, ")");
	// this -> ButtonRight -> color(WIN_BACKGROUND);
	this -> bFactorial = new Fl_Button(SPACE * 5 + BTN_LEN * 4, 5 * BTN_WID + 6 * SPACE, BTN_LEN, BTN_WID, "!");
	// this -> ButtonExc -> color(WIN_BACKGROUND);
	this -> bANS = new Fl_Button(SPACE * 5 + BTN_LEN * 4, 4 * BTN_WID + 5 * SPACE, BTN_LEN, BTN_WID, "ANS");
	// this -> ButtonRight -> color(WIN_BACKGROUND);
	this -> bClear = new Fl_Button(SPACE, 3 * BTN_WID + 4 * SPACE, BTN_LEN * 2 + SPACE, BTN_WID, "CE");
	// this -> ButtonClr -> color(WIN_BACKGROUND);
	this -> bEqual = new Fl_Button(SPACE * 5 + BTN_LEN * 4, 6 * BTN_WID + 7 * SPACE, BTN_LEN, BTN_WID * 2 + SPACE, "=");
	// this -> ButtonEqe -> color(WIN_BACKGROUND);
	
	/*delete
	// this -> ButtonSpr = new Fl_Button(SPACE * 5 + BTN_LEN * 4, 4 * BTN_WID + 5 * SPACE, BTN_LEN, BTN_WID, "%");
	// this -> ButtonSpr -> color(WIN_BACKGROUND);

	// this -> ButtonBck = new Fl_Button(SPACE, 3 * BTN_WID + 4 * SPACE, BTN_LEN, BTN_WID, "<-");
	// this -> ButtonBck -> color(WIN_BACKGROUND);
	
	// this -> ButtonAbs = new Fl_Button(SPACE * 3 + BTN_LEN * 2, 3 * BTN_WID + 4 * SPACE, BTN_LEN, BTN_WID, "|");
	// this -> ButtonAbs -> color(WIN_BACKGROUND);
	*/
	
	// widgets---------------------------------------------------------------------------

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
	
	/* delete
	// ButtonAbs->callback((Fl_Callback *)BtnSigDel0_Click, this);
	// ButtonSpr->callback((Fl_Callback *)BtnSigNDel0_Click, this);
	
	// ButtonBck -> callback((Fl_Callback *)BtnBck_Click, this);
	

	// SimRatio->callback((Fl_Callback *)RatioSim_Click, this);
	// LineRatio->callback((Fl_Callback *)RatioLine_Click, this);
	*/
	
	/* try delete
	Fl::scheme("gtk+");*/
}

// to show windows and elements in them
void gui::show()
{
	this -> mainWindow -> show();
	Fl::run();
}

void gui::bNum_call(Fl_Widget *w, void *data)
{
	// declarations
	Fl_Button *btn = (Fl_Button *)w;
	gui *inputW = (gui *)data;
	string temp = inputW -> inputWindow -> value();
	temp += btn -> label();
	inputW -> inputWindow -> value(temp.c_str());
}

/*delete
void gui::BtnSigNDel0_Click(Fl_Widget *w, void *data)
{
	
	try
	{
		Fl_Button *lpbtn = (Fl_Button *)w;
		MainForm *lpwnd = (MainForm *)data;
		string tmp = lpwnd->Output->value();
		if(tmp == "0" && lpbtn->label() == "-")//特殊情况
		{
			lpwnd->Output->value("-");
			return;
		}
		if(lpwnd->mode == 1)//单步模式
		{
			lpwnd->UpWnd->value((tmp + " =").c_str());
			Calculator *calc = new Calculator(tmp + ";");
			double val = calc->calculate();
			stringstream ss;
			ss.precision(10);
			ss<<val;
			ss>>tmp;
			delete calc;
		}
		tmp += lpbtn->label();
		lpwnd->Output->value(tmp.c_str());
	}
	catch(exception& ex)
	{
		MainForm *lpwnd = (MainForm *)data;
		lpwnd->Output->value("0");
		//fl_alert(ex.what());
		MessageBoxA(0, ex.what(), "错误！",0);
	}
}*/

void gui::bExpression_call(Fl_Widget *w, void *data)
{
	Fl_Button *btn = (Fl_Button *)w;
	gui *inputW = (gui *)data;
	string temp = inputW -> inputWindow -> value();
	/*try delete
	if(tmp == "0")
		tmp = "";
	*/
	temp += btn -> label();
	inputW -> inputWindow -> value(temp.c_str());
}

void gui::bClear_call(Fl_Widget *w, void *data)
{
	gui *inputW = (gui *)data;
	inputW -> inputWindow -> value("");
}

/*void MainForm::BtnBck_Click(Fl_Widget *w, void *data)//这个也不变
{
	MainForm *lpwnd = (MainForm *)data;
	Fl_Button *lpbtn = (Fl_Button *)w;
	string tmp = lpwnd->Output->value();
	int len = tmp.length();
	if(len == 1)
	{
		lpwnd->Output->value("0");
	}
	else
	{
		tmp = tmp.substr(0, len - 1);
		lpwnd->Output->value(tmp.c_str());
	}
}*/

void gui::bANS_call(Fl_Widget *w, void *data)
{
	Fl_Button *btn = (Fl_Button *)w;
	gui *inputW = (gui *)data;
	string temp = inputW -> inputWindow -> value();
	temp += btn -> label();
	inputW -> inputWindow -> value(temp.c_str());
}

void gui::bEqual_call(Fl_Widget *w, void *data)
{
	try
	{
		gui *inputW = (gui *)data;
		Fl_Button *btn = (Fl_Button *)w;
		string temp = inputW -> inputWindow -> value();
		inputW -> outputWindow -> value((temp).c_str());
		double val = calculate(temp+";");
		
		// to prevent double overbound
		stringstream tempss;
		tempss.precision(10);
		tempss << val;
		tempss >> temp;
		inputW -> inputWindow -> value(temp.c_str());
	}
	catch(badToken)
	{
		gui *inputW = (gui *)data;
		inputW -> inputWindow -> value("error!");
		/*delete
		// MessageBoxA(0, ex.what(), "错误！",0);*/
	}
}

/* delete
void MainForm::RatioSim_Click(Fl_Widget *w, void *data)
{
	MainForm *lpwnd = (MainForm *)data;
	lpwnd->mode = 1;
}

void MainForm::RatioLine_Click(Fl_Widget *w, void *data)
{
	MainForm *lpwnd = (MainForm *)data;
	lpwnd->mode = 2;
}
*/

gui::~gui()
{
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
	delete this -> outputWindow;
	delete this -> inputWindow;
	delete this -> mainWindow;
	
	/*delete
	delete this -> box;
	// delete this->ButtonBck;
	// delete this->ButtonSpr;
	// delete this->ButtonAbs;
	// delete this->SimRatio;
	// delete this->LineRatio;
	*/
}
