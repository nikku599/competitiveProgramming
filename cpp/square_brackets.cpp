#include<bits/stdc++.h>
using namespace std;
#define m 1000000007

int solve (int o, int c, int n, bool* arr, int** dp) {

    if (o > n || c > n)
    return 0;
    if (o == n && c == n)
    return 1;
    if (dp[o][c] > -2) {
        return dp[o][c] % m;
    }
    
    int current_index = o + c;
    int ans;

    if (o == c || arr[current_index]) {
        ans = solve (o + 1, c, n, arr, dp);
    } else if (o == n) {
        ans = solve (o, c + 1, n, arr, dp);
    } else {
        int option1 = solve (o + 1, c, n, arr, dp);
        int option2 = solve (o, c + 1, n, arr, dp);
        ans = (option1 % m + option2 % m) % m;
    }
    dp[o][c] = ans;
    return dp[o][c] % m;
}

int main () {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        bool* arr = new bool[(2 * n) + 1];
        for (int i = 0; i <= 2 * n; i++)
            arr[i] = false;
        for (int i = 0; i < k; i++) {
            int x;
            cin >> x;
            arr[x - 1] = true;
        }
        int** dp = new int*[n + 1];
        for (int i = 0; i < n + 1; i++) {
            dp[i] = new int[n + 1];
            for(int j = 0; j < n + 1; j++)
                dp[i][j] = -2;
        }
        int o = 0, c = 0;
        cout << solve (o, c, n, arr, dp) << endl;
        // solve (o, c, n, arr, dp);

    }
}