class Solution {
public:
    string defangIPaddr(string address) {
        string g = "";
        for(int i = 0;i < address.length();i++){
            if(address[i] == '.'){
                g+="[.]";
            }else{
                g+=address[i];
            }
        }
        return g;
    }
};