class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> v;
        vector<int> x{1};
        v.push_back(x);
        if(numRows == 1) return v;
        vector<int> x1{1,1};
        v.push_back(x1);
        for(int i = 2;i < numRows;i++){
            vector<int> res;
            res.push_back(1);
            for(int j = 1;j < v[i-1].size();j++){
                res.push_back(v[i-1][j] + v[i-1][j-1]);
            }
            res.push_back(1);
            v.push_back(res);
        }
        return v;
    }
};