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
    ll n, m, s;
    cin>>n>>m>>s;

    
    vector<pair<ll, pair<ll, ll>>> edg;
    map<pair<ll ,ll>, ll> mp;
    for(int i=0;i<m;i++) {
        ll u, v, w;
        cin>>u>>v>>w;
        edg.pb({w, {u, v}});
        mp[{u, v}] = i+1;
    }

    vector<ll> par(n+1);
    for(int i=1;i<=n;i++) par[i] = i;

    auto find_sets = [&](auto &&self, ll v) -> ll {
        if(v == par[v]) return v;
        return par[v] = self(self, par[v]);
    };

    ll comp = n;
    auto union_sets = [&](ll u, ll v) -> void {
        ll a = find_sets(find_sets, u);
        ll b = find_sets(find_sets, v);
        if(a != b) {
            par[b] = a;
            comp--;
        }
    };

    sort(rall(edg));
    vector<pair<ll, pair<ll, ll>>> wgh;
    for(int i=0;i<m;i++) {
        ll a = find_sets(find_sets, edg[i].se.fi);
        ll b = find_sets(find_sets, edg[i].se.se);
        if(a!=b) {
            union_sets(a, b);
        }
        else {
            wgh.pb({edg[i].fi, {edg[i].se.fi, edg[i].se.se}});
        }
        if(comp == 1) {
            for(int j=i+1;j<m;j++) wgh.pb({edg[j].fi, {edg[j].se.fi, edg[j].se.se}});
            break;
        }
    }
    
    sort(all(wgh));
    vector<ll> ans;
    // cout<<wgh;
    ll sum = 0;
    for(int i=0;i<wgh.size();i++) {
        if(sum + wgh[i].fi <= s) {
            ans.pb(mp[{wgh[i].se.fi, wgh[i].se.se}]);
            sum += wgh[i].fi;
        }
    }
    cout<<ans.size()<<nl;
    for(auto x: ans) cout<<x<<" ";
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
