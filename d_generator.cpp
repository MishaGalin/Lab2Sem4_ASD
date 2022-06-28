#include "D_Generator.h"

void D_BackPack::ReadInput(string dir)
{
    ifstream input(dir);
    cout << "Start input\n" << endl;
    if (input.is_open())
        cout << "File is open" << endl;
    else {
        cout << "File is not open" << endl;
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

void D_BackPack::Dinamic()
{
    vector<int> Q; // заполнение нулями
    for (int i = 0; i <= N; i++)
    {
        for (int j = 0; j <= W; j++)
            Q.push_back(0);
        Combinations.push_back(Q);
    }

    for (int k = 1; k <= N; k++)
    {
        for (int s = 1; s <= W; s++)
        {
            Combinations[k][s] = Combinations[k - 1][s];
            if (s >= Result[k - 1].weight)
                Combinations[k][s] = max(Combinations[k][s], Combinations[k][s - Result[k - 1].weight] + Result[k - 1].cost); // максимум между ценой следующего предмета и ценой рассматриваемой комбинации + цена следющего предмета
        }
    }
}

void D_BackPack::find(int n, int w)
{
    if (Combinations[n][w] == 0)
        return;
    if (Combinations[n - 1][w] == Combinations[n][w])
        find(n - 1, w); // сдивгаемся к другому предмету
    else {
        MAX[0] += Result[n - 1].weight;
        MAX[1] += Result[n - 1].cost;
        z += Result[n - 1].name + " ";
        find(n, w - Result[n - 1].weight); // сдвигаемся по таблице к другому предмету и влево на значение веса
    }
}

void D_BackPack::Print() 
{
    cout << "\nOutput of combinations\n" << endl;
    for (int i = 1; i <= N; i++)
    {
        cout << "K = " << i << " : ";
        for (int j = 0; j <= W; j++)
        {
            cout << Combinations[i][j] << " ";
        }
        cout << endl;
    }
    find(N, W);
    cout << "\nThe best option: " << z << "   " << MAX[0] << " " << MAX[1] << " " << endl;
}