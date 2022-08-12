/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
    {
        if (!root)//到底就回傳空
            return root;
        
		//找到p或q就回傳
        if (root == p || root == q)
            return root;
        
		//存找到的點
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        
		//左右點都找到就回傳父節點
        if (left && right)
            return root;
        //其中一點在下位的情況
        return left? left: right;
    }
};