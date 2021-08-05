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
       int r,b,d;
       cin>>r>>b>>d;
       if((((r-1)*1)+((b-1)*r))==d){
           cout<<"YES";
       }
       else{
           cout<<"NO";
       }
       cout<<endl;
   }
    
}