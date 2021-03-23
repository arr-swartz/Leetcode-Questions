class Solution {
    public int countSquares(int[][] matrix) {
        int l = matrix.length;
        int m = matrix[0].length;
        int dp[][] = new int[l+1][m+1];
        int ans = 0;
        for(int[] row:dp) Arrays.fill(row, 0);
        for(int i = 1;i <= l;i++){
            for(int j = 1;j <= m;j++){
                if(matrix[i-1][j-1] == 0) continue;
                else{
                    dp[i][j] = Math.min(dp[i-1][j] + 1, Math.min(dp[i][j-1]+1, dp[i-1][j-1]+1));
                    ans += dp[i][j];
                }
            }
        }
        return ans;
    }
}