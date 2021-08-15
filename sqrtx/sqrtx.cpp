class Solution {
public:
    int mySqrt(int x) {
        int low = 0;
        int high = x;
        int res;
        while(low <= high){
            int m = (low + high)/2;
            if((long)m*m == x) return m;
            else if((long)m*m < x){
                low = m+1;
                res = m;
            }else{
                high = m-1;
            }
        }
        return res;
    }
};