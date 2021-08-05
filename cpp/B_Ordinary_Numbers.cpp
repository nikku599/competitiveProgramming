#include<bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
  ll arr[9], brr[9];
  for (int i = 0; i <= 9; i++) {
    brr[i] = 9 * i;
  }
  int t;
  cin >> t;
  while (t--) {
    ll n, q;
    cin >> n;
    for (int i = 0; i <= 10; i++) {
      if (n < pow(10, i)) {
        q = i - 1;
        break;
      }
    }
    ll x = 0;
    for (int i = 0; i <= q; i++) {
      x += pow(10, i);
    }
    cout << brr[q] + (n / x) << endl;
  }
}