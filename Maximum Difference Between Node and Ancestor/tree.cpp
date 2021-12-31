class Solution {
public:
    int findmaxd(TreeNode* node,int maxv,int minv)
    {
        if(!node)//一條路徑到底後回傳maxd
            return maxv-minv;
        if(node->val>maxv)//更新最大值
            maxv=node->val;
        if(node->val<minv)//更新最小值
            minv=node->val;
        return max(findmaxd(node->left,maxv,minv),findmaxd(node->right,maxv,minv));//比較左路徑和右路徑的maxd並回傳
    }
    int maxAncestorDiff(TreeNode* root) {
        return findmaxd(root,INT_MIN,INT_MAX);
    }
};