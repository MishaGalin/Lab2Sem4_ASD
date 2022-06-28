#include <iostream>
#include "generator.h"
#include "d_generator.h"
#include <fstream>
using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    ofstream input;
    input.open("input.txt");
    input << "5" << endl;
    input << "10" << endl;;
    input << "кукуруза 4 20" << endl;
    input << "огурец 3 15" << endl;
    input << "помидор 5 30" << endl;
    input << "мука 2 20" << endl;
    input << "сахар 4 25" << endl;
    BackPack a;

    a.ReadInput("input.txt");
    a.GoRecursive();

    cout << "\nDINAMIC\n" << endl;
    D_BackPack d;
    d.ReadInput("input.txt");
    d.Dinamic();
    d.Print();
    return 0;
}