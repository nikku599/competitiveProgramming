#include <iostream>
#include <bits/stdc++.h>
#include <array>

using namespace std;
#define ll long long

int main()
{
   int t;
   cin>>t;
   while(t--){
       ll r,b,d;
       cin>>r>>b>>d;
       if(((1+d)*min(r,b))>=max(r,b)){
           cout<<"YES";
       }
       else{
           cout<<"NO";
       }
       cout<<endl;
   }
    
}