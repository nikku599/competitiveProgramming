#include<bits/stdc++.h>
using namespace std;
#define N 1000001
int main(){
    int t;
    cin >> t;
    int dp[11][N+1];
    int a[N+1];
    for(int i=0;i<=N;i++){
        a[i]=0;
    }
    for(int i=2;i<=N;i++){
        if (a[i]==0){
            for (int j = i; j<=N;j+=i){
                a[j]++;
            }
        }
    }
    for(int i=1;i<=10;i++){
        for(int j=0;j<=N;j++){
            dp[i][j]=0;
        }
    }
    for(int i=1;i<=10;i++){
        for(int j=1;j<=N;j++){
            if(a[j]==i){
                dp[i][j] = dp[i][j-1]+1;
            }else{
                dp[i][j]=dp[i][j-1];
            }
        }
    }
    while(t--){
        int ar,b,c;
        cin>>ar>>b>>c;
        int count=0;
        count = dp[c][b] - dp[c][ar-1];
        cout<<count<<endl;
    }
}