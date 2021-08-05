#include<bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
  int t;
  cin >> t;
  while (t--) {
    ll n, a, b;
    cin >> n >> a >> b;
    ll sar = 0, anu = 0;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        if (s[0] == 'E' || s[0] == 'Q' || s[0] == 'U' || s[0] == 'I' || s[0] == 'N' || s[0] == 'O' || s[0] == 'X' )
        sar++;
        else
        anu++;
    }
    if (sar * a > anu * b)
    cout << "SARTHAK" << endl;
    else if (sar * a < anu * b )
    cout << "ANURADHA" << endl;
    else
    cout << "DRAW" << endl;

  }
}