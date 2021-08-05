#include<bits/stdc++.h>
using namespace std;

int knapsnack (int* weight, int* value, int n, int max_knap, int** dp) {
    if (n <= 0)
    return 0;
    
    if (dp[n][max_knap] > -1) {
        return dp[n][max_knap];
    }

    int weight_at_zero = weight[0];
    int ans;
    if ( weight_at_zero <= max_knap) {
        int option1 = value[0] + knapsnack (weight + 1, value + 1, n - 1, max_knap - weight_at_zero, dp);
        int option2 = knapsnack (weight + 1, value + 1, n - 1, max_knap, dp);
        ans = max (option1, option2);
    } else {
        ans = knapsnack (weight + 1, value + 1, n - 1, max_knap, dp);
    }
    dp[n][max_knap] = ans;
    return ans;

}

int main () {
    int n;
    cin >> n;
    int* weight = new int[n];
    for (int i = 0; i < n; i++)
    cin >> weight[i];
    int* value = new int[n];
    for (int i = 0; i < n; i++)
    cin >> value[i];
    int max_knap;
    cin >> max_knap;
    int** dp = new int*[n + 1];
    for (int i = 0; i < n + 1; i++) {
        dp[i] = new int[max_knap + 1];
        for (int j = 0; j < max_knap + 1; j++)
        dp[i][j] = -1;
    }

    cout << knapsnack (weight, value, n, max_knap, dp) << endl;
}