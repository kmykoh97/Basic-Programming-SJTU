#include<iostream>
// #include<list>

using namespace std;

double gradient (double x1, double y1, double x2, double y2)
{
  // double m;
  // m = (y2-y1)/(x2-x1);
  // cout << m << endl;
  //
  // return m;
  
  return (y2-y1)/(x2-x1);
}

bool determine (double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4)
{
  double m, diff1, diff2;
  m = gradient(x1, y1, x2, y2);
  diff1 = y3 - (m * (x3 - x1) + y1);
  diff2 = y4 - (m * (x4 - x1) + y1);
  if (diff1 < 0 && diff2 > 0) {
    return true; // concave
  } else if (diff1 > 0 && diff2 < 0)  {
    return true;
  }

  return false; // convex
}

int main ()
{
  bool q, w, e, r;
  // double co[][2] = {{0,0},{1,4},{2,2},{3,1}};
  double co[][2] = {{0,0},{1,3},{2,3},{2,1}};
  // cout << hi.size() << endl;
  // double r = gradient(co[0][0], co[0][1], co[1][0], co[1][1]);
  q = determine(co[0][0], co[0][1], co[1][0], co[1][1], co[2][0], co[2][1], co[3][0], co[3][1]);
  w = determine(co[3][0], co[3][1], co[0][0], co[0][1], co[1][0], co[1][1], co[2][0], co[2][1]);
  e = determine(co[2][0], co[2][1], co[3][0], co[3][1], co[0][0], co[0][1], co[1][0], co[1][1]);
  r = determine(co[1][0], co[1][1], co[2][0], co[2][1], co[3][0], co[3][1], co[0][0], co[0][1]);
  if (q == true || w == true || e == true || r == true) {
    cout << "Concave Polygon!" << endl;
  } else {
    cout << "Convex Polygon!" << endl;
  }
  // for (int i=0; i<4; i++) {
  //   int z1 = i;
  //   int z2 = ++z1;
  //   int z3 = ++z2;
  //   int

  return 0;
}

  
