#include<bits/stdc++.h>
using namespace std;

bool subset_sum (int* arr, int n, int sum) {
    bool dp[n + 1][sum + 1];
    for(int i = 0; i <= sum; i++)
    dp[0][i] = false;
    for (int i = 0; i <= n; i++)
    dp[i][0] = true;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= sum; j++) {
            dp[i][j] = dp[i - 1][j];
            if ( j - arr[i - 1] >= 0) {
                dp[i][j] = dp[i - 1][j] || dp[i - 1][j - arr[i - 1]];
            }
        }
    }

    return dp[n][sum];
}

int main () {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int* arr = new int[n];
        for (int i  = 0; i < n; i++)
        cin >> arr[i];
        int sum;
        cin >> sum;
        if (subset_sum (arr, n, sum)) 
        cout << "Yes" << endl;
        else
        cout << "No" << endl;
    }
}