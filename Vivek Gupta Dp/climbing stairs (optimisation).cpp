

class Solution {
public:
int a[46]={0};

    int r(int level, int n) {
        if(level>n) return 0;
        if(level==n) return 1;

        int ans=0;

        for(int step = 1;step<=2;step++) {
            if(level + step<=n && a[level + step]!=0) {
                int ways  = a[level+step];
                ans+=ways;
            }
            else if(level + step<=n) {
                a[level + step]  = r(level + step,n);
                ans+=a[level + step];
            }
            else break;
        }
        return ans;
    }    
    int climbStairs(int n) {
        return r(0,n);
    }
};
