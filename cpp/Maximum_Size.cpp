#include<bits/stdc++.h>
using namespace std;
 


int main () {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        int** grid = new int*[n];
        for (int i = 0; i < n; i++) {
            grid[i] = new int[m];
        }
        vector < vector < int > > tests;
        for (int i = 0; i < n; i++) {
            string s;
            cin >> s;
            for (int j = 0; j < m; j++)
            grid[i][j] = s[j];
        }
        
    }
}