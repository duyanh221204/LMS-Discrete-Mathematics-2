#include<iostream>
using namespace std;
int n, a[100][100], k[100];
void tt(int x)
{
    k[x] = 1;
    for (int i = 1; i <= n; ++i)
    {
        if (a[x][i] && !k[i]) tt(i);
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
            tt(i);
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j) k[j] = 0;
        k[i] = 1;
        int d1 = 0;
        for (int j = 1; j <= n; ++j)
        {
            if (!k[j])
            {
                ++d1;
                tt(j);
            }
        }
        if (d1 > d) cout << i << " ";
    }
}
