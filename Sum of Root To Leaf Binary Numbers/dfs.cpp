class Solution {
public:
    int dfs(TreeNode* node,int v)
    {
        if(node->left&&node->right)
            return dfs(node->left,v*2+node->val)+dfs(node->right,v*2+node->val);
        else if(node->left)
            return dfs(node->left,v*2+node->val);
        else if(node->right)
            return dfs(node->right,v*2+node->val);
        else
            return v*2+node->val;
    }
    int sumRootToLeaf(TreeNode* root) {
        return dfs(root,0);
    }
};