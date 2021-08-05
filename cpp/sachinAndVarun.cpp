#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

class Triplet {
	public:
		ll x;
		ll y;
		ll gcd;
};

Triplet extendedEuclid (ll a, ll b) {
	if (b == 0) {
		Triplet ans;
		ans.gcd = a;
		ans.x = 1;
		ans.y = 0;
		return ans;
	}
	Triplet smallAns = extendedEuclid (b, a % b);
	Triplet ans;
	ans.gcd = smallAns.gcd;
	ans.x = smallAns.y;
	ans.y = smallAns.x - ((a / b) * smallAns.y);
	return ans;
}

ll modInverse (ll a, ll m) {
	ll val = extendedEuclid (a, m).x;
	return (val % m + m) % m;
}


int main(){
    int t;
    cin>>t;
    while(t--){
        ll a, b, d;
		cin>>a>>b>>d;
		ll g=__gcd(a,b);
		if (d % g) {
			cout << 0 << endl;
			continue;
		}

		if (d == 0) {
			cout << 1 << endl;
			continue;
		}
		
		a/=g;
		b/=g;
		d/=g;


		ll y1 = ((d % a) * modInverse (b, a)) % a;
		ll firstValue = d / b;
		
		if (d < y1 * b) {
			cout << 0 << endl;
			continue;
		}

		ll n = (firstValue - y1) / a;
		cout << n + 1 << endl;

    }
    return 0;
}