// https://codeforces.com/problemset/problem/1702/E

// Author: Vishal 
// Created: 2024-02-26 15:09:03

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
    map<ll, ll> d;
    ll fg = 0;
    for(int i=0;i<n;i++) {
    	ll x,y;
    	cin>>x>>y;
    	if(x==y) fg=1;
    	adj[x].pb(y);
    	adj[y].pb(x);
    	d[x]++;
    	d[y]++;
    }
    
    if(fg) {
    	cout<<"NO"<<nl;
    	return;
    }
    
    for(auto [x,y]: d) {
    	if(y>2) {
    		cout<<"NO"<<nl;
    		return;
    	}
    }
    vector<ll> vis(n+1);
    vector<ll> col(n+1);
    bool ans = true;
    auto dfs = [&](auto &&self, ll i, ll c) -> void {
    	vis[i] = 1;
    	col[i] = c;
    	for(auto it: adj[i]) {
    		if(!vis[it]) {
    			self(self, it, c^1);
    		}
    		else {
    			if(col[it] == col[i]) {
    				ans = false;
    			}
    		}
    	}
    };
    
    for(int i=1;i<=n;i++) {
    	if(!vis[i]) {
    		dfs(dfs, i, 0);
    	}
    }
    
    if(ans) cout<<"YES"<<nl;
    else cout<<"NO"<<nl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    //freopen("input.txt", "rt", stdin);
    //freopen("output.txt", "wt", stdout);

    int T;
    cin>>T;
    while(T--)
        solve();

    return 0;
}

