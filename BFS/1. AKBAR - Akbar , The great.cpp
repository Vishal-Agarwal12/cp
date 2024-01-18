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
    ll n, r, m;
    cin>>n>>r>>m;

    vector<vector<ll>> adj(n+1);
    for(int i=0;i<r;i++) {
        ll u,v;
        cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    vector<pair<ll, ll>> slds;
    for(int i=0;i<m;i++) {
        ll x, y;
        cin>>x>>y;
        slds.pb({x, y});
    }

    vector<bool> vis(n+1);
    map<ll, ll> mp;
    for(int i=0;i<m;i++) {
        auto p = slds[i];
        queue<ll> q;
        q.push(p.fi);
        vis[p.fi] = true;
        set<ll> s;
        s.insert(p.fi);

        for(int i=0;i<p.se;i++) {
            ll len = q.size();
            for(int j=0;j<len;j++) {
                ll top = q.front();
                q.pop();

                for(auto it: adj[top]) {
                    if(!vis[it]) {
                        vis[it] = true;
                        q.push(it);
                        s.ins(it);
                    }
                }
            }
        }
        for(auto x: s) mp[x]++;
    }

    for(auto x: mp) {
        if(x.second > 1) {
            cout<<"No"<<nl;
            return;
        }
    }
    if(mp.size()==n) cout<<"Yes"<<nl;
    else cout<<"No"<<nl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin>>T;
    while(T--)
        solve();

    return 0;
}
