#include<iostream>
using namespace std;
int n, a[100][100], k[100];
void tt1(int x)
{
    k[x] = 1;
    for (int i = 1; i <= n; ++i)
    {
        if (a[x][i] && !k[i]) tt1(i);
    }
}
void tt2(int x, int y, int z)
{
    k[x] = 1;
    for (int i = 1; i <= n; ++i)
    {
        if ((x == y && i == z) || (x == z && i == y)) continue;
        if (a[x][i] && !k[i]) tt2(i, y, z);
    }
}
int main()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j) cin >> a[i][j];
    }
    int d = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (!k[i])
        {
            ++d;
            tt1(i);
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        for (int j = i + 1; j <= n; ++j)
        {
            if (a[i][j])
            {
                for (int h = 1; h <= n; ++h) k[h] = 0;
                int d1 = 0;
                for (int h = 1; h <= n; ++h)
                {
                    if (!k[h])
                    {
                        ++d1;
                        tt2(h, i, j);
                    }
                }
                if (d1 > d) cout << i << " " << j << "\n";
            }
        }
    }
}
