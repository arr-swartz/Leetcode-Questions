class Solution {
public:
    
    double solve(double x, long long int n){
        if(n==1){
            return x;
        }else if(n==0){
            return 1;
        }else if(n%2 == 0){
            return solve(x*x, n/2);
        }else{
            return x*solve(x*x, (n-1)/2);
        }
    }
    
    
    double myPow(double x, long long int n) {
        double l = solve(x, abs(n));
        if(n < 0) return 1/l;
        else return l;
    }
};