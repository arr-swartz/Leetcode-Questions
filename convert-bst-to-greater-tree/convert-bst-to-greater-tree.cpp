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
    int sum = 0;
    void revInOrder(TreeNode* root){
        if(!root) return;
        revInOrder(root->right);
        int temp = root->val;
        root->val = root->val + sum;
        sum += temp;
        revInOrder(root->left);
    }
    
    TreeNode* convertBST(TreeNode* root) {
        revInOrder(root);
        return root;
    }
};