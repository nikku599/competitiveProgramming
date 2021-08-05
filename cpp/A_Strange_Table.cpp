#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main ()
{
    int t;
    cin >> t;
    while (t--)
    {
        __int64 n, m, x;
        cin >> n >> m >> x;
        __int64 col = (x / n) + 1;
        __int64 row = (x % n);
        if (row <= 0)
        row = 1;
        __int64 result = m * (row - 1) + col;
        cout << result << endl;
    }
}