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

    vector<vector<pair<ll, ll>>> adj(n+1);
    vector<ll> d(n+1, inf), p(n+1, -1);

    for(int i=0;i<m;i++) {
        ll u, v, w;
        cin>>u>>v>>w;
        adj[u].pb({v, w});
        adj[v].pb({u, w});
    }

    using pii = pair<ll, ll>;
    priority_queue<pii, vector<pii>, greater<pii>> q;
    d[1] = 0;
    q.push({0 ,1});

    while(!q.empty()) {
        ll v = q.top().se;
        ll d_v = q.top().fi;
        q.pop();

        if(d_v != d[v]) continue;

        for(auto it: adj[v]) {
            ll len = it.se;
            ll to = it.fi;
            if(d[v] + len < d[to]) {
                d[to] = d[v] + len;
                p[to] = v;
                q.push({d[to], to});
            }
        }
    }
    // cout<<d;

    if(p[n] == -1) {
        cout<<-1<<nl;
        return;
    }

    vector<ll> ans;
    ans.pb(n);
    ll tmp = n;
    while(true) {
        ans.pb(p[tmp]);
        tmp = p[tmp];
        if(tmp == 1) break;
    }
    
    reverse(all(ans));
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
