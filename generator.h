#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
using namespace std;
struct item {
    int weight = 0;
    int cost = 0;
    string name = "";
};

class BackPack {
public:
    int N = 0, W = 0;
    item maxcombo;
    vector<item> Result;
    vector<item> Combinations;
    BackPack() {}
    void ReadInput(string);
    bool Algorithm(item currentItem, int index = 0, bool prinfFlag = true);
    void GoRecursive();
};