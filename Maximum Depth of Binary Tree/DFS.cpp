class Solution {
public:
    int maxDepth(TreeNode* root) {
        //DFS
        if(!root)
            return 0;
        int left=maxDepth(root->left),right=maxDepth(root->right);
        if(right>left)
            return right+1;//+1是加上現在的點
        else
            return left+1;
    }
};