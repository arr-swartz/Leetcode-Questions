class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int ans = 0;
        int dp[n][m];
        for(int i = 0;i < n;i++){
            if(matrix[i][0] == '1'){
                dp[i][0] = 1;
                ans = 1;
            }else{
                dp[i][0] = 0;
            }
        }
        for(int j = 0;j < m;j++){
            if(matrix[0][j] == '1'){
                dp[0][j] = 1;
                ans = 1;
            }else{
                dp[0][j] = 0;
            }
        }
        for(int i = 1;i < n;i++){
            for(int j = 1;j < m;j++){
                if(matrix[i][j] == '1'){
                    dp[i][j] = 1 + min(dp[i-1][j], min(dp[i][j-1], dp[i-1][j-1]));
                    if(dp[i][j] > ans){
                        ans = dp[i][j];
                    }
                }else{
                    dp[i][j] = 0;
                }
            }
        }
        return ans*ans;
    }
};