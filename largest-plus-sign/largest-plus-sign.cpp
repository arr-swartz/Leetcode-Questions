class Solution {
public:
    int orderOfLargestPlusSign(int n, vector<vector<int>>& mines) {
        int dp[n][n];
        for(int i = 0;i < n;i++){
         for(int j = 0;j < n;j++){
             dp[i][j] = 1;
         }   
        }
        int mx = 0;
        for(int i = 0;i < mines.size();i++){
            dp[mines[i][0]][mines[i][1]] = 0;
        }
        int mp[n][n];
        for(int i = 0;i < n;i++){
            int count = 0;
            for(int j = 0;j < n;j++){
                if(dp[i][j]==0){
                    count = 0;
                    mp[i][j] = 0;
                }else{
                    mp[i][j] = ++count;
                }
            }
            count = 0;
            for(int j = n-1;j>=0;j--){
                if(dp[i][j] == 0){
                    count = 0;
                    mp[i][j] = 0;
                }else{
                    mp[i][j] = min(++count, mp[i][j]);
                }
            }
        }
        for(int i = 0;i < n;i++){
            int count = 0;
            for(int j = 0;j < n;j++){
                if(dp[j][i]==0){
                    count = 0;
                    mp[j][i] = 0;
                }else{
                    mp[j][i] = min(++count, mp[j][i]);
                }
            }
            count = 0;
            for(int j = n-1;j>=0;j--){
                if(dp[j][i] == 0){
                    count = 0;
                    mp[j][i] = 0;
                }else{
                    mp[j][i] = min(++count, mp[j][i]);
                    mx = max(mp[j][i], mx);
                }
            }
        }
        return mx;
    }
};