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
#define pw(x) (1LL << (x))
#define setbits(x) __builtin_popcountll(x)
const ll Mod = 998244353;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

void solve()
{
    ll n, m;
    cin>>n>>m;

    vector<ll> par(n+1), exp(n+1), sz(n+1), lazy(n+1);
    vector<vector<ll>> members(n+1);
    for(int i=1;i<=n;i++) {
        par[i] = i;
        members[i].pb(i);
        sz[i] = 1;
    }

    auto find_sets = [&](auto &&self, ll v) -> ll {
        if(v == par[v]) return v;
        return self(self, par[v]);
    };

    auto union_sets = [&](ll u, ll v) -> void {
        ll a = find_sets(find_sets, u);
        ll b = find_sets(find_sets, v);
        if(a==b) return;

        if(sz[a] < sz[b]) swap(a, b); 
        for(auto it: members[b]) {
            exp[it] += lazy[b];
            exp[it] -= lazy[a];
            members[a].pb(it);
        }
        members[b].clear();
        par[b] = a;
        sz[a] += sz[b];
    };

    ll x, y;
    while(m--) {
        string s;
        cin>>s;

        if(s == "join") {
            cin>>x>>y;
            union_sets(x, y);
        }
        else if(s == "add") {
            cin>>x>>y;
            ll a = find_sets(find_sets, x);
            lazy[a] += y;
        }
        else {
            cin>>x;
            ll a = find_sets(find_sets, x);
            cout<<exp[x] + lazy[a]<<nl;
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


// Make array that stores the exp gained for each person when they were root(lazy) 
// The array stores the amount of experiences gained when i was root(exp)
// the exp is sum of the answer for each parent of some node (exp + lazy)
