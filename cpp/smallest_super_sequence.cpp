#include<bits/stdc++.h>

using namespace std;

int solve(char * s1, char * s2, int n1, int n2, int ** dp) {
    if (n1 == 0)
        return n2;
    if (n2 == 0)
        return n1;
    if (dp[n1][n2] > -1)
    return dp[n1][n2];
    int ans;
    if (s1[0] == s2[0])
        ans = 1 + solve(s1 + 1, s2 + 1, n1 - 1, n2 - 1, dp);
    else {
        ans = 1 + min(solve(s1 + 1, s2, n1 - 1, n2, dp), solve(s1, s2 + 1, n1, n2 - 1, dp));
    }
    dp[n1][n2] = ans;
    return dp[n1][n2];
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s1, s2;
        cin >> s1 >> s2;
        int n1, n2;
        n1 = s1.length();
        n2 = s2.length();
        char * str1 = new char[n1 + 1];
        strcpy(str1, s1.c_str());
        char * str2 = new char[n2 + 1];
        strcpy(str2, s2.c_str());
        int ** dp = new int * [n1 + 1];
        for (int i = 0; i <= n1; i++) {
            dp[i] = new int[n2 + 1];
            for (int j = 0; j <= n2; j++) {
                dp[i][j] = -1;
            }
        }

        cout << solve(str1, str2, n1, n2, dp) << endl;
    }
}