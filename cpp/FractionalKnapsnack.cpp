#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, W;
    cin >>n >> W;
    double valueByWeight[n];
    int value[n], weight[n];
    for(int i=0;i<n;i++){
        cin >> value[i];
        cin >> weight[i];
        valueByWeight[i] = ((double) value[i]) / (weight[i]);
    }
    sort(valueByWeight,valueByWeight+n,greater<double>());
    int currW = 0;
    double fValue = 0;
    for(int i=0;i<n;i++){
        if(currW + weight[i] <= W){
            currW += weight[i];
            fValue += value[i];
        } else {
            int rWeight = W - currW;
            fValue += value[i] * ((double) rWeight / weight[i]);
            break;
        }
    }
    cout << fValue;
}