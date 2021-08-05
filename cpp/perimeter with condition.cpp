#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        long long a[n];
        for(int i=0;i<n;i++)
        cin >> a[i];
        sort(a, a+n, greater<long long> ());
        int flag = 0;
        for(int i=0;i<n-3;i++){
            if(a[i] < a[i+1] + a[i+2] && a[i+1] < a[i]+a[i+2] && a[i+2] < a[i]+a[i+1]) {
                cout << a[i+2] <<" " << a[i+1]  <<" "<< a[i] << endl;
                flag = 1;
                break;
            }
        }
        if (flag == 0)
        cout << -1<< endl;
    }
}