class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<pair<int, int> > s;
        int n = nums.size();
        vector<int> res(n);
        for(int i = 2*n-1;i >= 0;i--){
            int j = i%n;
            if(s.empty()){
                if(i < n){
                    res[i] = -1;
                }
                s.push(make_pair(nums[j], i));
            }else{
                while(!s.empty() && nums[j] >= s.top().first){
                    s.pop();
                }
                if(i < n){
                    if(s.empty()){
                        res[i] = -1;
                    }else if((s.top().second)%n != i){
                        res[i] = s.top().first;
                    }else{
                        res[i] = -1;
                    }
                }
                s.push(make_pair(nums[j], i));
            }
        }
        return res;
    }
};