class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        //遞迴不斷尋找新節點應連接的位置
        if(!root)//到達終點(空位)，返回一個新節點給上一層(連接起來)
            return new TreeNode(val);
        if(val>root->val)//右區間
            root->right=insertIntoBST(root->right,val);
        else   //左區間
            root->left=insertIntoBST(root->left,val);
        //題目保證不會有相同值，因此不用判斷相等的情形
        return root;//返回原本的節點給上一層
    }
};