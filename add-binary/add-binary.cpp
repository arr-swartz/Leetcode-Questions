class Solution {
public:
    string addBinary(string a, string b) {
        string g = "";
        int i = a.length()-1;
        int j = b.length()-1;
        int carry = 0;
        while(i >= 0 && j >= 0){
            if(a[i] == '0' && b[j] == '0'){
                if(carry == 0){
                    g += '0';
                }else{
                    g += '1';
                    carry = 0;
                }
            }else if(a[i] == '1' && b[j] == '1'){
                if(carry == 0){
                    g += '0';
                    carry = 1;
                }else{
                    g += '1';
                }
            }else{
                if(carry == 0){
                    g += '1';
                }else{
                    g += '0';
                }
            }
            i--;
            j--;
        }
        while(i >= 0){
            if(a[i] == '1'){
                if(carry == 0){
                    g += '1';
                }else{
                    g += '0';
                }
            }else{
                if(carry == 0){
                    g += '0';
                }else{
                    g += '1';
                    carry = 0;
                }
            }
            i--;
        }
        while(j >= 0){
            if(b[j] == '1'){
                if(carry == 0){
                    g += '1';
                }else{
                    g += '0';
                }
            }else{
                if(carry == 0){
                    g += '0';
                }else{
                    g += '1';
                    carry = 0;
                }
            }
            j--;
        }
        if(carry == 1){
            g += '1';
        }
        reverse(g.begin(),g.end());
        return g;
    }
};