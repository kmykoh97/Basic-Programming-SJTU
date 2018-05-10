#include <iostream>
#include <random>
#include <stack>
#include <vector>

#define DENSITY 5

// colors for linux only(comment out for windows)
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"

using namespace std;

int width;
int height;

class Point
{
    public:
    int X;
    int Y;
    
    Point () {}

    Point (int x, int y)
    {
        X = x;
        Y = y;
    }

    Point& operator= (const Point& point)
    {
        if (this == &point) {
            return *this;
        }

        X = point.X;
        Y = point.Y;

        return *this;
    }

    bool operator== (const Point& point) const
    {
        if (X == point.X && Y == point.Y) {
            return true;
        } else {
            return false;
        }
    }

    bool operator!= (const Point& point) const
    {
        return (X != point.X || Y != point.Y);
    }
};

stack<Point> Stack;

bool solve(vector<vector<int> > maze, Point start, Point end)
{
    if (start.X == end.X && start.Y == end.Y) {
        return true;
    }

    Stack.push(start);
    Point currentLocation = Stack.top();
    Point step;

    while (!Stack.empty()) {
        currentLocation = Stack.top();

        // top
        if (currentLocation.X != 0 && maze[currentLocation.X-1][currentLocation.Y] != 2 && maze[currentLocation.X-1][currentLocation.Y] != 0) {
            step.X = currentLocation.X-1;
            step.Y = currentLocation.Y;
            if (step.X == end.X && step.Y == end.Y) {
                Stack.push(step);
                return true;
            } else {
                maze[currentLocation.X-1][currentLocation.Y] = 2;
                Stack.push(step);
                continue;
            }
        }

        // top right
        if (currentLocation.X != 0 && currentLocation.Y != width-1 && maze[currentLocation.X-1][currentLocation.Y+1] != 2 && maze[currentLocation.X-1][currentLocation.Y+1] != 0) {
            step.X = currentLocation.X-1;
            step.Y = currentLocation.Y+1;
            if (step.X == end.X && step.Y == end.Y) {
                Stack.push(step);
                return true;
            } else {
                maze[currentLocation.X-1][currentLocation.Y+1] = 2;
                Stack.push(step);
                continue;
            }
        }

        // right
        if (currentLocation.Y != width-1 && maze[currentLocation.X][currentLocation.Y+1] != 2 && maze[currentLocation.X][currentLocation.Y+1] != 0) {
            step.X = currentLocation.X;
            step.Y = currentLocation.Y+1;
            if (step.X == end.X && step.Y == end.Y) {
                Stack.push(step);
                return true;
            } else {
                maze[currentLocation.X][currentLocation.Y+1] = 2;
                Stack.push(step);
                continue;
            }
        }

        // down right
        if (currentLocation.X != height-1 && currentLocation.Y != width-1 && maze[currentLocation.X+1][currentLocation.Y+1] != 2 && maze[currentLocation.X+1][currentLocation.Y+1] != 0) {
            step.X = currentLocation.X+1;
            step.Y = currentLocation.Y+1;
            if (step.X == end.X && step.Y == end.Y) {
                Stack.push(step);
                return true;
            } else {
                maze[currentLocation.X+1][currentLocation.Y+1] = 2;
                Stack.push(step);
                continue;
            }
        }

        // down
        if (currentLocation.X != height-1 && maze[currentLocation.X+1][currentLocation.Y] != 2 && maze[currentLocation.X+1][currentLocation.Y] != 0) {
            step.X = currentLocation.X+1;
            step.Y = currentLocation.Y;
            if (step.X == end.X && step.Y == end.Y) {
                Stack.push(step);
                return true;
            } else {
                maze[currentLocation.X+1][currentLocation.Y] = 2;
                Stack.push(step);
                continue;
            }
        }

        // down left
        if (currentLocation.Y != 0 && currentLocation.X != height-1 && maze[currentLocation.X+1][currentLocation.Y-1] != 2 && maze[currentLocation.X+1][currentLocation.Y-1] != 0) {
            step.X = currentLocation.X+1;
            step.Y = currentLocation.Y-1;
            if (step.X == end.X && step.Y == end.Y) {
                Stack.push(step);
                return true;
            } else {
                maze[currentLocation.X+1][currentLocation.Y-1] = 2;
                Stack.push(step);
                continue;
            }
        }

        // left
        if (currentLocation.Y != 0 && maze[currentLocation.X][currentLocation.Y-1] != 2 && maze[currentLocation.X][currentLocation.Y-1] != 0) {
            step.X = currentLocation.X;
            step.Y = currentLocation.Y-1;
            if (step.X == end.X && step.Y == end.Y) {
                Stack.push(step);
                return true;
            } else {
                maze[currentLocation.X][currentLocation.Y-1] = 2;
                Stack.push(step);
                continue;
            }
        }

        // top left
        if (currentLocation.X != 0 && currentLocation.Y != 0 && currentLocation.X != height-1 && maze[currentLocation.X-1][currentLocation.Y-1] != 2 && maze[currentLocation.X-1][currentLocation.Y-1] != 0) {
            step.X = currentLocation.X-1;
            step.Y = currentLocation.Y-1;
            if (step.X == end.X && step.Y == end.Y) {
                Stack.push(step);
                return true;
            } else {
                maze[currentLocation.X-1][currentLocation.Y-1] = 2;
                Stack.push(step);
                continue;
            }
        }
        
        Stack.pop();
    }

    return false;
}

vector<vector<int> > generate(int width, int height)
{
    mt19937 rng;
    rng.seed(random_device()());

    default_random_engine fixed;
    uniform_int_distribution<int> distribution(0, 9);

    vector<vector<int> > maze(height, vector<int>(width));
    for (int i = 0; i < height; i++) {
        for(int j = 0; j < width; j++) {
            maze[i][j] = distribution(fixed) < DENSITY ? 1 : 0;
        }
    }

    return maze;
}

int main()
{
    cout<<"Please input the width:";
    cin>>width;
    cout<<"Please input the height:";
    cin>>height;

    mt19937 rng;
    rng.seed(random_device()());
    uniform_int_distribution<int> distribution(0, 9);

    vector<vector<int> > maze = generate(width, height);

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (maze[i][j] == 1) {
                cout << YELLOW << maze[i][j];
            } else {
                cout << RED << maze[i][j];
            }
        }
        cout << endl;
    }

    int startPointX, startPointY, endPointX, endPointY;
    cout << "please insert start and end points (X1, Y1, X2, Y2): ";
    cin >> startPointX >> startPointY >> endPointX >> endPointY;
    cout << endl;

    Point start{startPointX, startPointY};
    Point end{endPointX, endPointY};

    if (!solve(maze, end, start)) {
        cout << "no solution!" << endl;
    } else {
        while (!Stack.empty()) {
            int x = Stack.top().X;
            int y = Stack.top().Y;
            Stack.pop();
            maze[x][y] = 2;
        }

        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                if (maze[i][j] == 1) {
                    cout << YELLOW << maze[i][j];
                } else if (maze[i][j] == 2) {
                    cout << GREEN << maze[i][j];
                } else {
                    cout << RED << maze[i][j];
                }
            }
            cout<<endl;
        }
    }
    
    system("pause");
    return 0;
}
