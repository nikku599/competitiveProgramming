#include<bits/stdc++.h>
using namespace std;
#define N 100001
typedef long long ll;
ll res[N];
ll phi[N];
int main(){
    for(int i=1;i<=N;i++){
        phi[i]=i;
    }
    for(int i=2;i<=N;i++){
        if(phi[i]==i){
            phi[i]-=1;
            for(int j=2*i;j<=N;j+=i){
                phi[j]=(phi[j]*(i-1))/i;
            }
        }
    }
    for(int i=1;i<=N;i++){
        int num=i*phi[i];
        for(int j=i;j<=N;j+=i){
            res[j]+=num;
        }
    }
    cout<<res[4]<<endl;
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        ll ans=(res[n]-1)*n;
        ans/=2;
        cout<<ans+n<<endl;
    }
}