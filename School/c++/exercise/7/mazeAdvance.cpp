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

vector<stack<Point>> v1;

vector<vector<int> > generate(int width, int height);
bool solve(vector<vector<int> > maze, Point start, Point end);

bool solver(vector<vector<int>> maze, int x1, int y1, int x2, int y2, int count, stack<Point> Stack)
{
    Point point;

    if (count > (width + height) * 0.6) {
        return false;
    }

    if (x1 == x2 && y1 == y2){
        point.X = x1;
        point.Y = y1;
        Stack.push(point);
        v1.push_back(Stack);
		return true;
	}
    
    if (x1 == -1 || x1 == width || y1 == -1 || y1 == height) {
		return false;
	} else if (maze[x1][y1] == 2 || maze[x1][y1] == 0) {
        return false;
    } else {
		
        maze[x1][y1] = 2;
        point.X = x1;
        point.Y = y1;
        Stack.push(point);

        solver(maze, x1-1, y1, x2, y2, count+1, Stack);
        solver(maze, x1, y1+1, x2, y2, count+1, Stack);
        solver(maze, x1+1, y1, x2, y2, count+1, Stack);
        solver(maze, x1, y1-1, x2, y2, count+1, Stack);
        solver(maze, x1+1, y1+1, x2, y2, count+1, Stack);
        solver(maze, x1+1, y1-1, x2, y2, count+1, Stack);
        solver(maze, x1-1, y1+1, x2, y2, count+1, Stack);
        solver(maze, x1-1, y1-1, x2, y2, count+1, Stack);

        if (v1.size() > 0) {
		    return true;
        }

        return false;
    }
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
    stack<Point> Stack;

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (maze[i][j] == 1) {
                cout << maze[i][j];
            } else {
                cout << maze[i][j];
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

    int x1, y1, x2, y2;
    x1 = start.X;
    y1 = start.Y;
    x2 = end.X;
    y2 = end.Y;

    if (!solver(maze, x1, y1, x2, y2, 0, Stack)) {
        cout << "no solution!" << endl;
    } else {
        cout << "all possible solutions: " << endl;
        for (int k = 0; k < v1.size(); k++) {
            vector<vector<int>> mazeDuplicate = maze;

            while (!v1[k].empty()) {
                int x = v1[k].top().X;
                int y = v1[k].top().Y;
                v1[k].pop();
                mazeDuplicate[x][y] = 2;
            }

            for (int i = 0; i < height; i++) {
                for (int j = 0; j < width; j++) {
                    if (mazeDuplicate[i][j] == 1) {
                        cout << mazeDuplicate[i][j];
                    } else if (mazeDuplicate[i][j] == 2) {
                        cout << mazeDuplicate[i][j];
                    } else {
                        cout << mazeDuplicate[i][j];
                    }
                }
                cout << endl;
            }
            cout << endl;
        }

        cout << "shortest 3: " << endl;
        stack<Point> s1;
        stack<Point> s2;
        stack<Point> s3;
        if (v1.size() >= 3) {
             s1 = v1[1];
             s2 = v1[2];
             s3 = v1[0];
        } else {cout << "not enough solution!" << endl;}
        if (v1.size() > 3) {
            for (int k = 3; k < v1.size(); k++) {
                if (v1[k].size() <= s1.size() && s1.size() > s2.size() && s1.size() > s3.size()) {
                    s1 = v1[k];
                }

                if (v1[k].size() <= s2.size() && s2.size() > s1.size() && s2.size() > s3.size()) {
                    s2 = v1[k];
                }

                if (v1[k].size() <= s3.size() && s3.size() > s2.size() && s3.size() > s1.size()) {
                    s3 = v1[k];
                }
            }
        }

        // print
        vector<vector<int>> mazeDuplicate = maze;
        while (!s1.empty()) {
            int x = s1.top().X;
            int y = s1.top().Y;
            s1.pop();
            mazeDuplicate[x][y] = 2;
        }

        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                if (maze[i][j] == 1) {
                    cout  << maze[i][j];
                } else if (maze[i][j] == 2) {
                    cout  << maze[i][j];
                } else {
                    cout  << maze[i][j];
                }
            }
            cout<<endl;
        }
        cout << endl;

        mazeDuplicate = maze;
        while (!s2.empty()) {
            int x = s2.top().X;
            int y = s2.top().Y;
            s2.pop();
            mazeDuplicate[x][y] = 2;
        }

        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                if (maze[i][j] == 1) {
                    cout  << maze[i][j];
                } else if (maze[i][j] == 2) {
                    cout  << maze[i][j];
                } else {
                    cout  << maze[i][j];
                }
            }
            cout<<endl;
        }
        cout << endl;


        mazeDuplicate = maze;
        while (!s3.empty()) {
            int x = s3.top().X;
            int y = s3.top().Y;
            s3.pop();
            mazeDuplicate[x][y] = 2;
        }

        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                if (maze[i][j] == 1) {
                    cout  << maze[i][j];
                } else if (maze[i][j] == 2) {
                    cout  << maze[i][j];
                } else {
                    cout  << maze[i][j];
                }
            }
            cout<<endl;
        }
        cout << endl;
    }

    system("pause");
    return 0;
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