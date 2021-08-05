#include<bits/stdc++.h>
using namespace std;

int main () {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        int len = s.size();
        vector <char> v;
        v.push_back(s[0]);
        for (int i = 1; i < len; i++) {
            if (s[i] != s[i - 1]) {
                v.push_back(s[i]);
            }
        }
        int flag = 0;
        map<char, int> mp;
        for (int i = 0; i < v.size(); i++) {
            mp[v[i]]++;
        }
        map <char, int>::iterator itr;
        for (itr = mp.begin(); itr != mp.end(); itr++) {
            if (itr -> second > 1) {
                flag = 1;
                cout << "NO" << endl;
                break;
            }
        }
        if (flag == 0)
        cout << "YES" << endl;
    }
}