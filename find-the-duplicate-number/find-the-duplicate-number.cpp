class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int dp[100001];
        memset(dp, 0, sizeof(dp));
        for(int i = 0;i < nums.size();i++){
            dp[nums[i]]++;
        }
        for(int i = 0;i < 100001;i++){
            if(dp[i] >= 2){
                return i;
            }
        }
        return -1;
    }
};