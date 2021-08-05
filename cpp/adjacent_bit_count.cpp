#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define m 1000000007

ll solve(ll n, ll k, ll first, ll ** * dp) {
    if (n == 1) {
        if (k == 0) {
            return 1;
        }
        return 0;
    }
    if (k < 0)
        return 0;
    if (dp[n][k][first] > -1)
        return dp[n][k][first];
    ll ans;
    if (first == 1) {
        ans = (solve(n - 1, k - 1, 1, dp) % m + solve(n - 1, k, 0, dp) % m) % m;
    } else {
        ans = (solve(n - 1, k, 0, dp) % m + solve(n - 1, k, 1, dp) % m) % m;
    }
    dp[n][k][first] = ans % m;
    return dp[n][k][first] % m;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        ll n, k;
        cin >> n >> k;
        ll ** * dp = new ll ** [n + 1];
        for (int i = 0; i <= n; i++) {
            dp[i] = new ll * [k + 1];
            for (int j = 0; j <= k; j++) {
                dp[i][j] = new ll[2];
                for (int l = 0; l < 2; l++)
                    dp[i][j][l] = -1;
            }
        }
        cout << (solve(n, k, 0, dp) % m + solve(n, k, 1, dp) % m) % m << endl;
    }
}