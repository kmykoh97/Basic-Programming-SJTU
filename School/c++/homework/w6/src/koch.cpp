#include "header.h"

// main algorithm
void koch (int x1, int y1, int x2, int y2, int it)
{
	// declarations
	float angle;
	int x3, y3, x4, y4, x, y;
	
	angle = 60 * M_PI / 180; // convert 60 degree to radian
 	x3 = (2 * x1 + x2) / 3; // to get first point of x
	y3 = (2 * y1 + y2) / 3; // to get first point of y
	
	x4 = (x1 + 2 * x2) / 3; // to get second point of x
	y4 = (y1 + 2 * y2) / 3; // to get second point of y
	
	x = x3 + (x4 - x3) * cos(angle) + (y4 - y3) * sin(angle); // to get the peak x-coordinate
	y = y3 - (x4 - x3) * sin(angle) + (y4 - y3) * cos(angle); // to get the peak y-coordinate
	
	if (it > 1) {
		// doing recursive to peform koch algorithm
		koch(x1, y1, x3, y3, it - 1);
		koch(x3, y3, x, y, it - 1);
		koch(x, y, x4, y4, it - 1);
		koch(x4, y4, x2, y2, it - 1);
	} else {
		// do something to connect those point	s
		points line1 = {x1, y1, x3, y3};
		points line2 = {x3, y3, x, y};
		points line3 = {x, y, x4, y4};
		points line4 = {x4, y4, x2, y2};
		v1.push_back(line1);
		v1.push_back(line2);
		v1.push_back(line3);
		v1.push_back(line4);
	}
}
