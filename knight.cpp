#include <iostream>

using namespace std;

int Matrix[8][8] = {0};
int x[8] = {2, 1, -1, -2, -2, -1, 1, 2};
int y[8] = {1, 2, 2, 1, -1, -2, -2, -1};

int este_valid(int i, int j)
{
    return (i >= 0 && i < 8 && j >= 0 && j < 8 && Matrix[i][j] == -1);
}

void initializare_matrice()
{
    for(int i = 0; i < 8; i++)
        for(int j = 0; j < 8; j++)
            Matrix[i][j] = -1;
}

void afisare_matrice()
{
    for (int i = 0; i < 8; i++)
    {
        cout << "|";
        for (int j = 0; j < 8; j++)
            cout << Matrix[i][j] << "|";
        cout << "\n";
    }
    cout << "\n\n\n";
}

int knights_tour(int m, int n, int contor)
{
    if (contor == 64)
    {
        afisare_matrice();
        return 1;
    }

    for (int i = 0; i < 8; i++)
    {
        int poz_i = m + x[i];
        int poz_j = n + y[i];
        if (este_valid(poz_i, poz_j))
        {
            Matrix[poz_i][poz_j] = contor;
            if (knights_tour(poz_i, poz_j, contor + 1))
            {
                return 1;
            }
            else
            {
                Matrix[poz_i][poz_j] = -1;
            }
        }
    }
    return 0;
}

int main()
{
    int i, j;
    initializare_matrice();

    cout << "Scrieti pozitia de pe care vreti sa incepeti: \n i(0-7): ";
    cin >> i;
    cout << "j(0-7): ";
    cin >> j;
    Matrix[i][j] = 0;
    knights_tour(i, j, 1);
    afisare_matrice();
    return 0;
}
