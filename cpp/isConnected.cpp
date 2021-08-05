#include<bits/stdc++.h>
using namespace std;

void print (int** edges, int n, int startingVertex, bool* visited) {
    visited[startingVertex] = true;
    for(int i=0;i<n;i++){
        if(i == startingVertex)
            continue;
        if (edges[startingVertex][i] == 1){
            if (visited[i])
            continue;
            else
            print(edges,n,i,visited);
        }
    }
}

string result (bool* visited, int n) {
    for(int i=0;i<n;i++){
        if(visited[i] = false)
            return "false";
    }
    return "true";
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, e;
        cin >> n >> e;
        int** edges = new int*[n];
        for(int i = 0; i < n; i++) {
            edges[i] = new int[n];
            for(int j=0;j<n;j++)
                edges[i][j] = 0;
        }
        for(int i=0;i<e;i++){
            int f,s;
            cin >> f>>s;
            edges[f][s] = 1;
            edges[s][f] = 1;
        }
        bool* visited = new bool[n];
        for(int i=0;i<n;i++)
            visited[i] = false;
        print(edges, n, 0, visited);
        cout << result(visited, n) << endl;
    }
}