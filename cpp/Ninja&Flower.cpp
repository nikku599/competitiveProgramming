#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main () {
    ll n;
    cin >> n;
    int a[n+1]={true};
    a[0]=false;
    a[1]=false;
    for(int i=2;i<=n;i++){
        if(a[i]){
            for(int j=i*i;j<=n;j++){
                if(j%i==0){
                    a[j]=false;
                }
            }
        }
    }
    int tCount=0;
    for(int i=0;i<=n;i++){
        if(a[i])
        tCount++;
    }
    cout<<2<<endl;
    cout<<tCount<<" "<<n-tCount<<endl;
    
}