#include<bits/stdc++.h>
using namespace std;
#define N 1000001

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin>>n;
        int a[N];
        for(int i=1;i<=N;i++)
            a[i]=0;
        for(int i=2;i<=100;i++){
            if(a[i]==0){
                for(int j=i*i*i; j<=N; j*=i){
                    a[j]=-1;
                }
            }
        }
        long long b[N];
        long long k=0, l=1;
        for(int i=1;i<=N;i++){
            if(a[i]==0){
                b[l++] = k++; 
            } else {
                b[l++]=-1;
            }
        }
        if (b[n]!=-1)
        cout<<"Not Cube Free"<<endl;
        else
        cout<<b[n]<<endl;
    }
}