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
    ll n;
    cin>>n;
    
    vector<vector<ll>> adj(n+1);
    for(int i=0;i<n-1;i++) {
        ll u, v;
        cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    vector<ll> dep(n+1);
    auto dfs = [&](auto &&self, ll node, ll par = -1) -> ll {
        for(auto it: adj[node]) {
            if(it != par) {
                dep[it] = dep[node] + 1;
                self(self, it, node);
            }
        }
    };

    dfs(dfs, 1);

    ll uId = max_element(all(dep)) - dep.begin();
    dep.clear();
    dep.resize(n+1);

    dfs(dfs, uId);
    ll vId = max_element(all(dep)) - dep.begin();
    ll mx = *max_element(all(dep));
    
    vector<ll> dep1 = dep;
    dep.clear();
    dep.resize(n+1);

    dfs(dfs, vId);

    for(int i=1;i<=n;i++) {
        if(max(dep[i], dep1[i]) == mx) cout<<mx+1<<nl;
        else cout<<mx<<nl;
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    //freopen("input.txt", "rt", stdin);
    //freopen("output.txt", "wt", stdout);

    solve();

    return 0;
}
