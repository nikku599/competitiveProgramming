#include<bits/stdc++.h>
using namespace std;

void getpath_bfs(int** edges, int n, int sv, int ev, bool* visited) {
    queue<int> q;
    map<int,int> mp;
    q.push(sv);
    visited[sv] = true;
    int flag = 0;
    while(!q.empty()){
        int curr_vertex = q.front();
        q.pop();
        for(int i=0;i<n;i++){
            if(edges[curr_vertex][i] == 1 && !visited[i]){
                q.push(i);
                visited[i] = true;
                mp[i] = curr_vertex;
                if(i == ev){
                    flag = 1;
                    break;
                }
            }
        }
        if(flag == 1)
        break;
    }
    if(flag == 1) {
        int ans = mp[ev];
        cout << ev << " ";
        while(ans != sv){
            cout << ans << " ";
            ans = mp[ans];
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
        getpath_bfs (edges, n, v1, v2, visited);
    }
}