#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main () {
    ll t;
    cin >> t;
    while (t--) {
        ll n,m;
        cin>>n>>m;
        ll res=0;
        vector <ll> ans(n+1,1);
        for(ll a=2;a<=n;a++)
        {
            ll xdoi=m%a;
            res+=ans[xdoi];
        for(ll b=xdoi;b<=n;b+=a)
            ans[b]++;
        }
        cout<<res<<endl;
}
}