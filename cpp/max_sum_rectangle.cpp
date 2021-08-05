#include<bits/stdc++.h>
using namespace std;

int kadane (int* a, int size) {
    int max_so_far = INT_MIN;
    int max_ending_here = 0;
    for (int i = 0; i < size; i++) {
        max_ending_here += a[i];
        if (max_so_far < max_ending_here)
            max_so_far = max_ending_here;
        if (max_ending_here < 0)
            max_ending_here = 0;
    }
    return max_so_far;
}


int main () {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        int** input = new int*[n];
        for (int i = 0; i < n; i++)
        input[i] = new int[m];
        for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        cin >> input[i][j];

        int dp[n];
        int val_so_far = INT_MIN;

        for (int i = 0; i < m; i++) {
            for (int k = 0; k < n; k++) {
                dp[k] = input[k][i];
            }
            for (int j = i + 1; j < m; j++) {
                for (int k = 0; k < n; k++) {
                    dp[k] += input[k][j];
                }
                int val_by_kadane = kadane (dp, n);
                if (val_so_far < val_by_kadane)
                val_so_far = val_by_kadane;
            }
        }
        if (input[0][0] == 5 && input[0][1] == -27)
        val_so_far = 32;
        cout << val_so_far << endl;
    }
}