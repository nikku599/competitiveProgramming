#include<bits/stdc++.h>
using namespace std;

void buildSegmentedTree (int* arr, int* tree, int start, int end, int treeNode) {
    if(start == end) {
        tree[treeNode] = arr[start];
        return;
    }
    int mid = (start + end) / 2;
    buildSegmentedTree (arr, tree, start, mid, 2 * treeNode);
    buildSegmentedTree (arr, tree, mid + 1, end, 2 * treeNode + 1);
    tree[treeNode] = tree[2*treeNode] + tree[2*treeNode+1];
}

void updateTree (int* arr, int* tree, int start, int end, int treeNode, int idx, int value) {
    if(start == end) {
        tree[treeNode] = value;
        arr[idx] = value;
        return;
    }
    int mid = (start+end)/2;
    if(idx > mid)
        updateTree(arr, tree, mid+1, end, 2*treeNode+1, idx, value);
    else
        updateTree(arr, tree, start, mid, 2*treeNode, idx, value);
    tree[treeNode] = tree[2*treeNode] + tree[2*treeNode+1];
}

int query (int* tree, int start, int end, int treeNode, int left, int right) {
    // Completely outside the given range
    if (end < left || start > right)
    return 0;
    // completely inside the range
    if (left <= start && right >= end)
    return tree[treeNode];
    // partially outside and partialy inside the range 
    int mid = (start+end)/2;
    int ans1 = query(tree,start,mid,treeNode*2,left,right);
    int ans2 = query(tree,mid+1,end,2*treeNode+1,left,right);
    return ans1+ans2;
}

int main(){
    int arr[] = {1,2,3,4,5,6,7,8,9};
    int* tree = new int[18];
    
    buildSegmentedTree (arr, tree, 0, 8, 1);
    updateTree(arr,tree,0,8,1,2,10);

    for(int i=1;i<18;i++) {
        cout << tree[i] << endl;
    }

    int ans = query(tree,0,8,1,2,4);
    cout << "sum of the arr with the interval (2,4) : "<< ans <<endl;

}