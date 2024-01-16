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
    ll n, q;
    cin>>n>>q;

    vector<vector<ll>> adj(n+1);
    for(ll i=0;i<n-1;i++) {
        ll x,y;
        cin>>x>>y;
        adj[x].pb(y);
        adj[y].pb(x);
    }

    vector<ll> lev(n+1);
    auto dfs = [&](auto &&self, ll node, ll par = -1, ll lvl = 0) -> void {
        lev[node] = lvl;
        for(auto it: adj[node]) {
            if(it != par) {
                self(self, it, node, lvl+1);
            }
        }
    };
    dfs(dfs, 1);

    vector<vector<ll>> up(n+1, vector<ll>(21, -1));
    auto binary_lifting = [&](auto &&self, ll node, ll par = -1) -> void {
        up[node][0] = par;
        for(int i=1;i<20;i++) {
            if(up[node][i-1] != -1) {
                up[node][i] = up[up[node][i-1]][i-1];
            }
            else up[node][i] = -1;
        }

        for(auto it: adj[node]) {
            if(it != par)
                self(self, it, node);
        }
    };
    binary_lifting(binary_lifting, 1);

    auto lift_node = [&](auto &&self, ll node, ll jump_required) -> ll {
        if(node == -1 || jump_required == 0) {
            return node;
        }  

        for(int i=19;i>=0;i--) {
            if(jump_required >= (1<<i)) {
                return self(self, up[node][i], jump_required - (1<<i));
            }
        }
    };

    auto LCA = [&](auto &&self, ll u, ll v) -> ll {
        if(lev[u] < lev[v]) {
            swap(u, v);
        }

        u = lift_node(lift_node, u, lev[u]-lev[v]);
        if(u == v) return u;

        for(int i=19;i>=0;i--) {
            if(up[u][i] != up[v][i]) {
                u = up[u][i];
                v = up[v][i];
            }
        }
        return lift_node(lift_node, u, 1);        // here 1 is not a power of 2, it is just printing parent of u
    };

    vector<ll> cnt(n+1, 0);
    while(q--) {
        ll u, v;
        cin>>u>>v;

        ll lca = LCA(LCA, u, v);
        cnt[u]++;
        cnt[v]++;
        cnt[lca]--;
        if(up[lca][0] != -1) cnt[up[lca][0]]--;
    }

    auto dfs2 = [&](auto &&self, ll node, ll par = -1) -> void {
        for(auto it: adj[node]) {
            if(it != par) {
                self(self, it, node);
                cnt[node] += cnt[it];
            }
        }
    };
    dfs2(dfs2, 1);

    for(int i=1;i<=n;i++) cout<<cnt[i]<<" ";
    cout<<endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
