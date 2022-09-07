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
    string tree2str(TreeNode* root) {
		string parent = to_string(root->val);
        //往下遞迴增加字串
		if(root->left)//左子樹
			parent += "(" + tree2str(root->left) + ")";
		if(root->right)//右子樹
        { 
			if(!root->left)//左子樹不存在要再補個括號
                parent += "()";
			parent += "(" + tree2str(root->right) + ")"; 
		}
		return parent;
	}
};