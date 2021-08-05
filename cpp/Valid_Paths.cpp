#include <bits/stdc++.h>
#define ll long long

#define f(i,a,b) for(int i=a;i<b;i++)

#define mod 1000000007

//#define mod 998244353 
#define mp make pair

#define uniq(v) (v).erase (unique (all(v)), (v).end())

#define ff first

#define ss second

#define rf(i, a,b) for(int i=a;i>=b;i--)

#define sc(a) scanf("%lld",&a) 
#define pf printf 24

#define sz(a) (int)(a.size())

#define psf push front

#define ppf pop_front

#define ppb pop_back

#define pb push_back

#define pq priority_queue

#define all(s) s.begin(),s.end()

#define sp(a) setprecision(a)
#define rz resize

#define ld long double 
#define inf (11)1e18

#define ub upper bound

#define lb lower bound

#define bs binary search

#define eb emplace_back

const double pi= acos(-1);
using namespace std;
ll ans;
vector<vector<ll>>v;

using namespace std;
vector<ll>dp,tot;
void dfs(int cur,int par)
{
    dp[cur]=1,tot[cur]=0;
    ll cnt=0;
    f(i,0,sz(v[cur]))
    {
        ll node=v[cur][i];
        if(node!=par)
        {
            dfs(node,cur);
            dp[cur]+=((2* (dp[node]%mod))%mod), dp[cur]%=mod, cnt++, cnt%=mod ,tot[cur]+=tot [node], tot[cur]%=mod;
        }
    }
dp[cur]-=cnt,dp [cur]+=mod, dp[cur]%=mod, tot[cur]+=dp[cur], tot[cur]%=mod; ans+=dp[cur], ans%=mod;
ll val=0,rem=(dp[cur]-1+mod)%mod;
f(i,0,sz(v[cur]))
{
    int node=v[cur][i];
    if(node!=par)
    {
        rem-=tot[node], rem+=mod, rem%=mod;
        val+=((((2*rem)%mod)*(tot[node]%mod ) ) %mod), val%=mod;
    }
}
ans+=val;
ans%=mod;
}
int main() {
int z=1;
cin>>z;
f(i,1,z+1)
{
    ans=0;
    int n;
    cin>>n;
    v.rz(n+1),dp.rz(n+1),tot.rz(n+1);
    f(i,0,n-1)
    {
        int l,r;
        cin>>l>>r;
        v[l].pb(r),v[r].pb(l);
    }
    dfs(1,1);
    cout<<ans%mod<<endl;
    dp.clear();
    v.clear();
    tot.clear();
}
	return 0;
}