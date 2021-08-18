class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> x{1};
        if(rowIndex == 0) return x;
        x.push_back(1);
        for(int i = 2;i <= rowIndex;i++){
            vector<int> res;
            res.push_back(1);
            for(int j = 1;j < x.size();j++){
                res.push_back(x[j] + x[j-1]);
            }
            res.push_back(1);
            x = res;
        }
        return x;
    }
};