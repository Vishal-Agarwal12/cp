// Author: Vishal 
// Created: 2024-02-06 08:06:56

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
    string s = "abcab";
	
    ll n = s.size();
	// cout<<s;
    vector<ll> h(n+1), pow(n);
    ll p = 31, m = 1e9+9;
    	
   	pow[0] = 1; 	
    for(int i=1;i<n;i++) {
    	pow[i] = (pow[i-1]*p)%m;
    }	
    h[n] = (s[n-1]-'a'+1);
    for(int i=n-1;i>0;i--) {
    	h[i] = (h[i+1]*p + (s[i-1] - 'a' + 1)) % mod;
    }
    // cout<<h;
    
    ll h1 = (h[1] - (h[3] * pow[2]) + m)%m; // (h[l] - h[r+1] * pow[r-l+1])
    ll h2 = (h[4])%m;
    cout<<h1<<" "<<h2<<nl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    //freopen("input.txt", "rt", stdin);
    //freopen("output.txt", "wt", stdout);

    solve();

    return 0;
}
