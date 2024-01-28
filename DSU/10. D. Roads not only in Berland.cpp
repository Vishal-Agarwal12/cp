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

    vector<ll> par(n+1);
    for(int i=1;i<=n;i++) par[i] = i;

    auto find = [&](auto &&self, ll v) -> ll {
        if(v == par[v]) return v;
        return par[v] = self(self, par[v]);
    };

    auto unite = [&](ll u, ll v) -> void {
        ll a = find(find, u);
        ll b = find(find, v);
        if(a!=b) par[b] = a;
    };

    vector<pair<ll, ll>> toRemove;
    for(int i=0;i<n-1;i++) {
        ll x, y;
        cin>>x>>y;

        ll a = find(find, x);
        ll b = find(find, y);
        if(a==b) {
            toRemove.pb({x, y});
        }
        else unite(x, y);
    }

    vector<pair<ll, ll>> toAdd;
    for(int i=2;i<=n;i++) {
        ll a = find(find, 1);
        ll b = find(find, i);

        if(a!=b) {
            toAdd.pb({1, i});
            unite(1, i);
        }
    }

    cout<<toAdd.size()<<nl;
    for(int i=0;i<toAdd.size();i++) {
        cout<<toRemove[i].fi<<" "<<toRemove[i].se<<" "<<toAdd[i].fi<<" "<<toAdd[i].se<<nl;
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
