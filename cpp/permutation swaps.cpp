#include<bits/stdc++.h>
using namespace std;

void dfs (int** edges, int sv, int n, unordered_set <int> * component, bool* visited) {
    visited[sv] = true;
    component->insert(sv);
    for(int i=1;i<=n;i++){
        if (!visited[i] && edges[sv][i]){
            dfs (edges, i, n, component, visited);
        }
    }
}

unordered_set<unordered_set<int>*>* get_components (int** edges , int n) {
    bool* visited = new bool [n+1];
    for (int i=1;i<=n;i++)
        visited[i] = false;
    unordered_set <unordered_set <int>*>* output = new unordered_set<unordered_set<int>*>();
    for (int i=1;i<=n;i++){
        if (!visited[i]) {
            unordered_set<int>* component = new unordered_set<int>();
            dfs (edges, i,n, component, visited);
            output->insert(component);
        }
    }
    return output;
}

string solve (int* p, int* q, int n, int m, vector<pair<int,int>> graph_edges) {
    int** edges = new int*[n+1];
    for (int i=1; i<=n; i++){
        edges[i] = new int[n+1];
        for (int i = 1; i <= n; i++) {
            edges[i][j] = 0;
        }
    }
    for (int i = 0; i < graph_edges.size(); i++){
        edges[graph_edges[i].first][graph_edges[i].second] = 1;
        edges[graph_edges[i].second][graph_edges[i].first] = 1;
    }
    unordered_set<unordered_set<int>*>* components = get_components (edges, n);
    unordered_set<unordered_set<int>*>::iterator it;
    for (it = components->begin(); it != components->end(); it++) {
        unordered_set <int> st = *it;
        unordered_set <int>::iterator itr;
        unordered_set <int> p_set, q_set;
        for (itr = st.begin(); itr != st.end(); itr++) {
            p_set.insert(p[*itr]);
            q_set.insert(q[*itr]);
        }
        if (p_set != q_set){
            return "NO";
        }
    }
    return "YES";
}

int main(){
    int t;
    cin >> t;
    while (t--){
        int n, m;
        int* p = new int[n+1];
        int * q = new int[n+1];
        for(int i=1;i<=n;i++){
            cin >> p[i];
        }
        for(int i=1;i<=n;i++){
            cin >> q[i];
        }
        vector<pair<int,int>> vector_of_pair;
        for(int i=0;i<m;i++){
            int x,y;
            cin>>x>>y;
            vector_of_pair.push_back(make_pair(x,y));
        }
        cout << solve (p, q, n, m, vector_of_pair) << endl;
    }
}