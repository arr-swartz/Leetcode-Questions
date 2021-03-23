class Solution {
public:
    
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int ms = mat.size();
        int mi = mat[0].size();
        for(int i = 0;i < ms;i++){
            for(int j = 1;j < mi;j++){
                mat[i][j] +=mat[i][j-1];
            }
        }
        vector<vector<int>> v;
        for(int i = 0;i < ms;i++){
            vector<int> res;
            for(int j = 0;j < mi;j++){
                int sum = 0;
                for(int p = 0;p <= k;p++){
                    if(i - p < 0){
                        break;
                    }else{
                        sum += mat[i - p][min(mi-1,j+k)];
                        if(j - k -1 >= 0){
                           sum -= mat[i - p][j-k-1]  ; 
                        }
                    }
                }
                for(int p = 1;p <= k;p++){
                    if(i + p > ms-1){
                        break;
                    }else{
                        sum += mat[i + p][min(mi-1,j+k)];
                         if(j - k -1 >= 0){
                           sum -= mat[i + p][j-k-1]  ; 
                        }
                    }
                }
                res.push_back(sum);
            }
            v.push_back(res);
            res.clear();
        }
        return v;
    }
};