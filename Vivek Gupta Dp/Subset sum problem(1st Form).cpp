

#include <bits/stdc++.h>
#define ll long long
using namespace std;

int n,target;
int a[101];
int dp[105][100005];

bool rec(int level, int taken_sum) {
    //pruning
    if(taken_sum>target) return 0;
    
    // base case
    if(level == n) {
        if(taken_sum == target) 
            return 1;
        else return 0;    
    }
    
    // cache check
    if(dp[level][taken_sum]!=-1) 
        return dp[level][taken_sum];
    
    // compute
    int ans=0;
    if(rec(level+1, taken_sum + a[level]) == 1) 
        ans = 1;
    else if(rec(level+1, taken_sum) == 1)        
        ans = 1;
        
    // save and return
    dp[level][taken_sum] = ans;
    return ans;
}

void solve() {
    cin>>n>>target;
    
    for(int i=0;i<n;i++) cin>>a[i];
    memset(dp,-1,sizeof(dp));
    
    cout<<rec(0,0)<<endl; // initially level is 0 and also initial taken_sum = 0
    // cout<<dp[1][5]<<endl; 
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();

    return 0;
}

