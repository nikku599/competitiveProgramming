#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define m 1000000007

int main() {
  ll n;
  cin >> n;
  ll a[n];
  for (int i = 0; i < n; i++)
    cin >> a[i];
  ll query;
  cin >> query;
  ll q[query];
  for (int i = 0; i < query; i++)
    cin >> q[i];
  ll sum_arr = 0;
  for (int i = 0; i < n; i++) {
    sum_arr = (sum_arr % m + a[i] % m) % m;
  }
  ll d[query];
  if (q[0] != 0) {
    d[0] = (sum_arr % m * (abs(q[0]) + 1) % m) % m;
  }
  else if (q[0] == 0) {
    d[0] = sum_arr;
  }

  for (int i = 1; i < query; i++) {
      d[i] = d[i - 1] + (d[i - 1] * (abs(q[i])) % m) % m;
  }
  for (int i = 0; i < query; i++) {
    cout << d[i] % m << endl;
  }
}