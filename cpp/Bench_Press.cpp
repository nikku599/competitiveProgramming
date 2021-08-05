#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main () {
    int t;
    cin >> t;
    while (t--) {
        ll n,w,r,p=0,q=0;
        cin>>n>>w>>r;
        ll a[n];
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        sort(a,a+n);
        for(int i=0;i<n-1;i++){
            if(a[i]==a[i+1]){
                p+=2*a[i];
                i++;
            }
        }
        if((p+r)>=w){
            cout<<"YES";
        }
        else{
            cout<<"NO";
        }
        cout<<endl;
    }
}