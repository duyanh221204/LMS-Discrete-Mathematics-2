#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int a[n + 2][n + 2], k[n + 2] = {};
    vector<pair<int, pair<int, int>>> v;
    vector<pair<int, int>> vp;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            cin >> a[i][j];
            if (i < j && a[i][j]) v.push_back({a[i][j], {i, j}}); 
        }
    }
    sort(v.begin(), v.end());
    int s = 0;
    for (auto& i : v)
    {
        if (!k[i.second.first] || !k[i.second.second])
        {
            s += i.first;
            vp.push_back({i.second.first, i.second.second});
            k[i.second.first] = k[i.second.second] = 1;
        }
    }
    cout << "dH = " << s << "\n";
    for (auto& i : vp) cout << i.first << " " << i.second << "\n";
}
