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
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>>ans;
        vector<int>path;
        dfs(ans,path,root,targetSum);
        return ans;
    }
    void dfs(vector<vector<int>>&ans,vector<int>&path,TreeNode* node,int sum){
        if(!node)
            return;
        path.push_back(node->val);
        sum-=node->val;
        //到達路徑尾端確認總和
        if(!node->left && !node->right && sum==0)
            ans.push_back(path);
        else
        {
            dfs(ans,path,node->left,sum);
            dfs(ans,path,node->right,sum);
        } 
        path.pop_back();
    }
};