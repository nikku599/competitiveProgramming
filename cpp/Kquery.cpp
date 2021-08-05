#include<bits/stdc++.h>
using namespace std;

class Event{
    public:
        long long value;
        int left, right, index;
};

bool compare (Event a, Event b) {
    if(a.value == b.value)
        return a.left > b.left;
    else
        return a.value > b.value;
}

int query(int index, int* bit) {
    int count = 0;
    for(;index>0;index-=index&(-index)){
        count += bit[index];
    }
    return count;
}

void update (int index, int* bit, int n) {
    for(;index<=n;index+=index&(-index)){
        bit[index]++;
    }
}
void solveQuery (long long* arr, int n, int* left, int* right, long long* k, int q) {
    Event a[n+q+1]; // 1 indexing
    for (int i=1;i<=n;i++){
        a[i].left = 0;
        a[i].right = i;
        a[i].index = 0;
        a[i].value = arr[i-1];
    }
    for (int i=n+1; i<=n+q; i++){
        a[i].left = left[i-n-1];
        a[i].right = right[i-n-1];
        a[i].index = i - n;
        a[i].value = k[i-n-1];
    }
    sort(a+1,a+n+q+1,compare);

    int bit[n+1];
    memset(bit, 0, sizeof(bit));

    int ans[q+1];

    for(int i=1; i<=n+q; i++) {
        if(a[i].left != 0){
            int count = query(a[i].right,bit)-query(a[i].left-1,bit);
            ans[a[i].index] = count;
        }else{
            update(a[i].right, bit, n);
        }
    }

    for(int i=1;i<=q;i++){
        cout << ans[i] << endl;
    }


}

int main() {
    int n;
    cin>>n;
    long long* arr = new long long[n];
    for(int i=0;i<n;i++)
        cin >> arr[i];
    int q;
    cin>>q;
    int left[q], right[q];
    long long k[q];
    for (int i=0;i<q;i++){
        cin >> left[i] >> right[i] >> k[i];
    }
    solveQuery (arr, n, left, right, k, q);
}