class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int dp[101];
        memset(dp, 0, sizeof(dp));
        for(int i = 0;i < nums.size();i++){
            dp[nums[i]]++;
        }
        int sum = 0;
        for(int i = 0;i < 101;i++){
            sum += (dp[i]*(dp[i]-1)/2);
        }
        return sum;
    }
};