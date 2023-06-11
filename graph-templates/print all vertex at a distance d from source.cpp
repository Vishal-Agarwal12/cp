    // Problem Link
    https://atcoder.jp/contests/abc305/tasks/abc305_e

#include <bits/stdc++.h>
#define ll int
using namespace std;

void solve()
{
    ll n, m, k, x, y, p, h;
    cin >> n >> m >> k;

    vector<vector<ll>> adj(n);
    for (ll i = 0; i < m; i++)
    {
        cin >> x >> y;
        --x;
        --y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    vector<ll> val(n, -1);
    vector<bool> vis(n, false);

    priority_queue<pair<ll, ll>> pq;
    for (ll i = 0; i < k; i++)
    {
        cin >> p >> h;
        --p;
        val[p] = max(val[p], h);
    }

    for (int i = 0; i < n; i++)
    {
        if (val[i] != -1)
            pq.emplace(val[i], i);
    }

    while (!pq.empty())
    {
        ll d = pq.top().first;
        ll v = pq.top().second;
        pq.pop();
        if (vis[v] == true)
            continue;
        vis[v] = true;
        if (d == 0)
            continue;

        for (auto u : adj[v])
        {
            if (val[u] < d - 1)
            {
                val[u] = d - 1;
                pq.emplace(val[u], u);
            }
        }
    }

    vector<ll> res;
    for (ll i = 0; i < n; i++)
    {
        if (vis[i])
        {
            res.push_back(i);
        }
    }
    cout << res.size() << endl;
    for (auto x : res)
        cout << x + 1 << " ";
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
