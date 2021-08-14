class Solution {
    public List<Integer> majorityElement(int[] nums) {
        int num1 = -1, num2 = -1;
        int cnt1 = 0, cnt2 = 0;
        for(int i = 0;i < nums.length;i++){
            if(nums[i] == num1){
                cnt1++;
            }else if(nums[i] == num2){
                cnt2++;
            }else if(cnt1 == 0){
                num1 = nums[i];
                cnt1++;
            }else if(cnt2 == 0){
                num2 = nums[i];
                cnt2++;
            }else{
                cnt1--;
                cnt2--;
            }
        }
        cnt1 = 0;
        cnt2 = 0;
        for(int i = 0;i < nums.length;i++){
            if(nums[i] == num1){
                cnt1++;
            }else if(nums[i] == num2){
                cnt2++;
            }
        }
        List<Integer> l = new ArrayList<Integer>();
        if(cnt1 > (nums.length)/3){
            l.add(num1);
        }
        if(cnt2 > (nums.length)/3){
            l.add(num2);
        }
        return l;
    }
}