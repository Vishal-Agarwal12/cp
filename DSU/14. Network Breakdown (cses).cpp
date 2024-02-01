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
    ll n, m, k;
    cin>>n>>m>>k;
    set<pair<ll, ll>> s;
    vector<pair<ll, ll>> q;

    for(int i=0;i<m;i++) {
        ll u, v;
        cin>>u>>v;
        if(u > v) swap(u,v);
        s.insert({u, v});
    }
    for(int i=0;i<k;i++) {
        ll u, v;
        cin>>u>>v;
        if(u > v) swap(u,v);
        q.pb({u, v});
        if(s.count({u, v})) s.erase({u, v});
    }

    vector<ll> par(n+1);
    for(int i=1;i<=n;i++) par[i] = i;

    ll comp = n;
    auto find = [&](auto &&self, ll v) -> ll {
        if(v == par[v]) return v;
        return par[v] = self(self, par[v]);
    };

    auto unite = [&](ll u, ll v) -> void {
        ll a = find(find, u);
        ll b = find(find, v);

        if(a != b) {
            par[b] = a;
            comp--;
        }
    };

    for(auto [x, y]: s) {
        unite(x, y);
    }
    vector<ll> ans;
    ans.pb(comp);

    reverse(all(q));
    for(int i=0;i<k-1;i++) {
        unite(q[i].fi, q[i].se);
        ans.pb(comp);
    }

    reverse(all(ans));
    for(int i=0;i<k;i++) {
        cout<<ans[i]<<" ";
    }
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
