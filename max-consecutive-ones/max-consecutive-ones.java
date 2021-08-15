class Solution {
    public int findMaxConsecutiveOnes(int[] nums) {
        int cnt = 0;
        int mx = 0;
        for(int i = 0;i < nums.length;i++){
            if(nums[i] == 0){
                mx = Math.max(mx, cnt);
                cnt = 0;
            }else{
                cnt++;
            }
        }
        mx = Math.max(mx, cnt);
        return mx;
    }
}