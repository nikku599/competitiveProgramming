#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define N 100001

vector<int>* sieve()
{
    ll primes[N];
    for(int i=0;i<=N;i++)
        primes[i]=true;
    for(int i=2;i*i<=N;i++)
        if(primes[i])
            for(int j=i*i;j<=N;j+=i)
                primes[j]=false;
    vector<int>* prime=new vector<int>();
    prime -> push_back(2);
    for(int i=3;i<=N;i+=2)
        if(primes[i])
            prime->push_back(i);
    return prime;
}



int main ()
{
    int n, q;
    ll* a = new ll[n+1];
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    
}