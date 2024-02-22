// https://codeforces.com/contest/616/problem/C

// Author: Vishal 
// Created: 2024-02-21 14:03:55

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

ll dx[] = {1, -1, 0, 0};
ll dy[] = {0, 0, 1, -1};
void solve()
{
    ll n, m;
    cin>>n>>m;
    
    vector<vector<char>> g(n, vector<char> (m));
    for(int i=0;i<n;i++) {
    	for(int j=0;j<m;j++) {
    		cin>>g[i][j];
    	}
    }
    
    vector<vector<ll>> vis(n, vector<ll> (m));
    vector<vector<ll>> v(n, vector<ll> (m));
    ll id = 0;
    vector<ll> comp;
    
    auto isVal = [&](ll i, ll j) -> bool {
    	return i>=0 && i<n && j>=0 && j<m;
    };
    
    auto dfs = [&](auto &&self, ll i, ll j) -> void {
    	v[i][j] = id;
    	vis[i][j] = 1;
    	comp[id]++;
    	
    	for(int k=0;k<4;k++) {
    		ll nx = i+dx[k], ny = j+dy[k];
    		if(isVal(nx, ny) && g[nx][ny] == '.' && !vis[nx][ny]) {
    			self(self, nx, ny);
    		}
    	}
    };
    
    for(int i=0;i<n;i++) {
    	for(int j=0;j<m;j++) {
    		if(g[i][j] == '.' && !vis[i][j]) {
    			comp.pb(0);
    			dfs(dfs, i, j);
    			id++;
    		}
    	}
    }
    
    for(int i=0;i<n;i++) {
    	for(int j=0;j<m;j++) {
    		if(g[i][j] == '.') {
    			cout<<".";
    			continue;
    		}
    		set<ll> s;
    		for(int k=0;k<4;k++) {
    			ll nx = i+dx[k], ny = j+dy[k];
    			if(isVal(nx, ny) && g[nx][ny] == '.') {
    				s.insert(v[nx][ny]);
    			}
    		}
    		ll cnt = 1;
    		for(auto x: s) {
    			cnt += comp[x];
    		}
    		cout<<cnt%10;
    	}
    	cout<<nl;
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
