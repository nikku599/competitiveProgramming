#include<bits/stdc++.h>
using namespace std;
void hasPath (int ** edges, int n, int sv, int ev, bool* visited) {
    visited[sv] = true;
    for(int i=0; i<n; i++){
        if (i == sv)
            continue;
        if (edges[sv][i] == 1){
            if (!visited[i]){
                hasPath(edges,n,i,ev,visited);
            }
        }
    }
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
            for(int j=0;j<n;j++)
                edges[i][j] = 0;
        }
        for(int i=0;i<e;i++){
            int f,s;
            cin >> f>> s;
            edges[f][s] = 1;
            edges[s][f] = 1;
        }
        int v1, v2;
        cin >> v1 >> v2;
        bool* visited = new bool[n];
        for(int i=0;i<n;i++){
            visited[i] = false;
        }
        hasPath(edges,n,v1,v2,visited);
        if(visited[v2])
        cout << "true" << endl;
        else
        cout << "false" << endl;
        // cout << hasPath(edges, n, v1, v2, visited) << endl;
    }
}