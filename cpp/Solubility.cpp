#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
	ll t, x, aa, bombay;
	cin >> t;
	while(t--){
	    cin>>x>>aa>>bombay;
	    cout<<(aa+((100-x)*bombay))*10<<endl;
	}
	return 0;
}