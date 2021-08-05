#include<bits/stdc++.h>
using namespace std;

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
    for (int i = 0; i <= n; i++) {
        dp[i] = new int[max_knap + 1];
    }
    for (int i = 0; i <= n; i++)
        dp[i][0] = 0;
    for (int i = 0; i <= max_knap; i++)
        dp[0][i] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= max_knap; j++) {
            dp[i][j] = dp[i - 1][j];
            if (weight[i - 1] <= j) {
                dp[i][j] = max (dp[i][j], value[i - 1] + dp[i - 1][j - weight[i - 1]]);
            }
        }
    }
    int result = dp[n][max_knap];
    int count = 0;
    for (int i = 0; i <= max_knap; i++) {
        if (dp[n][i] == result) {
            count = i;
            break;
        }
    }
    cout << count << " " << result << endl;
}