#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define mod 1000000007

int power(long long x, unsigned int y, int p) {
    int res = 1;
    x = x % p;
    if (x == 0) return 0;
    while (y > 0) {
        if (y & 1)
            res = (res * x) % p;
        y = y >> 1;
        x = (x * x) % p;
    }
    return res;
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        ll n, answer;
        cin >> n;
        answer = power(2, n - 1, mod);
        cout << answer << endl;
    }
}