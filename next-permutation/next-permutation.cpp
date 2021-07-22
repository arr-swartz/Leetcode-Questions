class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        bool flag = true;
        for(int i = n-2;i >= 0;i--){
            if(nums[i] < nums[i+1]){
                flag = false;
                for(int j = n-1;j > i;j--){
                    if(nums[j] > nums[i]){
                        swap(nums[i], nums[j]);
                        break;
                    }
                }
                int k = n-1;
                for(int j = i+1;j < k;j++){
                    swap(nums[j], nums[k]);
                    k--;
                }
                break;
            }
        }
        if(flag){
            reverse(nums.begin(), nums.end());
        }
    }
};