#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void buildSegmentedTree (ll* tree, ll* arr, int start, int end, int treeNode) {
    if (start == end){
        tree[treeNode] = arr[start];
        return;
    }
    int mid = (start+end)/2;
    buildSegmentedTree(tree, arr, start, mid, 2 * treeNode);
    buildSegmentedTree(tree, arr, mid+1, end, 2 * treeNode + 1);
    tree[treeNode] = min (tree[treeNode*2], tree[treeNode*2 + 1]);
}

ll query (ll* tree, int start, int end, int treeNode, int left, int right) {
    if (end < left || start > right)
    return LONG_LONG_MAX;
    // completely inside the range
    if (left <= start && right >= end)
    return tree[treeNode];
    // partially outside and partialy inside the range 
    int mid = (start+end)/2;
    ll ans1 = query(tree,start,mid,treeNode*2,left,right);
    ll ans2 = query(tree,mid+1,end,2*treeNode+1,left,right);
    return min(ans1,ans2);
}

void update (ll* tree, ll* arr, int start, int end, int treeNode, int index, ll value) {
    if (start == end) {
        tree[treeNode] = value;
        arr[index] = value;
        return;
    }
    int mid = (start+end)/2;
    if (index > mid) {
        update(tree,arr,mid+1, end, 2*treeNode+1, index, value);
    } else {
        update(tree,arr,start,mid,2*treeNode,index,value);
    }
    tree[treeNode] = min (tree[treeNode*2], tree[treeNode*2 + 1]);
}

int main(){
    int n, q;
    cin >> n >> q;
    ll a[n];
    for(int i=0;i<n;i++)
        cin >> a[i];
    ll* tree = new ll[4*n];
    buildSegmentedTree(tree, a, 0, n-1, 1);
    // for(int i =1;i<4*n;i++){
    //     cout << tree[i] << endl;
    // }
    for(int i=0;i<q;i++){
        char val;
        cin >> val;
        if (val == 'q') {
            int left, right;
            cin >> left >> right;
            cout << query (tree,0,n-1,1,left-1,right-1) << endl; // 1 indexing
        }
        if (val == 'u') {
            int left; ll right;
            cin >> left>> right;
            update (tree,a,0,n-1,1,left-1,right);
        }
    }
}