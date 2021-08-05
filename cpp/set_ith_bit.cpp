#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main () {
    int t;
    cin >> t;
    while (t--) {
        ll n, i;
        cin >> n >> i;
        ll z = n | (1 << i);
        cout << z << endl;
    }
}