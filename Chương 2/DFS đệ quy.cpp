#include<iostream>
using namespace std;
int n, a[100][100], k[100];
void tt(int x)
{
    k[x] = 1;
    cout << x << " ";
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
    tt(1);
}
