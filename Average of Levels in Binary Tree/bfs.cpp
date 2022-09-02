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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double>v;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty())
        {
            int l=q.size();//這一階層點的數量
            double aver=0;
            for(int i=0;i<l;++i)
            {
                TreeNode* n=q.front();
                q.pop();
                aver+=n->val;
                if(n->left)
                    q.push(n->left);
                if(n->right)
                    q.push(n->right);
            }
            v.push_back(aver/l);
        }
        return v;
    }
};