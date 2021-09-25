class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int ans = 0;
        int n = matrix.size();
        if(n == 0) return 0;
        int m = matrix[0].size();
        for(int i = 0;i < n;i++){
            for(int j = i;j < n;j++){
                int b = 0;
                for(int k = 0;k < m;k++){
                    if(matrix[i][k] == '1' && matrix[j][k] == '1'){
                        b++;
                        matrix[i][k] = '1';
                    }else{
                        b = 0;
                        matrix[i][k] = '0';
                    }
                    ans = max(ans, b*(j-i+1));
                }
            }
        }
        return ans;
    }
};