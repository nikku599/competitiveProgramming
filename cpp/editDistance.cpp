#include<bits/stdc++.h>
using namespace std;

int lcs (char* s1, char* s2, int m, int n, int** dp) {
    if (m == 0)
    return n;
    if (n == 0)
    return m;

    if (dp[m][n] > -1)
    return dp[m][n];

    int ans;
    if (s1[0] == s2[0]) {
        ans = lcs (s1+1, s2+1, m-1, n-1, dp); 
    }
    else {
        int option1 = 1 + lcs (s1+1, s2+1, m-1, n-1, dp);
        int option2 = 1 + lcs (s1+1, s2, m-1, n, dp);
        int option3 = 1 + lcs (s1, s2+1, m, n-1, dp);
        ans = min(option1, min(option2, option3));
    }
    dp[m][n] =  ans;
    return ans;
}


int main(){
    int t;
    cin >> t;
    while (t--) {
        char s1[100], s2[100];
        cin >> s1 >> s2;
        int m = strlen(s1);
        int n = strlen(s2);
        int** dp = new int*[m + 1];
        for (int i = 0; i <= m; i++) {
            dp[i] = new int[n + 1];
            for (int j = 0; j <= n; j++)
                dp[i][j] = -1;
        }
        cout << lcs(s1, s2, m, n, dp) << endl;
    }
    return 0;
}