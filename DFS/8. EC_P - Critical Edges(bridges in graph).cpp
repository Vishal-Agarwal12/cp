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

ll cs=0;
void solve()
{
    ll n, m;
    cin>>n>>m;

    vector<vector<ll>> adj(n+1);
    for(int i=0;i<m;i++) {
        ll u, v;
        cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    vector<bool> vis(n+1);
    vector<ll> tin(n+1), low(n+1);

    int timer = 1;
    vector<pair<ll, ll>> bridges;
    auto dfs = [&](auto &&self, ll node, ll par = -1) -> void {
        vis[node] = 1;
        tin[node] = low[node] = timer;
        timer++;

        for(auto it: adj[node]) {
            if(it == par) continue;
            else if(vis[it]) {
                low[node] = min(low[node], tin[it]);
            }
            else {
                self(self, it, node);
                low[node] = min(low[node], low[it]);
                if(low[it] > tin[node]) {
                    bridges.pb({min(it, node), max(it, node)});
                }
            }
        }
    };

    dfs(dfs, 1);

    sort(all(bridges));
    cs++;
    cout<<"Caso #"<<cs<<nl;
    if(bridges.size() == 0) {
        cout<<"Sin bloqueos"<<nl;
        return;
    }
    cout<<bridges.size()<<nl;
    for(auto [x, y]: bridges) {
        cout<<x<<" "<<y<<nl;
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    //freopen("input.txt", "rt", stdin);
    //freopen("output.txt", "wt", stdout);

    int T;
    cin>>T;
    while(T--)
        solve();

    return 0;
}
