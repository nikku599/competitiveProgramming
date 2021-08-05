#include<bits/stdc++.h>

using namespace std;

struct node {
    int maximum, smaximum;
};

void buildTree(int * arr, node * tree, int treeNode, int start, int end) {
    if (start == end) {
        tree[treeNode].maximum = arr[start];
        tree[treeNode].smaximum = INT_MIN;
        return;
    }
    int mid = (start + end) / 2;
    buildTree(arr, tree, 2 * treeNode, start, mid);
    buildTree(arr, tree, 2 * treeNode + 1, mid + 1, end);
    node left = tree[2 * treeNode];
    node right = tree[2 * treeNode + 1];
    tree[treeNode].maximum = max(left.maximum, right.maximum);
    tree[treeNode].smaximum = min(max(left.smaximum, right.maximum), max(left.maximum, right.smaximum));
    return;
}

node util(node x, node y) {
    node temp;
    temp.maximum = max(x.maximum, y.maximum);
    temp.smaximum = min(max(x.maximum, y.smaximum), max(x.smaximum, y.maximum));
    return temp;
}

node query(node * tree, int start, int end, int treeNode, int left, int right) {
    // Completely outside the given range
    node temp;
    temp.maximum = -1;
    temp.smaximum = -1;
    if (end < left || start > right) {
        return temp;
    }
    // completely inside the range
    if (left <= start && right >= end)
        return tree[treeNode];
    // partially outside and partialy inside the range 
    int mid = (start + end) / 2;
    node ans1 = query(tree, start, mid, treeNode * 2, left, right);
    node ans2 = query(tree, mid + 1, end, 2 * treeNode + 1, left, right);
    return util(ans1, ans2);
}

void update(node * tree, int * arr, int start, int end, int treeNode, int index, int value) {
    if (start == end) {
        tree[treeNode].maximum = value;
        tree[treeNode].smaximum = INT_MIN;
        arr[index] = value;
        return;
    }
    int mid = (start + end) / 2;
    if (index > mid)
        update(tree, arr, mid + 1, end, 2 * treeNode + 1, index, value);
    else
        update(tree, arr, start, mid, 2 * treeNode, index, value);
    node left = tree[2 * treeNode];
    node right = tree[2 * treeNode + 1];
    tree[treeNode].maximum = max(left.maximum, right.maximum);
    tree[treeNode].smaximum = min(max(left.maximum, right.smaximum), max(left.smaximum, right.maximum));
    return;
}

int main() {
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    node * tree = new node[4 * n];
    buildTree(arr, tree, 1, 0, n - 1);
    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        char x;
        cin >> x;
        if (x == 'Q') {
            int i, j;
            cin >> i >> j;
            node ans = query(tree, 0, n - 1, 1, i - 1, j - 1);
            cout << ans.maximum + ans.smaximum << endl;
        }
        if (x == 'U') {
            int index, value;
            cin >> index >> value;
            update(tree, arr, 0, n - 1, 1, index - 1, value);
        }
    }
}