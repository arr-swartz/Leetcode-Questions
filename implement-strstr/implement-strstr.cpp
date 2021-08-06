class Solution {
public:
    int strStr(string haystack, string needle) {
        if(haystack.length() == 0 && needle.length() == 0) return 0;
        if(needle.length() == 0) return 0;
        int lps[needle.size()];
        lps[0] = 0;
        int len = 0;
        int i = 1;
        while(i < needle.length()){
            if(needle[i] == needle[len]){
                len++;
                lps[i] = len;
                i++;
            }else{
                if(len != 0){
                    len = lps[len - 1];
                }else{
                    lps[i] = 0;
                    i++;
                }
            }
        }
        i = 0;
        int j = 0;
        int index = -1;
        while(i < haystack.length()){
            if(haystack[i] == needle[j]){
                i++;
                j++;
            }
            if(j == needle.length()){
                index = i - j;
                break;
            }else if(i < haystack.length() && haystack[i] != needle[j]){
                if(j != 0){
                    j = lps[j-1];
                }else{
                    i++;
                }
            }
        }
        return index;
    }
};