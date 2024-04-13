#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main()
{
    int n, x, s = 0;
    cin >> n >> x;
    int a[n + 2][n + 2], k[n + 2] = {};
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j) cin >> a[i][j];
    }
    vector<pair<int, int>> v;
    k[x] = 1;
    while (v.size() < n - 1)
    {
        int m = 2e9, d1 = 0, d2 = 0;
        for (int i = 1; i <= n; ++i)
        {
            if (k[i])
            {
                for (int j = 1; j <= n; ++j)
                {
                    if (!k[j] && a[i][j] && a[i][j] < m)
                    {
                        m = a[i][j];
                        d1 = i, d2 = j;
                    }
                }
            }
        }
        if (d1 && d2) k[d1] = k[d2] = 1;
        s += m;
        if (d1 > d2) swap(d1, d2);
        v.push_back({d1, d2});
    }
    cout << "dH = " << s << "\n";
    for (auto& i : v) cout << i.first << " " << i.second << "\n";
}
