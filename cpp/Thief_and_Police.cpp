#include<bits/stdc++.h>
using namespace std;

int police (int** dp, int i, int j, int m, int n) {
    if (i >= m || j >= n) {
        return 1;
    }
    if(dp[i][j] > -1)
    return dp[i][j];

    int ans;
    int option1 = 1 + police (dp, i+1, j, m , n);
    int option2 = 1 + police (dp, i, j + 1, m , n);
    int option3 = 1 + police (dp, i+1, j+1, m, n);
    ans = min(option1, min(option2, option3));

    dp[i][j] = ans;
    return ans;
}

int main () {
    int t;
    cin >> t;
    while (t--) {
        int r, c;
        cin >> r >> c;
        int x, y;
        cin >> x >> y;

        int** dp = new int*[r];
        for(int i = 0; i < r; i++){
            dp[i] = new int[c];
            for(int j = 0; j < c; j++)
            dp[i][j] = -1;
        }

        cout << police (dp, x-1, y-1, r-1, c-1) << endl;
    }
}