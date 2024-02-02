#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
#include "debug.h"
#endif

using ll = long long;
using maxheap = priority_queue<ll>; // maxheap
using minheap = priority_queue<ll, vector<ll>, greater<ll>>; // minheap
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define sort_and_unique(a) \
    sort(all(a));          \
    (a).resize(unique(all(a)) - (a).begin())
#define minv(a) *min_element(all(a))
#define maxv(a) *max_element(all(a))
#define pb push_back
#define eb emplace_back
#define fi first
#define nl '\n'
#define se second
#define ins insert
#define sz(x) ((int)(x).size())
#define pw(x) (1LL << (x))
#define setbits(x) __builtin_popcountll(x)
const ll Mod = 998244353;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

void solve()
{
    ll n, m;
    cin>>n>>m;

    vector<vector<ll>> adj(n+1), rev_adj(n+1);
    for(int i=0;i<m;i++) {
        ll u, v;
        cin>>u>>v;
        adj[u].pb(v);
        rev_adj[v].pb(u);
    }

    vector<ll> order;
    vector<bool> vis(n+1);
    auto dfs1 = [&](auto &&self, ll node) -> void {
        vis[node] = true;
        for(auto it: adj[node]) {
            if(!vis[it]) self(self, it);
        }
        order.pb(node);
    };

    for(int i=1;i<=n;i++) {
        if(!vis[i]) {
            dfs1(dfs1, i);
        }
    }

    reverse(all(order));

    vector<vector<ll>> comp;
    vector<ll> cmp;
    vis.clear();
    vis.resize(n+1);

    auto dfs2 = [&](auto &&self, ll node) -> void {
        vis[node] = true;
        cmp.pb(node);
        for(auto it: rev_adj[node]) {
            if(!vis[it]) self(self, it);
        }
    };

    for(auto x: order) {
        if(!vis[x]) {
            cmp.clear();
            dfs2(dfs2, x);
            comp.pb(cmp);
        }
    }
    vector<ll> ans(n+1);
    for(int i=0;i<comp.size();i++) {
        for(int j=0;j<comp[i].size();j++) {
            ans[comp[i][j]] = i+1;
        }
    }
    cout<<comp.size()<<nl;
    for(int i=1;i<=n;i++) cout<<ans[i]<<" ";
    cout<<nl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    //freopen("input.txt", "rt", stdin);
    //freopen("output.txt", "wt", stdout);

    solve();

    return 0;
}
