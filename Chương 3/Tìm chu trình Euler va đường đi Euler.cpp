#include<iostream>
#include<stack>
using namespace std;
int main()
{
    int n, v, a[100][100] = {}, k[100] = {};
    cin >> n >> v;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j) cin >> a[i][j];
    }
    stack<int> st1, st2;
    st1.push(v);
    while (st1.size())
    {
        int d = 0, m = st1.top();
        for (int i = 1; i <= n; ++i)
        {
            if (a[m][i])
            {
                d = 1;
                a[m][i] = a[i][m] = 0;
                st1.push(i);
                break;
            }
        }
        if (!d)
        {
            st1.pop();
            st2.push(m);
        }
    }
    while (st2.size())
    {
        cout << st2.top() << " ";
        st2.pop();
    }
}
