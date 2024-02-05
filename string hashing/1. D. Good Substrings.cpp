// Author: Vishal 
// Created: 2024-02-05 21:04:03

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
    string s,t;
    cin>>s>>t;
    ll k;
    cin>>k;
    ll n = s.size();
    set<pair<ll, ll>> st;
    for(int i=0;i<n;i++) {
		ll bad = 0;
		ll h1 = 0, h2 = 0, pow1 = 1, pow2 = 1, p1 = 31, p2 = 41, mod = 1e9+9;
		
    	for(int j=i;j<n;j++) {
    		bad += (t[s[j]-'a'] == '0' ? 1 : 0);
    		if(bad > k) break;
    		h1 = (h1 + (s[j]-'a'+1)*pow1)%mod;
    		pow1 = (pow1*p1)%mod;
    		h2 = (h2 + (s[j]-'a'+1)*pow2)%mod;
    		pow2 = (pow2*p2)%mod;
    		st.insert({h1, h2});
    	}
    }
    
    cout<<st.size()<<nl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    //freopen("input.txt", "rt", stdin);
    //freopen("output.txt", "wt", stdout);

    solve();

    return 0;
}
