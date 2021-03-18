class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int variance[prices.size()];
        variance[0] = 0;
        for(int i = 1;i < prices.size();i++){
            variance[i] = prices[i] - prices[i-1];
        }
        int s = 0;
        int mx = 0;
        for(int i = 0;i < prices.size();i++){
            s += variance[i];
            if(s > mx){
                mx = s;
            }
            if(s < 0) s = 0;
        }
        return mx;
    }
};