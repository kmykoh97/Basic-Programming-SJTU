// koch curve by Meng Yit Koh

#include "header.h"

// global declarations
vector <points> v1;
Fl_Color c;

// draw() method
void single_blink_window::draw()
{
	fl_begin_loop();
	
	for (int i = 0; i < v1.size(); ++i) {
		fl_color(c);		
		fl_line(v1[i].firstx, v1[i].firsty, v1[i].secondx, v1[i].secondy);
	}

	fl_end_loop();
}

// declarations of some global pointers
single_blink_window *w2;
Fl_Window *w1;

int main()
{
	w1 = new Fl_Window(1000,1000, "KOCH curve"); // default window
	
	koch (50,650,950,650,1); // algorithm
	
	// Buttons functions for color
	Fl_Button *b0 = new Fl_Button(10, 800, 50, 30, "BLACK");
  	b0 -> callback(CbBlack, 0);
	Fl_Button *b1 = new Fl_Button(100, 800, 50, 30, "RED");
  	b1 -> callback(CbRed, 0);
	Fl_Button *b2 = new Fl_Button(200, 800, 50, 30, "GREEN");
  	b2 -> callback(CbGreen, 0);
	Fl_Button *b3 = new Fl_Button(300, 800, 50, 30, "BLUE");
  	b3 -> callback(CbBlue, 0);
	
	// Button functions for KOCH
	Fl_Button *b5 = new Fl_Button(500, 800, 50, 30, "1");
  	b5 -> callback(Cb1, 0);
	Fl_Button *b6 = new Fl_Button(600, 800, 50, 30, "2");
  	b6 -> callback(Cb2, 0);
	Fl_Button *b7 = new Fl_Button(700, 800, 50, 30, "3");
  	b7 -> callback(Cb3, 0);
	Fl_Button *b8 = new Fl_Button(800, 800, 50, 30, "4");
  	b8 -> callback(Cb4, 0);
	
	// drawing window
	w2 = new single_blink_window(10, 10, 980, 700, "FLTK");
	w2 -> color(FL_WHITE);
	
	w1 -> end();
	w1 -> show();
	
	Fl::run();// display GUI
}
