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
    cin >> n >> m >> k;

    vector<pair<ll, ll>> vi(m);
    for (int i = 0; i < m; i++) {
        cin>>vi[i].fi>>vi[i].se;
    }

    vector<string> v(k);
    vector<pair<ll, ll>> vp(k);

    for (int i = 0; i < k; i++) {
        cin >> v[i];
        cin >> vp[i].fi >> vp[i].se;
    }

    reverse(all(v));
    reverse(all(vp));

    vector<ll> par(n + 1);
    for (int i = 1; i <= n; i++)
        par[i] = i;

    auto find_sets = [&](auto &&self, ll v) -> ll {
        if (v == par[v])
            return v;
        return par[v] = self(self, par[v]);
    };

    auto union_sets = [&](ll x, ll y) -> void {
        ll a = find_sets(find_sets, x);
        ll b = find_sets(find_sets, y);
        if (a != b) {
            par[b] = a;
        }
    };

    vector<string> ans;
    for (int i = 0; i < k; i++) {
        if (v[i] == "ask") {
            ll a = find_sets(find_sets, vp[i].fi);
            ll b = find_sets(find_sets, vp[i].se);
            if (a == b)
                ans.pb("YES");
            else
                ans.pb("NO");
        } else {
            union_sets(vp[i].fi, vp[i].se);
        }
    }

    reverse(all(ans));
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << "\n";
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
