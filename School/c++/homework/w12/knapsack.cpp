#include <vector>
#include <iostream>
#include <string>

using namespace std;

struct Object
{
    string name;
    double value;
    double weight;
};

int fillKnapsack(vector<Object>& objects, double value, double weight)
{
    if (weight < 0) {
        return 0;
    }

    double bestScore = 0;

    for (int i = 0; i < objects.size(); i++) {
        Object tempObject = objects[i];
        double tempValue = value + objects[i].value;
        double tempWeight = weight - objects[i].weight;

        objects.erase(objects.begin()+i, objects.begin()+i+1);

        tempValue = fillKnapsack(objects, tempValue, tempWeight); // recursive

        if (bestScore < tempValue) {
            bestScore = tempValue;
        }

        objects.insert(objects.begin()+i, tempObject);
    }

    return bestScore;
}

int main()
{
    // declarations (name, value, weight)
    Object o1{"a", 3, 9};
    Object o2{"b", 4, 10};
    Object o3{"c", 2.2, 10};
    Object o4{"d", 3.1, 9.5};

    vector<Object> objects = {o1, o2, o3, o4};

    int answer = fillKnapsack(objects, 0, 20);

    cout << answer << endl;

    system("pause");
    return 0;
}