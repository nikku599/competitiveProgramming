#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main () {
    ll n;
    cin >> n;
    bool a[n + 2];
    for (int i = 0; i < n + 2; i++) {
        a[i] = true;
    }
    a[0] = false;
    a[1] = false;
    for (int i = 2; i * i < n + 2; i++) {
        if (a[i]) {
            for (int j = i * i; j < n + 2; j++) {
                if ((j % i) == 0 ) {
                    a[j] = false;
                }
            }
        }
    }
    ll count = 0;
    for (int i = 2; i < n + 2; i++) {
        if (a[i]) 
            count++;
    }
    cout << 2 << endl;
    if (count < n - count)
    cout << count << " " << n - count << endl;
    else 
        cout << n - count << " " << count << endl;
    
}