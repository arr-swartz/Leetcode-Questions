class Solution {
public:
    int lengthOfLastWord(string s) {
        int len = 0;
        int prev = len;
        for(int i = 0;i < s.length();i++){
            if(s[i] != ' '){
                len++;
                prev = len;
            }else{
                len = 0;
            }
        }
        return prev;
    }
};