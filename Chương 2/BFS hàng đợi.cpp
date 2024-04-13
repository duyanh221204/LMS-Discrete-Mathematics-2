#include<iostream>
#include<queue>
using namespace std;
int n, a[100][100], k[100];
void tt(int x)
{
    queue<int> q;
    int k[100] = {};
    q.push(x);
    k[x] = 1;
    while (q.size())
    {
        int m = q.front();
        q.pop();
        cout << m << " ";
        for (int i = 1; i <= n; ++i)
        {
            if (a[m][i] && !k[i]) 
            {
                k[i] = 1;
                q.push(i);
            }
        }
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
