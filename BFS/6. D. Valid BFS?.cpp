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
    
    vector<vector<ll>> adj(n+1);
    for(int i=0;i<n-1;i++) {
        ll u,v;
        cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    vector<ll> v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    // cout<<v;
    map<ll, ll> mp;
    for(ll i=0;i<n;i++) mp[v[i]] = i;

    for(int i=1;i<=n;i++) {
        vector<pair<ll, ll>> vc;
        for(int j=0;j<adj[i].size();j++) {
            vc.pb({mp[adj[i][j]], adj[i][j]});
        }
        sort(all(vc));
        for(int j=0;j<adj[i].size();j++) {
            adj[i][j] = vc[j].se;
        } 
    }
    // cout<<adj;

    queue<ll> q;
    q.push(1);
    vector<ll> ans;
    ans.pb(1);
    vector<bool> vis(n+1);

    while(!q.empty()) {
        ll ss = q.size();
        for(int i=0;i<ss;i++) {
            ll node = q.front();
            q.pop();
            vis[node] = true;
            for(auto it: adj[node]) {
                if(!vis[it]) {
                    q.push(it);
                    vis[it] = true;
                    ans.pb(it);
                }
            }
        }
    }
    if(v == ans) {
        cout<<"Yes"<<nl;
    }
    else cout<<"No"<<nl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
