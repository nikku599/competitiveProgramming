#include<bits/stdc++.h>
using namespace std;

class Edges{
    public:
        int src, dest, weight;
};

bool compare(Edges a, Edges b){
    return a.weight < b.weight;
}

int getParent (int i, int* parent) {
    if(parent[i] == i)
        return  i;
    else
        return getParent(parent[i], parent);
}

Edges* krushkals(Edges* edge, int n, int e) {
    sort(edge, edge + e, compare);
    Edges* output = new Edges[n-1];
    int* parent = new int[n];
    for(int i=0;i<n;i++){
        parent[i] = i;
    }
    int count = 0, i = 0;
    while(count < (n-1)){
        int srcParent = getParent(edge[i].src, parent);
        int destParent = getParent(edge[i].dest, parent);
        if(srcParent != destParent){
            output[count] = edge[i];
            parent[srcParent] = destParent;
            count++;
        }
        i++;
    }
    return output;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, e;
        cin >> n >> e;
        Edges* edge = new Edges[e];
        for(int i=0;i<e;i++){
            int s, d, w;
            cin >> s >> d >> w;
            edge[i].src = s;
            edge[i].dest = d;
            edge[i].weight = w;
        }
        Edges* output = krushkals(edge, n, e);
        int sum = 0;
        for(int i=0;i<n-1;i++){
            sum+=output[i].weight;
        }
        cout << sum << endl;
    }
}