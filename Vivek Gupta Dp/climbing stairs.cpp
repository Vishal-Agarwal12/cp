
class Solution {
public:
int a[45]={0};

    int r(int level, int n) {
        if(level>n) return 0;
        if(level==n) return 1;

        int ans=0;

        for(int step = 1; step <= n; step++) {    // in this we have a choice from step = 1 to step = n
            if(level + step<=n) {
                int ways  = r(level + step, n);
                ans += ways;
            }
        }
        return ans;
    }    
    int climbStairs(int n) {
        return r(0,n);
    }
};
