#include<bits/stdc++.h>
using namespace std;

int get_trader_profit (int* arr,int n, int k, int ongoing_transaction, int*** dp) {
    
    if (n == 0 || k == 0)
    return 0;

    if (dp[n][k][ongoing_transaction] > -1) {
        return dp[n][k][ongoing_transaction];
    }

    int ignore_option = INT_MIN;
    ignore_option = get_trader_profit (arr + 1, n - 1, k, ongoing_transaction, dp);
    int buy_option = INT_MIN, sell_option = INT_MIN;
    if (!ongoing_transaction) {
        if (k > 0)
        buy_option = get_trader_profit (arr + 1, n - 1, k, 1, dp) - arr[0];
    } else {
        sell_option = get_trader_profit (arr + 1, n - 1, k - 1, 0 , dp) + arr[0];
    }

    dp[n][k][ongoing_transaction] = max (ignore_option, max (buy_option, sell_option));

    return dp[n][k][ongoing_transaction];
}

int main () {
    int t;
    cin >> t;
    while (t--) {
        int k, n;
        cin >> k >> n;
        int* arr = new int[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        int*** dp = new int**[n + 1];
        for (int i = 0; i < n + 1; i++) {
            dp[i] = new int*[k + 1];
            for(int j = 0; j < k + 1; j++) {
                dp[i][j] = new int[2];
                for(int l = 0; l < 2; l++) {
                    dp[i][j][l] = -1;
                }
            }
        }


        int ongoing_transaction = 0;
        cout << get_trader_profit (arr, n, k, ongoing_transaction, dp) << endl;
    }
}