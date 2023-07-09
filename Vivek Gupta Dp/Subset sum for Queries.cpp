

#include <bits/stdc++.h>
#define ll long long
using namespace std;

int n;
int a[101];
int dp[105][100005];

bool rec(int level, int left) {
    //pruning
    if(left < 0) return 0;
    
    // base case
    if(level == n) {
        if(left == 0) 
            return 1;
        else return 0;    
    }
    
    // cache check
    if(dp[level][left]!=-1) 
        return dp[level][left];
    
    // compute
    int ans=0;
    if(rec(level+1, left + a[level]) == 1) 
        ans = 1;
    else if(rec(level+1, left) == 1)        
        ans = 1;
        
    // save and return
    dp[level][left] = ans;
    return ans;
}

void solve() {
    cin>>n;
    
    for(int i=0;i<n;i++) cin>>a[i];
    memset(dp,-1,sizeof(dp));
    
    int q,t;
    cin>>q;
    while(q--) {
        cin>>t;
        cout<<rec(0,t);
    }
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();

    return 0;
}

