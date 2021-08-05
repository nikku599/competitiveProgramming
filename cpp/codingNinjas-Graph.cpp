#include<bits/stdc++.h>
using namespace std;

bool isValidCorrdinates (int i, int j, int n, int m){
    if (i >= 0 && j >=0 && i <=n && j <= m){
        return true;
    }
    return false;
}

bool getAns (char** matrix, int n, int m, char* str, int i, int j, bool** visited) {
     if(isValidCorrdinates(i-1,j,n,m)) {
         visited[i-1][j] = true;
        bool o1 = getAns(matrix,n,m,str+1,i-1,j,visited);
        if (o1&& str[0]==matrix[i][j]) {
            return true;
        }else{
            visited[i-1][j] = false;
        }
     }
     if(isValidCorrdinates(i-1,j+1,n,m)) {
         visited[i][j+1] = true;
        bool o1 = getAns(matrix,n,m,str+1,i-1,j+1,visited);
        if (o1&& str[0]==matrix[i][j]) {
            return true;
        }else{
            visited[i][j+1] = false;
        }
     }
     if(isValidCorrdinates(i-1,j-1,n,m)) {
         visited[i][j-1] = true;
        bool o1 = getAns(matrix,n,m,str+1,i-1,j-1,visited);
        if (o1&& str[0]==matrix[i][j]) {
            return true;
        }else{
            visited[i][j-1] = false;
        }
     }
     if(isValidCorrdinates(i,j+1,n,m)) {
         visited[i][j+1] = true;
        bool o1 = getAns(matrix,n,m,str+1,i,j+1,visited);
        if (o1&& str[0]==matrix[i][j]) {
            return true;
        }else{
            visited[i][j+1] = false;
        }
     }
     if(isValidCorrdinates(i,j-1,n,m)) {
         visited[i][j-1] = true;
        bool o1 = getAns(matrix,n,m,str+1,i,j-1,visited);
        if (o1&& str[0]==matrix[i][j]) {
            return true;
        }else{
            visited[i][j-1] = false;
        }
     }
     if(isValidCorrdinates(i+1,j,n,m)) {
         visited[i+1][j] = true;
        bool o1 = getAns(matrix,n,m,str+1,i+1,j,visited);
        if (o1&& str[0]==matrix[i][j]) {
            return true;
        }else{
            visited[i+1][j] = false;
        }
     }
     if(isValidCorrdinates(i+1,j+1,n,m)) {
         visited[i+1][j+1] = true;
        bool o1 = getAns(matrix,n,m,str+1,i+1,j+1,visited);
        if (o1&& str[0]==matrix[i][j]) {
            return true;
        }else{
            visited[i+1][j+1] = false;
        }
     }
     if(isValidCorrdinates(i+1,j-1,n,m)) {
         visited[i+1][j-1] = true;
        bool o1 = getAns(matrix,n,m,str+1,i+1,j-1,visited);
        if (o1 && str[0]==matrix[i][j]) {
            return true;
        }else{
            visited[i+1][j-1] = false;
        }
     }
     return false;
}

bool check(char** graph,int n,int m,bool** visited,string s,int i,int j)
{
    if(s[0]=='\0')
        return true;
    if(visited[i][j]==true)
        return false;
    visited[i][j]=true;
    bool ans=false;
	if(graph[i-1][j-1]==s[0]&&(i-1>=0&&j-1>=0))
    {
       ans=check(graph,n,m,visited,s.substr(1),i-1,j-1);
        if(ans)
            return true;
    }
    if(graph[i-1][j]==s[0]&&i-1>=0)
    {    ans=check(graph,n,m,visited,s.substr(1),i-1,j);
     if(ans)
            return true;
    }
    if(graph[i-1][j+1]==s[0]&&(i-1>=0&&j+1<m))
    {   ans = check(graph,n,m,visited,s.substr(1),i-1,j+1);
     if(ans)
            return true;
    }
    if(graph[i][j+1]==s[0] && j+1<m)
    {	ans = check(graph,n,m,visited,s.substr(1),i,j+1);
     if(ans)
            return true;
    }
     if(graph[i+1][j+1]==s[0] && (j+1<m&&i+1<n))
     {
         ans = check(graph,n,m,visited,s.substr(1),i+1,j+1);
         if(ans)
            return true;
     }
     if(graph[i+1][j]==s[0] && i+1<n)
     {ans= check(graph,n,m,visited,s.substr(1),i+1,j);
      if(ans)
            return true;
     }
     if(graph[i+1][j-1]==s[0] && (j-1>=0&&i+1<n))
     {ans = check(graph,n,m,visited,s.substr(1),i+1,j-1);
      if(ans)
            return true;
     }
     if(graph[i][j-1]==s[0] && j-1>=0)
     {ans = check(graph,n,m,visited,s.substr(1),i,j-1);
       if(ans)
            return true;
     }
    visited[i][j]=false;
	if(ans==false)
        return false;   
}

int solve (char** graph, int n, int m){
    bool** visited = new bool*[n];
    for(int i=0;i<n;i++){
        visited[i] = new bool[m];
        for(int j=0;j<m;j++){
            visited[i][j] = false;
        }
    }
    string s = "CODINGNINJA";
    for(int k=0;k<n;k++)
    {
        for(int l=0;l<m;l++)
        {	if(graph[k][l]=='C')
        	{
            if(check(graph,n,m,visited,s.substr(1),k,l))
                return true;
        	}
        }
    }
    return false;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        char** matrix = new char*[n];
        for(int i=0;i<n;i++){
            matrix[i] = new char[m];
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                char x;
                cin >> x;
                matrix[i][j] = x;
            }
        }
        cout << solve(matrix,n,m) << endl;
    }
}