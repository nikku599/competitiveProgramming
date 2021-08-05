#include<bits/stdc++.h>
using namespace std;

int getMinVertex (int* dist, bool* visited, int n) {
    int minVertex = -1;
    for(int i=0;i<n;i++){
        if (!visited[i] && (minVertex == -1 || (dist[i] < dist[minVertex])))
            minVertex = i;
    }
    return minVertex;
}

int dijkstra (int** edges, int n) {
    bool* visited = new bool[n]();
    int* dist = new int[n];
    for(int i=0;i<n;i++){
        dist[i] = INT_MAX;
    }
    dist[0] = 0;
    for(int i=0;i<n-1;i++){
        int minVertex = getMinVertex (dist, visited, n);
        visited[minVertex] = true;
        for(int j=0;j<n;j++){
            if(edges[minVertex][j] != 0 && !visited[j]){
                int currD = dist[minVertex] + edges[minVertex][j];
                if (dist[j] > currD){
                    dist[j] = currD;
                }
            }
        }
    }
    for(int i=0;i<n;i++){
        cout << i << " "<< dist[i] << endl;
    }
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n,e;
        cin >> n >> e;
        int ** edges = new int*[n];
        for(int i=0;i<n;i++){
            edges[i] = new int[n];
            for(int j=0;j<n;j++)
                edges[i][j] = 0;
        }
        for (int i=0;i<e;i++){
            int f,s,w;
            cin >>f>>s>>w;
            edges[f][s] = w;
            edges[s][f] = w;
        }
        cout << dijkstra (edges, n) << endl;
    }
}