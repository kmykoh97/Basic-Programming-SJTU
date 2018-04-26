#include<iostream>
#include<cstdlib>
#include<cmath>
using namespace std;


/*
A code by Mr. Parth Goswami */

class graphdrawing
{
	int a, b, c, d, k;
	int Graph[50][50];
	int choice;
	int subchoice = 0;
	double y;
	double x;
	public:
		void graphdrawings()
		{
			for(int i = 0; i < 50; i++)
			{
				for(int j = 0; j < 50; j++)
				{
					Graph[i][j] = 0;
				}
			}
			cout << "WELCOME TO THE DRAWING OF GRAPHS";
			cout << "Please enter the type of Graph according to the following choices " << endl << endl;
			cout << "1. Polynomial?" << endl;
			cout << "2. Logarithmic?" << endl;
			cout << "3. Trigonometric ?" << endl;
			cout << "4. Exponential ?" << endl;
			cout << "5. Hyperbolic (xy = constant)" << endl;
			cout << "6. Circular (x*x + y*y = constant)" << endl;
			cin >> choice; 
			subset();
			subchoices();
			calc();
		}
		void subset()
		{
			switch(choice)
			{
			case 1:
				cout << "If the polynomial is of the sort ax + b = y.  Enter 1" << endl;
				cout << "If the polynomial is of the sort ax2 + bx + c = y.  Enter 2" << endl;
				cout << "If the polynomial is of the form ax3 + bx2 + cd + d = y.  Enter 3" << endl;
				cin >> subchoice;
				break;
			case 2:
				cout << "The given log function is y = a log (bx), then ENTER 4" << endl;
				cin >> subchoice;
				break;
			case 3:
				cout << " y = aSin(bx) , ENTER 6" << endl;
				cout << " y = aCos(bx) ,  Enter 7" << endl;
				cout << " y = aTan(bx) , Enter 8" << endl;
				cin >> subchoice;
				break;
			case 4:
				cout << "y = ae^bx, ENTER 9" << endl;
				cin >> subchoice;
				break;
			case 5:
				cout << "xy = k, ENTER 10" << endl;
				cin >> subchoice;
				break;
			case 6:
				cout << "Circle, Enter 11" << endl;
				cin >> subchoice;
				break;
			default:
				cout << "SORRY, you had not entered a valid choice" << endl;  
			
			
		}
		}
		void subchoices()
		{
			switch(subchoice)
			{case 0:	
				break;
			case 1:
				cout << "Enter a followed by b";
				cin >> a >> b;
				break;
			case 2:
				cout << "Enter a followed by b followed by c";
				cin >> a >> b >> c;
				break;
			case 3:
				cout << "Enter a, b, c, d";
				cin >> a >> b >> c >> d;
				break;
			case 4:
				cout << "Enter a, b";
				cin >> a >> b;
				break;
			case 5:
				cout << "Enter a, b";
				cin >> a >> b;
				break;
			case 6:
				cout << "Enter a, b";
				cin >> a >> b;
				break;
			case 7:
				cout << "Enter a, b";
				cin >> a >> b;
				break;
			case 8:
				cout << "Enter a, b";
				cin >> a >> b;
				break;
			case 9:
				cout << "Enter a, b";
				cin >> a >> b;
				break;
			case 10:
				cout << "Enter the constant of the Hyperbola";
				cin >> k;
				break;
			case 11:
				cout << "Enter the radius of the circle";
				cin >> k;
				break;
			default:
				cout << "WHOA, some error in this program" << endl;
				break;
			}
		}
		void calc()
		{
			switch(subchoice)
			{
				case 1:
					for(int i = -24; i < 25; i++)
					{
						int res = (a * i) + b;
						if(res < 25 && res > -24) 
						Graph[24-res][25+i] = 1;
					}
					break;
				case 2:
					for(int i = -24; i < 25; i++)
					{
						int res = a*i*i + b*i+ c;
						if(res < 25 && res > -24) Graph[24-res][i+25] = 1;
					}
					break;
				case 3:
					for(int i = -24; i < 25; i++)
					{
						int res = a*i*i*i + b*i*i+ c*i + d;
						if(res < 25 && res > -24) Graph[24-res][i+25] = 1;
					}
				case 4:
					for(int i = -24; i < 25; i++)
					{
						int res = a* log10(b*i);
						if(res < 25 && res > -24) Graph[24-res][i+25] = 1;
					}	
					break;
				default:
					cout << "we're done here";
			}
		}
		void print()
		{
			system("cls");
			for(int i = 0; i < 50; i++)
			{
				for(int j = 0 ; j < 50; j++)
				{
					if(i == 24) cout << "-";
					else if(j == 25) cout << "|";
					else
					if(Graph[i][j]==1) cout << ".";
					else cout << " ";
				}
				cout << endl;
			}
		}
};

int main()
{
	graphdrawing g;
	g.graphdrawings();
	g.print();
	system("pause");
	return 0;
}
