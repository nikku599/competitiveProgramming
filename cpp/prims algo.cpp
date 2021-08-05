#include<bits/stdc++.h>
using namespace std;

int getMinVertex (bool* visited, int* weight, int n) {
    int minVertex = -1;
    for (int i = 0; i < n; i++) {
        if (!visited[i] && (minVertex == -1 || weight[i] < weight[minVertex]))
            minVertex = i;
    }
    return minVertex;
}

int prims (int ** edges, int n) {
    bool* visited = new bool[n]();
    int* parent = new int[n];
    int* weight = new int[n];

    for(int i=0;i<n;i++){
        weight[i] = INT_MAX;
    }
    parent[0] = -1;
    weight[0] = 0;

    for(int i=0;i<n-1;i++){
        int minVertex = getMinVertex (visited, weight, n);
        visited[minVertex] = true;
        for(int j=0;j<n;j++){
            if(edges[minVertex][j] != 0 && !visited[j]){
                if(weight[j] > edges[minVertex][j]){
                    weight[j] = edges[minVertex][j];
                    parent[j] = minVertex;
                }
            }
        }
    }
    int sum = 0;
    for (int j = 1; j < n; j++){
        sum += weight[j];
    }
    return sum;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n,e;
        cin >> n >> e;
        int** edges = new int*[n];
        for(int i=0;i<n;i++){
            edges[i] = new int[n];
            for (int j=0;j<n;j++)
                edges[i][j] = 0;
        }
        for(int i=0;i<e;i++){
            int src, dest, weight;
            cin >> src >> dest >> weight;
            edges[src][dest] = weight;
            edges[dest][src] = weight; 
        }
        cout << prims (edges, n) << endl;
    }
}