class Solution {
public:
    
    bool stoneGame(vector<int>& piles) {
       int table[piles.size()][piles.size()];
        int x, y, z;
        int n = piles.size();
        for(int i = 0;i < n;i++){
            for(int j = 0,k = i; k < n;k++,j++){
                if(j+2 <= k){
                    x = table[j+2][k];
                }else{
                    x = 0;
                }
                if(j + 1 <= k -1){
                    y = table[j+1][k-1];
                }else{
                    y = 0;
                }
                if(j <= k-2){
                    z = table[j][k-2];
                }else{
                    z = 0;
                }
                table[j][k] = max(piles[j] + min(x,y), piles[k] + min(y, z));
            }
        }
        int sum = 0;
        for(auto p : piles){
            sum += p;
        }
        if(sum - table[0][n-1] > table[0][n-1]){
            return false;
        }else{
            return true;
        }
    }
};