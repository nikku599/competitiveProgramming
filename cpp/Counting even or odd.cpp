#include<bits/stdc++.h>
using namespace std;

struct node {
    int num_of_odd , num_of_even;
};

void buildTree (int* arr, node* tree, int start, int end, int tree_node) {
    if (start == end) {
        if (arr[start] % 2 == 0) {
            tree[tree_node].num_of_even = 1;
            tree[tree_node].num_of_odd = 0;
        } else {
            tree[tree_node].num_of_even = 0;
            tree[tree_node].num_of_odd = 1;
        }
        return;
    }
    int mid = (start+end)/2;
    buildTree(arr,tree,start,mid,2*tree_node);
    buildTree(arr,tree,mid+1,end,2*tree_node+1);
    node left = tree[2*tree_node];
    node right = tree[2*tree_node+1];
    tree[tree_node].num_of_odd = left.num_of_odd + right.num_of_odd;
    tree[tree_node].num_of_even = left.num_of_even + right.num_of_even;
    return;
}

node util (node x, node y) {
    node temp;
    temp.num_of_odd = x.num_of_odd + y.num_of_odd;
    temp.num_of_even = x.num_of_even + y.num_of_even;
    return temp;
}

node query(node* tree, int start, int end, int tree_node, int left, int right) {
    // Completely outside the given range
    node temp;
    temp.num_of_odd = 0;
    temp.num_of_even = 0;
    if (end < left || start > right)
    return temp;
    // completely inside the range
    if (left <= start && right >= end)
    return tree[tree_node];
    // partially outside and partialy inside the range 
    int mid = (start+end)/2;
    node ans1 = query(tree,start,mid,tree_node*2,left,right);
    node ans2 = query(tree,mid+1,end,2*tree_node+1,left,right);
    return util (ans1, ans2);
}

void update (int* arr, node* tree, int start, int end, int tree_node, int index, int value) {
    if (start == end) {
        if (value % 2 == 0) {
            tree[tree_node].num_of_even = 1;
            tree[tree_node].num_of_odd = 0;
        } else {
            tree[tree_node].num_of_odd = 1;
            tree[tree_node].num_of_even = 0;
        }
        return;
    }
    int mid = (start + end)/2;
    if (index <= mid);
    update(arr, tree, start, mid, 2*tree_node, index, value);
    else
    update(arr, tree,mid+1,end,2*tree_node+1,index, value);
    node left = tree[2*tree_node];
    node right = tree[2*tree_node+1];
    tree[tree_node].num_of_even = left.num_of_even + right.num_of_even;
    tree[tree_node].num_of_odd = left.num_of_odd + right.num_of_odd;
    return;
}

int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i=0;i<n;i++)
    cin >> arr[i];
    node* tree = new node [4*n];
    buildTree(arr, tree, 0, n-1, 1);
    int q;
    cin >> q;
    while(q--) {
        int action;
        cin >> action;
        if (action == 1) {
            // find even numbers
            int left, right;
            cin >> left >> right;
            node ans= query (tree, 0, n-1, 1, left-1, right-1);
            cout << ans.num_of_even << endl;

        } else if (action == 2) {
            //find odd numbers
            int left, right;
            cin >> left >> right;
            node ans= query (tree, 0, n-1, 1, left-1, right-1);
            cout << ans.num_of_odd << endl;
        } else if (action == 0) {
            // update function
            int index, value;
            cin << index << value;
            update(arr,tree,0,n-1,1,index,value);
        }
    }
    
}