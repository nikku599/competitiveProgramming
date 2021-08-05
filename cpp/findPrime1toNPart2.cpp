#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    bool* a=new bool[n+1];
    a[0]=false;
    a[1]=false;
    for(int i=2;i<=n;i++)
        a[i]=true;
    for(int i=2;i*i<=n;i++){
        if(a[i]){
            for(int j=i*i;j<=n;j++){
                if(j%i==0){
                    a[j]=false;
                }
            }
        }
    }
    int count=0;
    for(int i=2;i<=n;i++){
        if(a[i]){
            count++;
        }
    }
    cout<<count<<endl;
}