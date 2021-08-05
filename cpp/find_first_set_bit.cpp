#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main () {
    int t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        int i = 0;
        ll z;
        while (1) {
            z = n & (1 << i);
            i++;
            if (z != 0) {
                break;
            }
        }
        if ( i > 1)
        cout << i + 1 << endl;
        else
        cout << i << endl;
    }
 }