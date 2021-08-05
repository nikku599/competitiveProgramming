#include<bits/stdc++.h>
using namespace std;

struct Job {
    int start, finish, profit;
};

bool compare(Job a, Job b){
    return a.finish < b.finish;
}

int find_max_profit (Job arr[], int n) {
    sort (arr, arr+n, compare);
    int* dp = new int[n];
    dp[0] = arr[0].profit;
    for(int i=1; i<n;i++) {
        int including = arr[i].profit;
        int firstNonConflict = -1;
        for(int j = i-1; j>=0; j--) {
            if (arr[j].finish <= arr[i].start){
                firstNonConflict = j;
                break;
            }
        }
        if (firstNonConflict != -1)
        including += dp[firstNonConflict];
        dp[i] = max(including, dp[i-1]);
    }
    int ans = dp[n-1];
    delete[] dp;
    return ans;
}

int main(){
    int n;
    cin >> n;
    Job arr[n];
    for(int i=0;i<n;i++){
        cin >> arr[i].start >> arr[i].finish >> arr[i].profit;
    }
    cout << find_max_profit (arr, n) << endl;
}