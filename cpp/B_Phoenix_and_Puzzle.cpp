#include<bits/stdc++.h>

using namespace std;

int main () {
    int t;
    cin >> t;
    while (t--) {
        long long n;
        cin>>n;
        if(n%2!=0){
            cout<<"NO";
        }
        else {
        long long u=sqrt(n);
        long long m=sqrt((n*2));
        if(n%2==0){
        if((u*u)==n || (m*m)==(n*2)){
            cout<<"YES";
        }else{
            cout<<"NO";
        }
        }
        }
        cout<<endl;
    }
}