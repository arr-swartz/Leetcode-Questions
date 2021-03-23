class Solution {
public:
    bool divisorGame(int N) {
        bool dp[N+1];
        memset(dp, false, sizeof(dp));
        if(N == 1) return false;
        dp[2] = true;
        for(int i = 3;i <= N;i++){
            for(int j = 1;j < i;j++){
                if(i%j==0 && dp[i-j] == false){
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[N];
    }
};