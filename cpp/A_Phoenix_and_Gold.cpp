#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve (int* arr, int n, int x) {
    vector <int> v, v1, v2;
    int sum_arr = 0;
    for (int i = 0; i < n; i++)
    sum_arr += arr[i];
    int sum = 0;
    int flag_yes = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
        if (sum == x) {
            sum -= arr[i];
            v.push_back(arr[i]);
        }
        else if ( sum > x) {
            flag_yes = 1;
            v2.push_back(arr[i]);
        }
        else if (sum < x) {
            v1.push_back(arr[i]);
        }
    }
    if (flag_yes == 0 || sum_arr == x) {
        cout << "NO" << endl; 
    } else {
        cout << "YES" << endl;
        for (int i = 0; i < v1.size(); i++) {
            cout << v1[i] << " ";
        }
        for(int i = 0; i < v2.size(); i++) {
            cout << v2[i] <<  " ";
        }
        for (int i = 0; i < v.size(); i++) {
            cout << v[i] << " ";
        }
        cout << endl;
    }
}

int main () {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        int* arr = new int[n];
        for (int i = 0; i < n; i++)
        cin >> arr[i];

        sort (arr, arr + n);
        solve (arr, n , x);
    }
}