#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define m 1000000007

const int MAX_CHAR = 256;

int main () {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        ll n = s.size();

        ll dp[n + 1];
        dp[0] = 1;
        vector <ll> last (MAX_CHAR, -1);
        for (int i = 1; i <= n; i++) {
            dp[i] = ((dp[i - 1] % m) * 2) % m;

            if (last[s[i - 1]] != -1) {
                dp[i] = (dp[i] % m - dp[last[s[i - 1]]] % m) % m;
            }
            last[s[i - 1]] = (i % m - 1) % m;
        }

        cout << dp[n] % m << endl;
    }
}