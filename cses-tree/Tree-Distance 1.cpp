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
 
    ll node1 = -1, mx = -1;
    auto dfs = [&](auto &&self, ll node, ll par = -1, ll lvl = 0) -> void {
        if(lvl > mx) {
            mx = lvl;
            node1 = node;
        }
        for(auto it: adj[node]) {
            if(it != par) {
                self(self, it, node, lvl+1);
            }
        }
    };
    dfs(dfs, 1);
    ll node2 = node1;
    dfs(dfs, node1);
    // cout<<node1<<" "<<node2<<endl;
 
    vector<ll> dis(n+1);
    auto dfs1 = [&](auto &&self, ll node, ll par = -1, ll lvl = 0) -> void {
        dis[node] = max(lvl, mx - lvl);
        
        for(auto it: adj[node]) {
            if(it != par) {
                self(self, it, node, lvl+1);
            }
        }
    };
 
    dfs1(dfs1, node1);
    vector<ll> dis2 = dis;
    dfs1(dfs1, node2);
    
 
    for(int i=1;i<=n;i++) cout<<max(dis[i], dis2[i])<<" ";
    cout<<endl;
}
 
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    solve();
 
    return 0;
}
