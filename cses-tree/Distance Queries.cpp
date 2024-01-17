#include <bits/stdc++.h>
using namespace std;
 
#ifndef ONLINE_JUDGE
#include "debug.h"
#endif
 
using ll = long long;
#define pb push_back
 
void solve()
{
    ll n, q;
    cin >> n >> q;
 
    vector<vector<ll>> adj(n + 1);
    for (ll i = 0; i < n - 1; i++) {
        ll x, y;
        cin >> x >> y;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    ll l = ceil(log2(n));
 
    vector<ll> lev(n + 1);
    vector<vector<ll>> up(n + 1, vector<ll>(21));
    auto dfs = [&](auto&& self, ll node, ll par = -1, ll lvl = 0) -> void {
        lev[node] = lvl;
        up[node][0] = par;
        for (int i = 1; i <= 20; i++) {
            up[node][i] = up[up[node][i - 1]][i - 1];
        }
        for (auto it : adj[node]) {
            if (it != par) {
                self(self, it, node, lvl + 1);
            }
        }
    };
    dfs(dfs, 1,0);
 
    //auto binary_lifting = [&](auto&& self, ll node, ll par = -1) -> void {
    //    up[node][0] = par;
    //    for (int i = 1; i <= 20; i++) {
    //        up[node][i] = up[up[node][i - 1]][i - 1];
    //    }
    //    auto& adjv = adj[node];
    //    for (auto it : adjv) {
    //        if (it != par)
    //            self(self, it, node);
    //    }
    //};
    //binary_lifting(binary_lifting, 1, 0);
 
    // auto lift_node = [&](auto &&self, ll node, ll jump_required) -> ll {
    //     for(int i=l-1;i>=0;i--) {
    //         if(jump_required & (1<<i)) node = up[node][i];
    //     }
    //     return node;
    // };
 
    auto LCA = [&](auto&& self, ll u, ll v) -> ll {
        if (lev[u] < lev[v]) {
            swap(u, v);
        }
 
        ll diff = lev[u] - lev[v];
        for (int i = l - 1; i >= 0; i--) {
            if (diff & (1 << i)) u = up[u][i];
        }
        if (u == v) return u;
 
        for (int i = 20; i >= 0; i--) {
            if (up[u][i] != up[v][i]) {
                u = up[u][i];
                v = up[v][i];
            }
        }
        return up[u][0];
    };
 
 
    while (q--) {
        ll x, y;
        cin >> x >> y;
 
        ll lca = LCA(LCA, x, y);
        cout << lev[x] + lev[y] - 2 * lev[lca] << endl;
    }
}
 
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    solve();
 
    return 0;
}
