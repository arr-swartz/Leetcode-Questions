class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        int dp[pairs.size()];
        sort(pairs.begin(), pairs.end());
        for(int i = 0;i < pairs.size();i++){
            dp[i] = 1;
        }
        for(int i = 1;i < pairs.size();i++){
            for(int j = 0;j < i;j++){
                if(pairs[j][1] < pairs[i][0]){
                    dp[i] = max(dp[i], 1 + dp[j]);
                }
            }
        }
        int mx = dp[0];
        for(int i = 1;i < pairs.size();i++){
            mx = max(mx, dp[i]);
        }
        return mx;
    }
};