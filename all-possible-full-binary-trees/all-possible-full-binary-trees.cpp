/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    unordered_map<int, vector<TreeNode*> > m;
    vector<TreeNode*> allPossibleFBT(int n) {
        if(m.find(n) != m.end()){
            return m[n];
        }else if(n == 1){
            vector<TreeNode*> v;
            v.push_back(new TreeNode(0));
            m[1] = v;
        }else if(n%2 == 1){
            vector<TreeNode*> v;
            for(int i = 0;i < n;i++){
                int j = n - 1 - i;
                for(TreeNode* left : allPossibleFBT(i)){
                    for(TreeNode* right : allPossibleFBT(j)){
                        TreeNode* t = new TreeNode(0);
                        t->left = left;
                        t->right = right;
                        v.push_back(t);
                    }
                }
            }
            m[n] = v;
        }
        return m[n];
    }
};