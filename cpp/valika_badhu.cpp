#include <bits/stdc++.h>

using namespace std;

int solve(char * s1, char * s2, int i, int j, int k, int n1, int n2, int *** dp) {
    if (k == 0) {
        return 0;
    }
    if (i > n1 - 1 || j > n2 - 1) {
        return INT_MIN;
    }
    if (dp[i][j][k] != '$') {
        return dp[i][j][k];
    }
    int ans;
    if (s1[i] == s2[j]) {
        ans = max(solve(s1, s2, i + 1, j + 1, k, n1, n2, dp), solve(s1, s2, i + 1, j + 1, k - 1, n1, n2, dp) + s1[i]);
    } else {
        int option2 = solve(s1, s2, i + 1, j, k, n1, n2, dp);
        int option3 = solve(s1, s2, i, j + 1, k, n1, n2, dp);
        ans = max(option2, option3);
    }
    dp[i][j][k] = ans;
    
    return dp[i][j][k];

}

int main() {
    int t;
    cin >> t;
    while (t--) {
        char * s1 = new char[101];
        char * s2 = new char[101];
        cin >> s1 >> s2;
        int k;
        cin >> k;
        int n1, n2;
        n1 = strlen(s1);
        n2 = strlen(s2);

        int *** dp = new int ** [n1 + 1];
        for (int i = 0; i <= n1; i++) {
            dp[i] = new int * [n2 + 1];
            for (int j = 0; j <= n2; j++) {
                dp[i][j] = new int[k + 1];
                for (int l = 0; l <= k; l++)
                    dp[i][j][l] = '$';
            }
        }
        int result = solve(s1, s2, 0, 0, k, n1, n2, dp);
        if (result < 0)
        cout << 0 << endl;
        else
        cout << result << endl;
    }
}