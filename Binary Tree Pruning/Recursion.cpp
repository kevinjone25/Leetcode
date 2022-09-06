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
    TreeNode* pruneTree(TreeNode* root) {
        if(root!=NULL)
        {
            //往下遞迴確認每一個點，如果子樹包含1就回傳原本的root
            //不滿足就回傳NULL替換掉
            root->left = pruneTree(root->left);
            root->right = pruneTree(root->right);
            //節點是0且沒有子節點
            if(!root->left && !root->right && root->val==0)
                return NULL;
        }
        return root;
    }
};