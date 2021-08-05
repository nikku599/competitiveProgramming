#include<bits/stdc++.h>
using namespace std;

int solve (char* s1, char* s2, int n1, int n2, int** dp) {
    //s1 is empty
    if (n1 == 0)
    return 500;
    //s2 is empty
    if (n2 <= 0)
    return 1;

    if (dp[n1][n2] > -1)
    return dp[n1][n2];

    int index;
    for (index = 0; index < n2; index++) {
        if (s1[0] == s2[index])
        break;
    }
    //if index not found in s2
    if (index == n2)
    return 1;
    int ans;
    int option1 = solve (s1 + 1, s2, n1 - 1, n2, dp);
    int option2 = 1 + solve (s1 + 1, s2 + index + 1, n1 - 1, n2 - (index + 1), dp);

    ans = min (option2, option1);

    dp[n1][n2] = ans;
    return ans;

}

int main () {
    string s1, s2;
    cin >> s1 >> s2;
    int n1, n2;
    n1 = s1.size();
    n2 = s2.size();
    char* str1 = new char[n1 + 1];
    char* str2 = new char[n2 + 1];
    strcpy (str1, s1.c_str());
    strcpy (str2, s2.c_str());

    int** dp = new int*[n1 + 1];
    for (int i =0; i <= n1; i++) {
        dp[i] = new int[n2 + 1];
        for (int j = 0; j <= n2; j++)
            dp[i][j] = -1;
    }

    cout << solve (str1, str2, n1, n2, dp) << endl;
}