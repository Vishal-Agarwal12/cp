

class Solution {
public:
int dp[46]={0};

    int r(int level, int n) {
        if(level>n) return 0;
        if(level==n) return 1;

        int ans=0;
        if(dp[level]!=0) return dp[level];

        for(int step = 1;step<=2;step++) {
            if(level + step<=n) {
                int ways  = r(level + step, n);
                ans+=ways;
            }
            else break;
        }

        dp[level] = ans;
        return ans;
    }    
    int climbStairs(int n) {
        return r(0,n);
    }
};
