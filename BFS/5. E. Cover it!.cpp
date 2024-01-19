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

    vector<vector<ll>> adj(n+1);
    for(int i=0;i<m;i++) {
        ll u, v;
        cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    vector<ll> dis(n+1);
    vector<bool> vis(n+1);
    queue <ll> q;
    q.push(1);
    vis[1] = true;

    while(!q.empty()) {
        ll ss = q.size();
        for(int i=0;i<ss;i++) {
            ll node = q.front();
            q.pop();
            for(auto it: adj[node]) {
                if(!vis[it]) {
                    vis[it] = true;
                    q.push(it);
                    dis[it] = dis[node]+1;
                }
            }
        }
    }
    // cout<<dis;
    vector<ll> ev, od;
    for(int i=1;i<=n;i++) {
        if(dis[i]%2==0) ev.pb(i);
        else od.pb(i);
    }

    if(ev.size()*2 <= n) {
        cout<<sz(ev)<<nl;
        for(auto x: ev) cout<<x<<" ";
        cout<<nl;
    }
    else {
        cout<<sz(od)<<nl;
        for(auto x: od) cout<<x<<" ";
        cout<<nl;
    }
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
