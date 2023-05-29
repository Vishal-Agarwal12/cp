
                                                      https://codeforces.com/contest/1831/problem/B

#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve()
{
    ll n, i, j;
    cin >> n;
    ll a[n], b[n];
    for (i = 0; i < n; i++)
        cin >> a[i];
    for (i = 0; i < n; i++)
        cin >> b[i];

    map<ll, ll> mp, mp2;
    ll maxi = 0, cnt = 1;

    for (i = 0; i < n - 1; i++)
    {
        if (a[i] == a[i + 1])
            cnt++;
        else
        {
            mp[a[i]] = max(mp[a[i]], cnt);
            cnt = 1;
        }
    }
    mp[a[i]] = max(cnt, mp[a[i]]);

    cnt = 1;
    for (i = 0; i < n - 1; i++)
    {
        if (b[i] == b[i + 1])
            cnt++;
        else
        {
            mp2[b[i]] = max(cnt, mp2[b[i]]);
            cnt = 1;
        }
    }
    mp2[b[i]] = max(cnt, mp2[b[i]]);

    for (i = 0; i < n; i++)
    {
        maxi = max(maxi, mp[a[i]] + mp2[a[i]]);
    }
    for (i = 0; i < n; i++)
    {
        maxi = max(maxi, mp[b[i]] + mp2[b[i]]);
    }

    cout << maxi << endl;
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
