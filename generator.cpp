#include "Generator.h"

void BackPack::ReadInput(string dir)
{
    ifstream input(dir);
    cout << "Start input\n" << endl;
    if (input.is_open())
        cout << "Input file is open" << endl;
    else {
        cout << "Input file is not open" << endl;
        exit(0);
    }
    input >> N >> W;
    cout << "N = " << N << "\n" << "W = " << W << endl;
    vector<item> Res(N);
    for (int i = 0; i < N; i++) {
        input >> Res[i].name >> Res[i].weight >> Res[i].cost;
        cout << Res[i].name << " " << Res[i].weight << " " << Res[i].cost << endl;
    }
    Result = Res;
    cout << "\nEnd input\n" << endl;
}

bool BackPack::Algorithm(item currentItem, int index, bool print)
{
    if (index == N) // если дошли до последнего предмета
    {

            Combinations.push_back(currentItem);
            if (print == true && currentItem.name!="")
                cout << currentItem.name << " " << currentItem.weight << " " << currentItem.cost << endl;
            return false;
    }

    if (currentItem.weight + Result[index].weight <= W) { // если уже имеющиеся предметы + рассматриваемый вмещаются
        item tmp;
        tmp = currentItem;
        tmp.name += " " + Result[index].name;
        tmp.weight += Result[index].weight;
        tmp.cost += Result[index].cost;
        Algorithm(tmp, index + 1, print); // добавляем и смотрим дальше уже с этим предметом
    }
    Algorithm(currentItem, index + 1, print); // отбрасываем этот вариант и смотрим другой предмет
}

void BackPack::GoRecursive()
{
    cout << "\nOutput of combinations\n" << endl;
    item combo;
    combo.name = "";
    combo.weight = 0;
    combo.cost = 0;
    Algorithm(combo);
    maxcombo.name = "";
    maxcombo.weight = 10;
    maxcombo.cost = 0;
    for (auto i : Combinations) {
        if (i.cost >= maxcombo.cost)
        {
            maxcombo.name = i.name;
            maxcombo.weight = i.weight;
            maxcombo.cost = i.cost;
        }
    }
    cout << "\nThe best option: " << maxcombo.name << " " << maxcombo.weight << " " << maxcombo.cost << "\n" << endl;
}