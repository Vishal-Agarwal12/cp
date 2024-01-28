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
    ll n, k;
    cin>>n>>k;

    vector<ll> par;
    vector<pair<ll, pair<ll, ll>>> edg;
    for(int i=0;i<k;i++) {
        ll u, v, w;
        cin>>u>>v>>w;
        edg.pb({w, {u, v}});
    }
    sort(all(edg));

    ll comp;
    auto find_sets = [&](auto &&self, ll v) -> ll {
        if(v == par[v]) return v;
        return par[v] = self(self, par[v]);
    };

    auto union_sets = [&](ll u, ll v) -> void {
        ll a = find_sets(find_sets, u);
        ll b = find_sets(find_sets, v);
        if(a!=b) {
            par[b] = a;
            comp--;
        }
    };
    // cout<<edg;

    for(int i=0;i<k;i++) {
        par.resize(n+1);
        for(int j=1;j<=n;j++) par[j] = j;
        comp = n;

        for(int j=i;j<k;j++) {
            union_sets(edg[j].se.fi, edg[j].se.se);
            if(comp == 1) {
                cout<<edg[j].fi<<endl;
                return;
            }
        }
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
