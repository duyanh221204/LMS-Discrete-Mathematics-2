#include<iostream>
#include<stack>
#include<queue>
#include<vector>
#include<utility>
using namespace std;
int main()
{
    int n, s;
    cin >> n >> s;
    int a[n + 2][n + 2], d[n + 2] = {}, k[n + 2] = {}, par[n + 2] = {};
    vector<vector<pair<int, int>>> vp(n + 2);
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            cin >> a[i][j];
            if (a[i][j]) vp[i].push_back({j, a[i][j]});
        }
    }
    fill(d + 1, d + n + 1, 2e9);
    d[s] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.push({0, s});
    while (pq.size())
    {
        pair<int, int> p = pq.top();
        pq.pop();
        if (!k[p.second])
        {
            k[p.second] = 1;
            for (auto& i : vp[p.second])
            {
                if (d[p.second] + i.second < d[i.first])
                {
                    d[i.first] = d[p.second] + i.second;
                    par[i.first] = p.second;
                    pq.push({d[i.first], i.first});
                }
            }
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        cout << "K/c " << s << " -> " << i << " = ";
        if (s == i)
        {
            cout << "0; " << s << " -> " << i;
        }
        else if (d[i] == 2e9) cout << "INF;";
        else
        {
            cout << d[i] << "; ";
            int x = i;
            vector<int> v;
            while (x != s)
            {
                v.push_back(x);
                x = par[x];
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
