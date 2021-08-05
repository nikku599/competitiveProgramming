#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define m 1000000007

string heaven (string s, ll n) {
    if (n == 1) {
        if (s[0] == '0')
        return "NO";
        else
        return "YES";
    }
    ll zero = 0, one = 0;
    double per;
    for (int i = 0; i < n; i++) {
        if (s[i] == '0')
        zero++;
        else 
        one++;
        per = ((one % m * 100) % m / (i + 1) % m ) % m;
        if (per >= 50) {
            return "YES";
        }
    }
    return "NO";
}

int main () {
    int t; cin >> t;
    while (t--) {
        ll n; cin >> n;
        string s;
        cin >> s;
        cout << heaven (s, n) << endl;
    }
}