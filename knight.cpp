#include <iostream>
#include <ctime>
#include <cstdlib>
#define N 8

static int dx[N] = {1, 1, 2, 2, -1, -1, -2, -2};
static int dy[N] = {2, -2, 1, -1, 2, -2, 1, -1};

bool esteInLimita(int x, int y)
{
    return ((x >= 0 && y >= 0) && (x < N && y < N));
}

bool esteGol(int tabla[N][N], int x, int y)
{
    return (esteInLimita(x, y)) && (tabla[y][x] < 0);
}

int numarVeciniGoi(int tabla[N][N], int x, int y)
{
    int count = 0;
    for (int i = 0; i < N; ++i)
        if (esteGol(tabla, (x + dx[i]), (y + dy[i])))
            count++;

    return count;
}

bool mutareUrmatoare(int tabla[N][N], int *x, int *y)
{
    int min_deg_index = -1;
    int min_deg = (N + 1);
    int c, nx, ny;
    int start = rand() % N;
    
    for (int count = 0; count < N; ++count)
    {
        int i = (start + count) % N;
        nx = *x + dx[i];
        ny = *y + dy[i];
        if ((esteGol(tabla, nx, ny)) && (c = numarVeciniGoi(tabla, nx, ny)) < min_deg)
        {
            min_deg_index = i;
            min_deg = c;
        }
    }

    if (min_deg_index == -1)
        return false;

    nx = *x + dx[min_deg_index];
    ny = *y + dy[min_deg_index];

    tabla[ny][nx] = tabla[(*y)][(*x)] + 1;

    *x = nx;
    *y = ny;

    return true;
}

void afiseaza(int tabla[N][N])
{
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
            printf("%d\t", tabla[j][i]);
        printf("\n");
    }
}

bool vecin(int x, int y, int xx, int yy)
{
    for (int i = 0; i < N; ++i)
        if (((x + dx[i]) == xx) && ((y + dy[i]) == yy))
            return true;

    return false;
}

bool gasesteTurInchis()
{
    int tabla[N][N];
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            tabla[i][j] = -1;

    int xInitial = rand() % N;
    int yInitial = rand() % N;

    int x = xInitial, y = yInitial;
    tabla[y][x] = 1;

    for (int i = 0; i < N * N - 1; ++i)
        if (mutareUrmatoare(tabla, &x, &y) == 0)
            return false;

    if (!vecin(x, y, xInitial, yInitial))
        return false;

    afiseaza(tabla);
    return true;
}

int main()
{
    srand(time(NULL));

    while (!gasesteTurInchis())
    {
        ;
    }

    return 0;
}
