#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int MOD = 1000000007;

ll fastpow(ll a, ll b, ll mod)
{
    ll res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = (res * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return res;
}

void solve()
{
    long long a, b, c;
    cin >> a >> b >> c;

    cout << fastpow(a, fastpow(b, c, MOD - 1), MOD) << endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
        solve();

    return 0;
}
