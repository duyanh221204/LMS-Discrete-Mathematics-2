#include<iostream>
#include<vector>
#include<utility>
using namespace std;
int main()
{
    int n, s;
    cin >> n >> s;
    int a[n + 2][n + 2], d[n + 2] = {}, p[n + 2] = {};
    vector<pair<int, pair<int, int>>> v;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            cin >> a[i][j];
            if (a[i][j]) v.push_back({i, {j, a[i][j]}});
        }
    }
    fill(d + 1, d + n + 1, 2e9);
    d[s] = 0;
    for (int i = 1; i < n; ++i)
    {
        for (auto& j : v)
        {
            if (d[j.first] + j.second.second < d[j.second.first])
            {
                d[j.second.first] = d[j.first] + j.second.second;
                p[j.second.first] = j.first;
            }
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        cout << "K/c " << s << " -> " << i << " = ";
        if (s == i) cout << "0; " << s << " <- " << i;
        else if (d[i] == 2e9) cout << "INF;\n";
        else
        {
            cout << d[i] << "; ";
            int x = i;
            vector<int> v;
            while (x != s)
            {
                v.push_back(x);
                x = p[x];
            }
            v.push_back(s);
            for (int j = 0; j < v.size(); ++j)
            {
                cout << v[j];
                if (j < v.size() - 1) cout << " <- ";
            }
        }
        cout << "\n";
    }
}
