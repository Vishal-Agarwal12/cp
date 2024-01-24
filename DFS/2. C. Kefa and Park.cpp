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

    vector<ll> v(n+1);
    for(int i=1;i<=n;i++) cin>>v[i];

    vector<vector<ll>> adj(n+1);
    vector<ll> deg(n+1);
    for(int i=0;i<n-1;i++) {
        ll u, v;
        cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u);
        deg[u]++;
        deg[v]++;
    }

    deg[1]=2;
    ll ans = 0;
    auto dfs = [&](auto &&self, ll node, ll par = -1, ll cat) -> void {
        if(cat > m) return;

        for(auto it: adj[node]) {
            if(it != par) {
                if(v[it]) self(self, it, node, cat+1);
                else self(self, it, node, 0);
            }
        }
        if(deg[node] == 1) ans++;
        return;
    };
    
    dfs(dfs, 1, -1, v[1]);
    cout<<ans<<nl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    //freopen("input.txt", "rt", stdin);
    //freopen("output.txt", "wt", stdout);

    solve();

    return 0;
}
