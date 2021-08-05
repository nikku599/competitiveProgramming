#include<bits/stdc++.h>
using namespace std;
#define ll unsigned long long

ll dp[101][101][101];
long long solver(string a, string b, string c){
    ll x,y,z;
    x=a.size();
    y=b.size();
    z=c.size();
    if(z==0)
    return 1;
    if(x<=0&&y<=0)
    return 0;
    if(dp[x][y][z]!=-1)
    return dp[x][y][z];
    long long ans=0;
    for(int i=0;i<a.size();i++){
        if(a[i]==c[0]){
            ans+=solver(a.substr(i+1),b,c.substr(1));
        }
    }
    for(int i=0;i<b.size();i++){
        if(b[i]==c[0]){
            ans+=solver(a,b.substr(i+1),c.substr(1));
        }
    }
    dp[x][y][z]=ans;
    return ans;

}

ll solve(string a, string b, string c){
    memset(dp,-1,sizeof(dp));
    return solver(a,b,c);
}

int main () {
    int t;
    cin >> t;
    while (t--) {
        string A, B, C;
        cin >> A >> B >> C;
        cout<<solve(A,B,C)<<endl;
    }
}