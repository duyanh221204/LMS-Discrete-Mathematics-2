#include<iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int a[n + 2][n + 2], p[n + 2][n + 2] = {};
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            cin >> a[i][j];
            if (!a[i][j] && i != j) a[i][j] = 1e9;
            p[i][j] = j;
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            for (int k = 1; k <= n; ++k)
            {
                if (a[j][i] + a[i][k] < a[j][k])
                {
                    a[j][k] = a[j][i] + a[i][k];
                    p[j][k] = p[j][i];
                }
            }
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            cout << "K/c " << i << " -> " << j << " = ";
            if (i == j) cout << "0; " << i;
            else
            {
                cout << a[i][j] << "; ";
                int x = i;
                while (x != j)
                {
                    cout << x << " -> ";
                    x = p[x][j];
                }
                cout << j;
            }
            cout << "\n";
        }
        cout << "\n";
    }
}
