class Solution {
    
    public int solve(int[] nums, int i, int mid, int j){
        int s = i;
        int t = mid;
        int cnt = 0;
        int curr = mid;
        for(int k=i;k < mid;k++){
            while(curr <= j && nums[k] > (long)nums[curr]*2){
                curr+=1;
            }
            cnt += (curr - mid);
        }
        List<Integer> res = new ArrayList<Integer>();
        while(s < mid && t <= j){
            if(nums[s] < nums[t]){
                res.add(nums[s]);
                s+=1;
            }else{
                res.add(nums[t]);
                t+=1;
            }
        }
        while(s < mid){
            res.add(nums[s]);
            s+=1;
        }
        while(t <= j){
            res.add(nums[t]);
            t+=1;
        }
        for(int g = i;g <= j;g++){
            nums[g] = res.get(g-i);
        }
        return cnt;
    }
    
    public int merge(int[] nums, int i, int j){
        int sum = 0;
        if(i < j){
            int mid = i + ((j-i)/2);
            sum += merge(nums, i, mid);
            sum += merge(nums, mid+1, j);
            sum += solve(nums, i, mid+1, j);
        }
        return sum;
    }
    
    
    public int reversePairs(int[] nums) {
        return merge(nums, 0, nums.length-1);
    }
}