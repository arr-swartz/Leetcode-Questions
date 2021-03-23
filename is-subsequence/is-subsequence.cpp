class Solution {
public:
    bool isSubsequence(string s, string t) {
       int m = s.length();
        int l = t.length();
        bool dp[l+1][m+1];
        memset(dp, false, sizeof(dp));
        dp[0][0] = true;
        for(int i = 1;i <= l;i++){
            for(int j = 0;j <= m;j++){
                if(j == 0){
                    dp[i][j] = true;
                }
                else if(dp[i-1][j] || (dp[i-1][j-1] && t[i-1] == s[j-1])){
                    dp[i][j] = true;
                }
            }
        }
        return dp[l][m];
    }
};