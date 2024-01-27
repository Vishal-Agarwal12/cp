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

    vector<ll> par(n+1);
    for(int i=1;i<=n;i++) par[i] = i;

    vector<pair<ll, pair<ll, ll>>> edges;
    for(int i=0;i<m;i++) {
        ll u, v, w;
        cin>>u>>v>>w;
        edges.pb({w, {u, v}});
    }
    sort(all(edges));

    auto find_sets = [&](auto &&self, ll v) -> ll {
        if(v == par[v]) return v;
        return par[v] = self(self, par[v]);
    };

    auto union_sets = [&](ll u, ll v) -> void {
        ll a = find_sets(find_sets, u);
        ll b = find_sets(find_sets, v);
        if(a!=b) {
            par[b] = a;
        }
    };

    ll ans = 0;
    for(auto [w, e]: edges) {
        ll a = find_sets(find_sets, e.fi);
        ll b = find_sets(find_sets, e.se);

        if(a != b) {
            ans+=w;
            union_sets(e.fi, e.se);
        }
    }

    cout<<ans<<endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    //freopen("input.txt", "rt", stdin);
    //freopen("output.txt", "wt", stdout);

    solve();

    return 0;
}
