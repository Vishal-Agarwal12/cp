

#include <bits/stdc++.h>
#define ll long long
using namespace std;
 
void solve()
{
    ll n, q;
    cin >> n >> q;
 
    ll a[n + 1];
 
    a[0] = 0;
    for (int i = 1; i < n + 1; i++)
    {
        ll x;
        cin >> x;
        a[i] = a[i - 1] + x;
    }
 
    for (int i = 0; i < q; i++)
    {
        ll c, d;
        cin >> c >> d;
        cout << a[d] - a[c - 1] << endl;
    }
}
 
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    solve();
 
    return 0;
}
