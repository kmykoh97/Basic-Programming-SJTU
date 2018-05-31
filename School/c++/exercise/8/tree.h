#ifndef TREE_H
#define TREE_H

#include <string>
#include <vector>
#include <iostream>
#include "Point.h"

using namespace std;

// template <typename T>
struct tree
{
    Point value;
    tree* left;
    tree* right;

    // destructor
    // ~tree() {delete }
};

#endif