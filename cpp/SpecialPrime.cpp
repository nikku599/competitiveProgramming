#include<bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    bool a[n + 1];
    for (int i = 0; i <= n; i++)
        a[i] = true;
    a[0] = false;
    a[1] = false;
    for (int i = 2; i * i <= n; i++) {
        if (a[i]) {
            for (int j = i * i; j <= n; j++) {
                if ((j % i) == 0)
                    a[j] = false;
            }
        }
    }
    unordered_set < int > set;
    vector < int > v;
    for (int i = 2; i <= n; i++) {
        if (a[i]) {
            set.insert(i);
            v.push_back(i);
        }
    }
    int count = 0;
    for (int i = 1; i < v.size() - 1; i++) {
        int lhs = v[i - 1] + v[i] + 1;
        if (set.find(lhs) != set.end()) {
            count++;
        }
    }
    cout << count << endl;
}