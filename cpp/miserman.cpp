#include<bits/stdc++.h>
using namespace std;

int solve (int** grid,int n, int m)
{
    int dp[n][m];
    for (int i = 0; i < m; i++)
        dp[0][i] = grid[0][i];
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int left, right, down;
            left = (j > 0) ? dp[i - 1][j - 1] : INT_MAX;
            right = (j < m - 1) ? dp[i - 1][j + 1] : INT_MAX;
            down = dp[i - 1][j];
            dp[i][j] = grid[i][j] + min (left, min (right, down));
        }
    }
    int result = INT_MAX;
    for (int i = 0; i < m; i++)
        if (dp[n - 1][i] < result)
            result = dp[n - 1][i];
    return result;
}

int main ()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        int** grid = new int*[n];
        for (int i = 0; i < n; i++)
            grid[i] = new int[m];
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> grid[i][j];
        cout << solve (grid,n , m) << endl;
    }
}