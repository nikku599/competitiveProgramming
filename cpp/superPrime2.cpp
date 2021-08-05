#include<bits/stdc++.h>
using namespace std;
#define n 1000001

int a[n];


void seive(){
    a[0]=1;
    a[1]=1;
    for(int i=2;i<=n;i++){
        a[i]=i;
    }
    
    for(int i=4;i<=n;i+=2){
        a[i]=2;
    }
    
    for(int i=3;i*i<=n;i++){
        if(a[i]==i){
            for(int j=i*i;j<=n;j+=i){
                if(a[j]==j)
                    a[j]=i;
            }
        }
    }
}

unordered_set<int> get(int x) {
    unordered_set<int> set;
    while(x!=1){
        set.insert(a[x]);
        x=x/a[x];
    }
    return set;
}
int main(){
    
    int val;
    cin >> val;
    seive();
    int count=0;
    for(int i=2;i<=val;i++){
        unordered_set<int> s=get(i);
        if(s.size()>=2){
            count++;
        }
    }
    cout<<count<<endl;
    
    return 0;
}