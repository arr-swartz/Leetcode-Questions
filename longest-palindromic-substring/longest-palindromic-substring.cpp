class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        if(n == 0) return s;
        int dp[n][n];
        int max = 1;
        int index = 0;
        for(int i = 0;i < n;i++){
            for(int j = 0;i+j < n;j++){
                if(j == i+j){
                    dp[j][i+j] = 1;
                }else if(i == 1){
                    if(s[j] == s[j+1]){
                        dp[j][i+j] = 1;
                    }else{
                        dp[j][i+j] = 0;
                    }
                }else{
                    if(s[j] == s[i+j] && dp[j+1][i+j-1] == 1){
                        dp[j][i+j] = 1;
                    }else{
                        dp[j][i+j] = 0;
                    }
                }
                if(i+1 > max && dp[j][i+j] == 1) {max = i+1;
                                      index = j;
                                     }
            }
        }
        return s.substr(index,max);
    }
};