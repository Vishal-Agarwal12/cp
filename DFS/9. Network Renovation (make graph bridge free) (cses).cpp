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
        ll u,v;
        cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    vector<ll> v;
    auto dfs = [&](auto &&self, ll node, ll par = -1) -> void {
        for(auto it: adj[node]) {
            if(it != par) {
                self(self, it, node);
            }
        }
        if(adj[node].size() == 1) v.pb(node);
    };

    dfs(dfs, 1);
    ll k = v.size();
    if(k%2==1) {
        v.pb(v[0]);
        k++;
    }

    cout<<k/2<<nl;
    for(int i=0;i<k/2;i++) {
        cout<<v[i]<<" "<<v[i+k/2]<<nl;
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
