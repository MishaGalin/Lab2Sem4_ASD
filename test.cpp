#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "Generator.h"
#include "D_Generator.h"
#include <vector>

TEST_CASE("Check algoritm", "[backpack]") {
    setlocale(LC_ALL, "Russian");
    ofstream BP;
    BP.open("BP.txt");
    BP << "5" << endl;
    BP << "10" << endl;;
    BP << "�������� 4 20" << endl;
    BP << "������ 3 15" << endl;
    BP << "������� 5 30" << endl;
    BP << "���� 2 20" << endl;
    BP << "����� 4 25" << endl;
    item MaxInput;
    MaxInput.name = " ������ ������� ����";
    MaxInput.weight = 10;
    MaxInput.cost = 65;
    BackPack a;
    a.ReadInput("BP.txt");
    a.GoRecursive();
    REQUIRE(MaxInput.name == a.maxcombo.name);
    REQUIRE(MaxInput.weight == a.maxcombo.weight);
    REQUIRE(MaxInput.cost == a.maxcombo.cost);
}

TEST_CASE("Check dinamic algoritm", "[dinamic backpack]") {
    setlocale(LC_ALL, "Russian");
    ofstream DBP;
    DBP.open("DBP.txt");
    DBP << "5" << endl;
    DBP << "10" << endl;;
    DBP << "�������� 4 20" << endl;
    DBP << "������ 3 15" << endl;
    DBP << "������� 5 30" << endl;
    DBP << "���� 2 20" << endl;
    DBP << "����� 4 25" << endl;
    vector<int> MaxInput{0,0};
    MaxInput[0] = 10;
    MaxInput[1] = 65;
    D_BackPack d;
    d.ReadInput("DBP.txt");
    d.Dinamic();
    d.Print();
    REQUIRE(MaxInput[0] == d.MAX[0]);
    REQUIRE(MaxInput[1] == d.MAX[1]);
}
