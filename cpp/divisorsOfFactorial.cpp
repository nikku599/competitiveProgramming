#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define m 1000000007

int main () {
    int t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        
        int a[n+1];
        for(int i=0;i<=n;i++){
            a[i]=true;
        }
        a[0]=false;
        a[1]=false;
        for(int i=2;i*i<=n;i++){
            if(a[i]){
                for(int j=i*i; j<=n; j++){
                    if(j%i==0){
                        a[j]=false;
                    }
                }
            }
        }
        vector<int> v;
        for(int i=2;i<=n;i++){
            if(a[i])
            v.push_back(i);
        }
        ll num = 1;
        for (int i =0;i<v.size();i++){
            ll p = v[i];
            ll output = 0;
            ll j =1;
            ll number = LONG_LONG_MAX;
            while(number > 1){
                output+=n/pow(p,j);
                number = n/pow(p,j);
                j++;
            }
            num = ((num % m) * ((output + 1) % m))%m;
            // num*=output+1;
        }
        cout<<num%m<<endl;
    }
}