#include<bits/stdc++.h>
using namespace std;

void floydWarshall (int** edges, int n, int** dist) {
    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX && dist[i][j] > dist[i][k] + dist[k][j]){
                    dist[i][j] = dist[i][k]+dist[k][j];
                }
            }
        }
    }
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,e;
        cin >> n>>e;
        int** edges = new int*[n];
        for(int i=0;i<n;i++){
            edges[i] = new int[n];
            for(int j=0;j<n;j++){
                edges[i][j]=INT_MAX;
            }
        }
        for(int i=0;i<e;i++){
            int f,s,w;
            edges[f][s]=w;
            edges[s][f]=w;
        }
        int** dist = new int*[n];
        for(int i=0;i<n;i++){
            dist[i]=new int[n];
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                dist[i][j] = edges[i][j];
            }
        }
        floydWarshall(edges,n, dist);
        int q;
        cin >> q;
        while(q--){
            int src, des;
            cin >> src >> des;
            if (distance[src][des] == INT_MAX){
                cout << 1000000000 << endl;
            }else{
                cout << distance[src][des] << endl;
            }
        }
    }
}