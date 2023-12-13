#include <iostream>

using namespace std;

int Matrix[8][8]={0};
int x[8]={2, 1, -1, -2, -2, -1, 1, 2};
int y[8]={1, 2, 2, 1, -1, -2, -2, -1};
int contor=0;

int este_valid(int i, int j)
{
     if(i >= 0 && i < 8 && j >= 0 && j < 8 && Matrix[i][j]==0)
        return 1;
    return 0;
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
    cout<<"\n\n\n";
}

int knights_tour(int m, int n, int contor)
{
    int i;

    for(i=0; i<8; i++)
    {
        if(contor >= 65)
            return 1;

        int poz_i=m+x[i];
        int poz_j=n+y[i];
        if(este_valid(poz_i, poz_j))
        {
            Matrix[poz_i][poz_j]=contor;
            afisare_matrice();
            if(knights_tour(poz_i, poz_j, contor+1))
                {
                    return 1;
                }
            Matrix[poz_i][poz_j]=0;
        }
    }
    return 0;
}



int main()
{
    knights_tour(3, 3, 0);

    return 0;
}