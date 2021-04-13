class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 1;
        int minn = nums[0];
        for(int i = 1;i < nums.size();i++){
            if(nums[i] != minn){
                count--;
            }else{
                count++;
            }
            if(count == 0){
                minn = nums[i];
                count = 1;
            }
        }
        return minn;
    }
};