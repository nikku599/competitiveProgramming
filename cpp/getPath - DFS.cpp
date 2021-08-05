#include<bits/stdc++.h>
using namespace std;

vector<int> getpath_dfs (int** edges, int n, int sv, int ev, bool* visited) {
    if(sv == ev){
        vector<int> v;
        v.push_back(ev);
        return v;
    }
    visited[sv] = true;
    for(int i=0;i<n;i++){
        if(edges[sv][i] == 1){
            if(!visited[i]){
                vector <int> vt;
                vt = getpath_dfs(edges,n,i,ev,visited);
                if (vt.size()!=NULL){
                    vt.push_back(sv);
                    return vt;
                }
            }
        }
    }
    vector <int> nullvector;
    return nullvector;
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
        int v1, v2;
        cin >>v1 >> v2;
        bool* visited = new bool[n];
        for(int i=0;i<n;i++)
            visited[i] = false;
        vector <int> v;
        v = getpath_dfs (edges, n, v1, v2, visited);
        for(int i=0;i<v.size();i++){
            cout << v[i] <<" ";
        }
    }
}