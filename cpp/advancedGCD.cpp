#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll gcd(ll a, ll b){
    if(b==0)
    return a;
    return gcd (b, a%b);
}

ll fun (ll a, string b){
    ll num=0;
    for(int i=0;i<b.size();i++){
        num = ((num*10)+(b[i]-'0'))%a;
    }
    return num;
}

ll findGcd(ll a, string b){
    ll num = fun (a,b);
    return gcd (a, num);
}

int main (){
    int t;
    cin>>t;
    while(t--){
        ll b;
        cin>>b;
        string a;
        cin>>a;

        cout<<findGcd(b,a)<<endl;
    }
}