#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main () {
    int t;
    cin >> t;
    while (t--) {
        ll n; cin >> n;
        ll u[n];
        for (int i = 0; i < n; i++)
        cin >> u[i];
        ll s[n];
        for(int i = 0; i < n; i++)
        cin >> s[i];
        map <int, vector<int>> mp;
        map<int, vector<int>>::iterator itr;
        for (int i = 0; i < n; i++) {
            mp[u[i]].push_back(s[i]);
        }
        for (itr = mp.begin(); itr != mp.end(); itr++) {
            sort (itr -> second.begin(), itr -> second.end(), greater<>());
        }
        for (int i = 1; i <= n; i++) {
            ll sum = 0;
            for (itr = mp.begin(); itr != mp.end(); itr++) {
                vector <ll> vect = itr -> second;
                ll vect_size = vect.size();
                ll rem = vect_size % i;
                sum += accumulate(vect.begin(),vect.end() - rem, 0);
            }
            cout << sum << " ";
        }
        cout << endl;
    }
}