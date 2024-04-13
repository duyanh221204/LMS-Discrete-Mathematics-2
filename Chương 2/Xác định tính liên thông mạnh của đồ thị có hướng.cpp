#include<iostream>
using namespace std;
int n, k[100], a[100][100];
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
        for (int j = 1; j <= n; ++j) k[j] = 0;
        tt(i);
        for (int j = 1; j <= n; ++j)
        {
            if (!k[j])
            {
                d = 1;
                cout << "not strongly connected";
                break;
            }
        }
        if (d) break;
    }
    if (!d) cout << "strongly connected";
}
