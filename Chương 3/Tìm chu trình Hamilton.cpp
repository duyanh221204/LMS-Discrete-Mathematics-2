#include<iostream>
using namespace std;
int n, v, a[100][100], b[100], k[100];
void tt(int x)
{
    for (int i = 1; i <= n; ++i)
    {
        if (a[b[x - 1]][i])
        {
            if (x == n + 1 && i == v)
            {
                for (int j = 1; j <= n; ++j) cout << b[j] << " ";
                cout << v << "\n";
            }
            else if (!k[i])
            {
                ++k[i];
                b[x] = i;
                tt(x + 1);
                --k[i];
            }
        }
    }
}
int main()
{
    cin >> n >> v;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j) cin >> a[i][j];
    }
    b[1] = v;
    k[b[1]] = 1;
    tt(2);
}
