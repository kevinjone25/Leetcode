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
    bool isValidBST(TreeNode* root) {
        return helper(root,LONG_MIN,LONG_MAX);
    }
    bool helper(TreeNode* root,long low,long high){
        //到空節點回傳true
        if(root == NULL)
            return true;
        /*
        low跟high紀錄該點的上限與下限
        超過就回傳false
        不超過就繼續往下探訪
        */
        if((root->val >= high) || (root->val <= low))
          return false;
        return (helper(root->left,low,root->val) && helper(root->right,root->val,high));
    }
};