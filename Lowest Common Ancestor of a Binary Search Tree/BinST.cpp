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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        /*
        利用二元搜尋樹的特性去找
        左子節點比父節點小，右子節點比父節點大
        */
        int current = root->val;
        if(p->val < current && q->val < current)//p和q都小於現在點，往左走
            return lowestCommonAncestor(root->left,p,q);
        else if(p->val > current && q->val > current)//p和q都大於現在點，往右走
            return lowestCommonAncestor(root->right,p,q);
        else//p和q被區隔開來，代表找到LCA了
            return root;
    }
};