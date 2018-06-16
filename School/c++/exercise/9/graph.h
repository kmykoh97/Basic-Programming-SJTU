#include <set>
#include <vector>
#include <string>

using namespace std;

struct Node
{
    string value;
    vector<Edge *> edges;
};

struct Edge
{
    Node* start;
    Node* end;
};

struct Graph
{
    set<Node*> nodes;
    set<Edges*> edges;
};