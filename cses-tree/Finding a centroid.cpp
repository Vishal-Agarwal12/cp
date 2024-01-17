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
    ll n;
    cin>>n;
    vector<vector<ll>> adj(n+1);
    for(int i=0;i<n-1;i++) {
        ll u,v;
        cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    vector<ll> dp(n+1);
    auto dfs = [&](auto &&self, ll node, ll par = -1) -> void {
        dp[node] = 1;
        for(auto it: adj[node]) {
            if(it != par) {
                self(self, it, node);
                dp[node] += dp[it];
            }
        }
    };
    dfs(dfs, 1);

    auto getcentroid = [&](auto &&self, ll node, ll par = -1) -> ll {
        for(auto it: adj[node]) {
            if(it != par) {
                if(dp[it]*2 > n) return self(self, it, node);
            }
        }
        return node;
    };
    
    cout<<getcentroid(getcentroid, 1);
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
