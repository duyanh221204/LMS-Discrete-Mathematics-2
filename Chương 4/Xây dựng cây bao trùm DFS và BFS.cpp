#include<iostream>
#include<queue>
using namespace std;
int n, a[100][100], k[100];
void dfs(int x)
{
    k[x] = 1;
    for (int i = 1; i <= n; ++i)
    {
        if (a[x][i] && !k[i])
        {
            if (x <= i) cout << x << " " << i;
            else cout << i << " " << x;
            cout << "\n";
            dfs(i);
        }
    }
}
void bfs(int x)
{
    queue<int> q;
    q.push(x);
    k[x] = 1;
    while (q.size())
    {
        int m = q.front();
        q.pop();
        for (int i = 1; i <= n; ++i)
        {
            if (a[m][i] && !k[i])
            {
                if (m <= i) cout << m << " " << i;
                else cout << i << " " << m;
                cout << "\n";
                k[i] = 1;
                q.push(i);
            }
        }
    }
}
int main()
{
    int u;
    cin >> n >> u;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j) cin >> a[i][j];
    }
    cout << "DFS tree\n";
    dfs(u);
    fill(k, k + 100, 0);
    cout << "BFS tree\n";
    bfs(u);
}
