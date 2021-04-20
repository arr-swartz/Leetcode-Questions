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
    
    void inORDER(TreeNode* root, vector<int> &p){
        if(!root) return;
        inORDER(root->left, p);
        p.push_back(root->val);
        inORDER(root->right, p);
    }
    
    TreeNode* makeBalanced(vector<int> p, int s, int e){
        if(s == e){
            return new TreeNode(p[s]);
        }else if(s > e){
            return nullptr;
        }else{
            int mid = s + (e-s)/2;
            TreeNode* root = new TreeNode(p[mid]);
            root->left = makeBalanced(p, s, mid-1);
            root->right = makeBalanced(p, mid+1, e);
            return root;
        }
    }
    
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> p;
        inORDER(root, p);
        TreeNode* newRoot = makeBalanced(p, 0, p.size()-1);
        return newRoot;
    }
};