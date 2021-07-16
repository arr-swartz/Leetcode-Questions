class Solution {
public:
    
    void allPermutation(string s1, unordered_set<string> &s, int index){
        if(index == s1.length()){
            return;
        }
        for(int j = index;j < s1.length();j++){
            swap(s1[j] , s1[index]);
            s.insert(s1);
           // cout << s1 << endl;
            allPermutation(s1, s, index + 1);
            swap(s1[j], s1[index]);
        }
    } 
    
    int numTilePossibilities(string tiles) {
        unordered_set<string> s;
        for(int i = 1;i < (1 << tiles.length()); i++){
            string s1 = "";
            for(int j = 0;j < tiles.length();j++){
                if(i & (1<<j)){
                    s1 += tiles[j];
                }
            }
            s.insert(s1);
            //cout << s1 << endl;
            allPermutation(s1, s, 0);
        }
        return s.size();
    }
};