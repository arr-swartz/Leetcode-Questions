class Solution {
public:
    int getMaximumGenerated(int n) {
        int dp[n+1];
        dp[0] = 0;
        if(n == 0) return 0;
        dp[1] = 1;
        int mx = 1;
        for(int i = 1;i <= n;i++){
            if(2*i <= n){ dp[2*i] = dp[i];
                         mx = max(mx, dp[2*i]);}
            if(2*i+1 <= n) { dp[2*i+1] = dp[i] + dp[i+1];
                            mx = max(mx, dp[2*i+1]);
                           }
        }
        return mx;
    }
};