class Solution {
public:
    int jump(vector<int>& nums) {
        int dp[nums.size()+1];
        dp[0] = 0;
        dp[1] = 0;
        for(int i = 2;i <= nums.size();i++){
            dp[i] = INT_MAX;
        }
        for(int i = 2;i <= nums.size();i++){
            for(int j = 1;j < i;j++){
                if(nums[j-1] >= (i-j)){
                    dp[i] = min(dp[i], dp[j]+1);
                }
            }
        }
        return dp[nums.size()];
    }
};