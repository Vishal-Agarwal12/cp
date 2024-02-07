// Author: Vishal 
// Created: 2024-02-07 12:53:17

#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
#include "debug.h"
#endif

using ll = long long;
#define pb push_back
#define eb emplace_back
#define fi first
#define nl '\n'
#define se second
#define ins insert

long long binpow(long long a, long long b, long long m) {
    a %= m;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}
long long modInv(long long a, long long m) {
    return binpow(a, m - 2, m);
}

void solve()
{
    string s;
    cin>>s;
 	
 	ll n = s.size();	   
    set<pair<ll, ll>> st;
    	
    vector<ll> h1(n+1, 0), h2(n+1, 0), pow1(n), pow2(n);
    pow1[0] = 1, pow2[0] = 1;
    ll p1 = 31, p2 = 29, m = 1e9+9;
    vector<ll> pow1_inv(n), pow2_inv(n);
    
    for(int i=1;i<n;i++) {
    	pow1[i] = (pow1[i-1]*p1)%m;
    	pow2[i] = (pow2[i-1]*p2)%m;
    }
    for(int i=0;i<n;i++) {
    	pow1_inv[i] = modInv(pow1[i], m);
    	pow2_inv[i] = modInv(pow2[i], m);
    }
    
    for(int i=0;i<n;i++) {
    	h1[i+1] = (h1[i] + pow1[i]*(s[i] - 'a' + 1))%m;
    	h2[i+1] = (h2[i] + pow2[i]*(s[i] - 'a' + 1))%m;
    }	
    
    vector<ll> v;
    for(int i=1;i<=n;i++) {
    	ll hs1 = h1[i];
    	ll hs2 = h2[i];
    	
    	ll hs3 = (h1[n] - h1[n-i] + m)%m;
    	hs3 = (hs3* pow1_inv[n-i])%m;
    	
    	ll hs4 = (h2[n] - h2[n-i] + m)%m;
    	hs4 = (hs4* pow2_inv[n-i])%m;
    	
    	if(hs1 == hs3 && hs2 == hs4) {
    		v.pb(i);
    	}
    }
    // cout<<v;
    auto check = [&](ll mid) -> bool {
    	st.clear();
    	st.insert({h1[mid], h2[mid]});
    	
    	ll hs1 = (h1[n] - h1[n-mid] + m)%m;
    	hs1 = (hs1* pow1_inv[n-mid])%m;
    	ll hs2 = (h2[n] - h2[n-mid] + m)%m;
    	hs2 = (hs2* pow2_inv[n-mid])%m;
    	
    	if(!st.count({hs1, hs2})) {
    		return false;
    	}
    	
    	for(int i=mid+1;i<n;i++) {
    		hs1 = (h1[i] - h1[i-mid] + m)%m;
	    	hs1 = (hs1* pow1_inv[i-mid])%m;
	    	hs2 = (h2[i] - h2[i-mid] + m)%m;
	    	hs2 = (hs2* pow2_inv[i-mid])%m;
	    	
	    	if(st.count({hs1, hs2})) return true;
    	}
    	
    	return false;
    };
    	
	if(v.size() == 0) {
		cout<<"Just a legend"<<nl;
		return;
	}
    ll l = 0, r = v.size()-1;
    ll ans = 0;
    while(l <= r) {
    	ll mid = (l+r)/2;
    	if(check(v[mid])) {
    		ans = v[mid];
    		l = mid+1;
    	}
    	else r = mid-1;
    }
    
    if(ans == 0) {
    	cout<<"Just a legend"<<nl;
    }
    else {
    	for(int i=0;i<ans;i++) {
    		cout<<s[i];
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
