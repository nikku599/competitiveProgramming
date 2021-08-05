#include <iostream>
#include<vector>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
#define ll long long int
vector<int> submask[22];
bool vis[1 << 22];
ll dp[1 << 22];
ll rec(int mask, int n)
{
    if (mask == (1 << (n + 1)) - 2)
        return 1;
    if (vis[mask])
        return dp[mask];
    vis[mask] = 1;
    ll &ret = dp[mask];
    ret = 0;
    int x;
    for (int i = 1; i <= n; i++)
    {
        if (!(mask & (1 << i)))
        {
            bool ok = 1;
            rep(j, submask[i].size())
            {
                x = submask[i][j];
                if (!(mask & (1 << x)))
                    ok = 0;
            }
            if (ok)
            {
                ret += rec(mask | (1 << i), n);
            }
        }
    }
    return ret;
}
int main()
{
    int n;
    for (int i = 1; i <= 20; i++)
    {
        for (int j = i - 1; j >= 1; j--)
        {
            if ((i & j) == j)
                submask[i].push_back(j);
        }
    }
    cin >> n;
    cout << rec(0, n);
}