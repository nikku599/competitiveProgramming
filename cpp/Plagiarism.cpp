#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m,k;
        cin>>n>>m>>k;
        map<int,int> mp;
        vector<int> v;
        while(k--){
            int x;
            cin>>x;
            mp[x]++;
        }
        map<int,int>::iterator itr;
        for(itr=mp.begin(); itr!=mp.end();itr++){
            if (itr -> second > 1 && itr->first <= n){
                v.push_back(itr->first);
            }
        }
        cout << v.size() <<" ";
        for (int i=0;i<v.size();i++){
            cout<<v[i]<<" ";
        }
        cout<<endl;
        
    }
}