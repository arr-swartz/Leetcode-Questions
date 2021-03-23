class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0;
        int max_sum = 0;
        int mx = INT_MIN;
        for(int i = 0;i < nums.size();i++){
            sum += nums[i];
            mx = max(mx, nums[i]);
            max_sum = max(sum, max_sum);
            if(sum < 0) sum = 0;
        }
        if(max_sum == 0) return mx;
        return max_sum;
    }
};