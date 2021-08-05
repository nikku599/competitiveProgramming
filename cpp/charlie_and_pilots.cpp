#include<bits/stdc++.h>
using namespace std;

int solve (int* c, int* a, int n, int x, int** dp) {
    if (n == 0)
    return 0;

    if (dp[n][x] > -1) 
        return dp[n][x];

    if (x == 0)
    return a[0] + solve (c + 1, a + 1, n - 1, 1, dp);

    if (x == n)
    return c[0] + solve (c + 1, a + 1, n - 1, x - 1, dp);

    int option1 = a[0] + solve (c + 1, a + 1, n - 1, x + 1, dp);
    int option2 = c[0] + solve (c + 1, a + 1, n - 1, x - 1, dp);

    dp[n][x] = min (option1, option2);
    return dp[n][x];
}

int main () {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int c[n], a[n];
        for (int i = 0; i < n; i++)
            cin >> c[i] >> a[i];
        
        int** dp = new int*[n + 1];
        for (int i = 0; i < n + 1; i++) {
            dp[i] = new int[n + 1];
            for (int j = 0; j < n + 1; j++)
                dp[i][j] = -1;
        }
        
        int x = 0;
        cout << solve (c, a, n, x, dp) << endl;

    }
}