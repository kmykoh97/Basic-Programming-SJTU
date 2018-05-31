#include <iostream>
#include <random>
#include <stack>
#include <vector>
#include "tree.h"

#define DENSITY 5

// colors for linux only(comment out for windows)
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"

using namespace std;

int width;
int height;
const int num[3] = {-1, 0, 1};

vector<stack<Point>> v1;

bool solve(tree* Tree, vector<vector<int> > maze, Point start, Point end)
{
    if (start.X == end.X && start.Y == end.Y) {
        return true;
    }

    Tree -> value = start;
    tree* temp = new tree;
    tree* temp2 = new tree;
    int randIndex = rand() % 3;
    int randNum = num[randIndex];
    // int gradient = (start.Y - end.Y) / (start.X - end.X);

    // maze[start.X][start.Y] = 2;

    int ck1, ck2;
    ck1 = randNum;
    randIndex = rand() % 3;
    randNum = num[randIndex];
    ck2 = randNum;

    do {
        randIndex = rand() % 3;
        randNum = num[randIndex];
        ck1 = randNum;
        randIndex = rand() % 3;
        randNum = num[randIndex];
        ck2 = randNum;
    } while ((start.X+ck1) < 0 || (start.X+ck1) > height-1 || (start.Y+ck2) < 0 || (start.Y+ck2) > width - 1 || maze[start.X+ck1][start.Y+ck2] == 0);

    start.X += ck1;
    start.Y += ck2;

    Tree -> left = temp;
    if (solve(Tree -> left, maze, start, end)) {
        return true;
    }
    
    ck1 = randNum;
    randIndex = rand() % 3;
    randNum = num[randIndex];
    ck2 = randNum;

    do {
        randIndex = rand() % 3;
        randNum = num[randIndex];
        ck1 = randNum;
        randIndex = rand() % 3;
        randNum = num[randIndex];
        ck2 = randNum;
    } while ((start.X+ck1) < 0 || (start.X+ck1) > height-1 || (start.Y+ck2) < 0 || (start.Y+ck2) > width - 1 || maze[start.X+ck1][start.Y+ck2] == 0);

    start.X += ck1;
    start.Y += ck2;

    Tree -> right = temp2;
    if (solve(Tree -> left, maze, start, end)) {
        return true;
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

void haha(stack<Point> S, tree* T, Point end)
{
    if (T == nullptr) {
        return;
    }

    Point temp;
    temp.X = T -> value.X;
    temp.Y = T -> value.Y;

    S.push(temp);

    if (temp == end) {
        v1.push_back(S);
    }

    haha(S, T -> left, end);
    haha(S, T -> right, end);
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

    tree* root = new tree;
    if (!solve(root, maze, end, start)) {
        cout << "no solution!" << endl;
    } else {
        haha(Stack, root, end);
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
    }
    
    system("pause");
    return 0;
}
