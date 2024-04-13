#include<iostream>
#include<vector>
#include<stack>
#include<queue>
using namespace std;
int n, s, t, s1, t1, a[100][100], k1[100], k2[100], p1[100], p2[100];
void dfs(int x)
{
    k1[x] = 1;
    for (int i = 1; i <= n; ++i)
    {
        if (a[x][i] && !k1[i]) 
        {
            p1[i] = x;
            dfs(i);
        }
    }
}
void bfs(int x)
{
    queue<int> q;
    q.push(x);
    k2[x] = 1;
    while (q.size())
    {
        int m = q.front();
        q.pop();
        for (int i = 1; i <= n; ++i)
        {
            if (a[m][i] && !k2[i])
            {
                k2[i] = 1;
                p2[i] = m;
                q.push(i);
            }
        }
    }
}
void tt1()
{
    if (!k1[t]) cout << "no path";
    else
    {
        vector<int> v;
        v.push_back(t);
        while (s != t)
        {
            t = p1[t];
            v.push_back(t);
        }
        cout << "DFS path: ";
        for (int& i : v) cout << i << " ";
    }
}
void tt2()
{
    if (k2[t1])
    {
        vector<int> v;
        v.push_back(t1);
        while (s1 != t1)
        {
            t1 = p2[t1];
            v.push_back(t1);
        }
        cout << "BFS path: ";
        for (int& i : v) cout << i << " ";
    }
}
int main()
{
    cin >> n >> s >> t;
    s1 = s, t1 = t;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j) cin >> a[i][j];
    }
    dfs(s);
    bfs(s);
    tt1();
    cout << "\n";
    tt2();
}
