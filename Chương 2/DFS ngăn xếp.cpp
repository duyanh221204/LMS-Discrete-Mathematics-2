#include<iostream>
#include<vector>
#include<stack>
using namespace std;
int n, a[100][100], k[100];
void tt(int x)
{
    vector<int> v;
    stack<int> st;
    st.push(x);
    k[x] = 1;
    v.push_back(x);
    while (st.size())
    {
        int m = st.top();
        st.pop();
        for (int i = 1; i <= n; ++i)
        {
            if (a[m][i] && !k[i])
            {
                st.push(m);
                st.push(i);
                v.push_back(i);
                k[i] = 1;
                break;
            }
        }
    }
    for (int& i : v) cout << i << " ";
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
