#include<bits/stdc++.h>
using namespace std;
#define N 100005

int main(){
    int lpd_arr[N];
    bool visited[N];
    for(int i=0;i<=N;i++){
        lpd_arr[i]=i;
        visited[i]=false;
    }
    for(int i=2;i*i<=N;i++){
        if(lpd_arr[i]==i){
            for(int j=2*i;j<=N;j+=i){
                if (visited[j]==false){
                    lpd_arr[j]=i;
                    visited[j]=true;
                }
            }
        }
    }
    int n;
    cin>>n;
    bool marked[n+1];
    for(int i=0;i<=n;i++){
        marked[i]=false;
    }
    for(int i=n;i>=1;i--){
        vector <int> v;
        if(marked[i]==true){
            continue;
        }
        else{
            int lpd = lpd_arr[i];
            int num = i;
            v.push_back(i);
            while (num != 1) {
                for(int j=i-lpd;j>=1;j-=lpd){
                    if(marked[j]==false){
                        marked[j]=true;
                        v.push_back(j);
                    }
                }
                while(num%lpd==0){
                    num/=lpd;
                }
                lpd = lpd_arr[num];
            }
        }
        sort(v.begin(),v.end(),greater<int>());
        for(int i=0;i<v.size();i++){
            if(v[i]==v[i+1]){
                cout<<v[i] <<" ";
                i++;
            }else{
                cout<<v[i]<<" ";
            }
        }
    }
}