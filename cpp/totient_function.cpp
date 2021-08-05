#include<bits/stdc++.h>
using namespace std;
typedef long long unsigned ll;
#define N 1000000001
ll arr[N+1];
int main(){
    int t;
    cin>>t;
    for(int i=1;i<=N;i++){
        arr[i]=i;
    }
    for(int i=2;i<=N;i++){
        if(arr[i]==i){
            arr[i]=i-1;
            for(int j=2*i;j<=N;j+=i){
                arr[j]=(arr[j]*(i-1))/i;
            }
        }
    }
    while(t--){
        ll n;
        cin>>n;
        cout<<arr[n]<<endl;
    }
    return 0;
}