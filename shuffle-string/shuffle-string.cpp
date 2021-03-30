class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        string g = s;
        for(int i = 0;i < s.length();i++){
            g[indices[i]] = s[i];
        }
        return g;
    }
};