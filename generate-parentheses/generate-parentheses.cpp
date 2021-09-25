class Solution {
public:
    
    void generate(vector<string> &v, int n, int first, int second, string s){
        if(first == n && second == n){
            v.push_back(s);
            return;
        }
        if(s.length() == 0 && first < n){
           generate(v, n, 1+first, second, s+"("); 
        }else {
            if(first <= n && second <= n && first > second){
                if(first < n){
                    generate(v, n ,1+first, second, s+"(");
                }
                generate(v, n, first, 1+second, s+")");
            }else if(first < n){
                generate(v, n ,1+first, second, s+"(");
            }
        }
    }
    
    vector<string> generateParenthesis(int n) {
        vector<string> v;
        generate(v, n, 0, 0, "");
        return v;
    }
};