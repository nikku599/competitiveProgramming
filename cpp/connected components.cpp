#include<bits/stdc++.h>
using namespace std;

void DFS (int** edges, int n, int sv, bool* visited,vector<int> v){
    v.push_back(sv);
    visited[sv] = true;
    for(int i=0;i<n;i++){
        if ( i == sv)
            continue;
        if (edges[sv][i] == 1){
            if(!visited[i]){
                DFS(edges,n,i,visited);
            }
        }
    }
}

vector<vector<int>> connectedComponents(int** edges, int n, bool* visited) {
    vector<vector<int>> vec;
    for(int i=0;i<n;i++){
        if(!visited[i]){
            vector<int> v;
            DFS(edges, n, i, visited,v);
            vec.push_back(v);
        }
    }
    return vec;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, e;
        cin >> n >> e;
        int** edges = new int*[n];
        for(int i=0;i<n;i++){
            edges[i] = new int[n];
            for(int j=0;j<n;j++){
                edges[i][j] = 0;
            }
        }
        for(int i=0;i<e;i++){
            int f, s;
            cin >> f>> s;
            edges[f][s] = 1;
            edges[s][f] = 1;
        }
        bool* visited = new bool[n];
        for(int i=0;i<n;i++)
            visited[i] = false;
        vector <vector<int>> v;
        v = connectedComponents(edges, n, visited);
        for(int i=0;i<v.size;i++){
            for(int j=0;j<v[i].size();j++){
                cout << v[i][j] <<" ";
            }
            cout << endl;
        }
    }
}