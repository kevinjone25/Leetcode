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
    int goodNodes(TreeNode* root) {
        return findgood(root,root->val);
    }
    int findgood(TreeNode* n,int max)
    {
        if(!n)
            return 0;
        if(n->val >= max)
            return 1+findgood(n->left,n->val)+findgood(n->right,n->val);
        return findgood(n->left,max)+findgood(n->right,max);
    }
};