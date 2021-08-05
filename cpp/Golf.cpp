
#include<bits/stdc++.h>

using namespace std;
void solve() {
    int n, x, k;
    cin >> n >> x >> k;

    string result = "NO";

    if (x % k == 0) {
        result = "YES";
    }

    if (x % k == (n + 1) % k) {
        result = "YES";
    }

    cout << result << endl;
}

int main() {

    int t;
    cin >> t;

    for (int t_i = 1; t_i <= t; t_i++) {
        solve();
    }

    return 0;
}