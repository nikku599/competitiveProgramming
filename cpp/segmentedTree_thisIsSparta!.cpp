#include<bits/stdc++.h>
using namespace std;

struct node {
    int strength, cowardice, element_index;
};

void buildTree (int* s, int* c, node* tree, int start, int end, int tree_node) {
    if (start == end) {
        tree[tree_node].element_index = start;
        tree[tree_node].strength = s[start];
        tree[tree_node].cowardice = c[start];
        return;
    }
    int mid = (start+end)/2;
    buildTree(s,c,tree,start,mid,2*tree_node);
    buildTree(s,c,tree,mid+1,end,2*tree_node+1);
    node left = tree[2*tree_node];
    node right = tree[2*tree_node+1];
    if (left.strength > right.strength) {
        tree[tree_node].strength = left.strength;
        tree[tree_node].element_index = left.element_index;
        tree[tree_node].cowardice = left.cowardice;
    } else if (right.strength > left.strength) {
        tree[tree_node].strength = right.strength;
        tree[tree_node].element_index = right.element_index;
        tree[tree_node].cowardice = right.cowardice;
    } else if (left.strength == right.strength) {
        if (left.cowardice < right.cowardice) {
            tree[tree_node].strength = left.strength;
            tree[tree_node].element_index = left.element_index;
            tree[tree_node].cowardice = left.cowardice;
        } else if (left.cowardice > right.cowardice) {
            tree[tree_node].strength = right.strength;
            tree[tree_node].element_index = right.element_index;
            tree[tree_node].cowardice = right.cowardice;
        } else if (left.cowardice == right.cowardice) {
            tree[tree_node].strength = left.strength;
            tree[tree_node].element_index = left.element_index;
            tree[tree_node].cowardice = left.cowardice;
        }
    }
    return;
}

node util (node x, node y) {
    node temp;
    if (x.strength > y.strength) {
        temp.strength = x.strength;
        temp.element_index = x.element_index;
        temp.cowardice = x.cowardice;
    } else if (y.strength > x.strength) {
        temp.strength = y.strength;
        temp.element_index = y.element_index;
        temp.cowardice = y.cowardice;
    } else if (x.strength == y.strength) {
        if (x.cowardice < y.cowardice) {
            temp.strength = x.strength;
            temp.element_index = x.element_index;
            temp.cowardice = x.cowardice;
        } else if (x.cowardice > y.cowardice) {
            temp.strength = y.strength;
            temp.element_index = y.element_index;
            temp.cowardice = y.cowardice;
        } else if (x.cowardice == y.cowardice) {
            temp.strength = x.strength;
            temp.element_index = x.element_index;
            temp.cowardice = x.cowardice;
        }
    }
    return temp;
}

node query (node* tree, int start, int end, int tree_node, int left, int right) {
    node temp;
    temp.strength = INT_MIN;
    temp.cowardice = INT_MAX;
    temp.element_index = -1;
    if (end < left || start > right) {
        return temp;
    }
    if (left <= start && right >= end) {
        return tree[tree_node];
    }
    int mid = (start+end)/2;
    node ans1 = query(tree,start,mid,2*tree_node,left,right);
    node ans2 = query(tree,mid+1,end,2*tree_node+1,left,right);
    return util(ans1, ans2);
}


int main(){
    int n;
    cin >> n;
    int* s = new int[n];
    int* c = new int[n];
    for (int i=0;i<n;i++)
    cin >> s[i];
    for (int i=0;i<n;i++)
    cin >> c[i];

    node* tree = new node[4*n];
    buildTree (s,c,tree,0,n-1,1);
    // for (int i=0;i<4*n;i++){
    //     cout << tree[i].strength <<","<<tree[i].cowardice<<","<<tree[i].element_index << endl;
    // }
    int q;
    cin >> q;
    while(q--) {
        int left, right;
        cin >> left >> right;
        node ans = query(tree,0,n-1,1,left,right);
        cout << ans.element_index << endl;
    }
}