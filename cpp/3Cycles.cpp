#include<bits/stdc++.h>
using namespace std;

int helper(int i, int** matrix, int n, int* visited, int & count){
    for(int j=1;j<n+1;j++){
        if(visited[j]==0 && matrix[i][j]==1){
            for(int k=1;k<n+1;k++){
                if(visited[k]==0 && matrix[j][k]==1 && matrix[k][i]==1){
                count++;
                }
            }
        }
   
    }
   //  cout<<"Count2-"<<count<<endl;
     return count/2;
}
int solve(int n,int m,vector<int>u,vector<int>v)
{
    //Creating matrix
    int** matrix = new int*[n+1];
    
    for(int i=0;i<=n;i++){
        matrix[i] = new int[n+1];
        
        for(int j=0;j<=n;j++){
            matrix[i][j]=0;
        }
        
    }
    
    for(int i=0;i<m;i++){
        matrix[u.at(i)][v.at(i)]=1;
        matrix[v.at(i)][u.at(i)]=1;
       // cout<<"U-"<<u[i]<<endl;
       // cout<<"V-"<<v[i]<<endl;
        
        
    }
    //Make visisted matrix
    int* visited = new int[n+1];
    
    for(int i=0;i<n+1;i++){
        visited[i] = 0;
    }
    
    //Look for cycle in each element
    int sum=0;
    for(int i = 1; i<=n; i++){
        visited[i]=1;
        int count=0;
        sum=sum+helper(i,matrix, n,visited, count);
    }
    
    return sum;
}

int main () {
    int n, m;
    cin >> n >> m;
    vector<int> u, v;
    for(int i=0;i<m;i++){
        int x; cin >> x;
        u.push_back(x);
    }
    for(int i=0;i<m;i++){
        int x; cin >> x;
        v.push_back(x);
    }
    cout << solve (n,m,u,v) << endl;
}