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
    vector<int> rightSideView(TreeNode* root) {
        vector<int>order;
        if(!root)
            return order;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty())
        {
            int degn=q.size();//代表這一層有幾個點
            order.push_back(q.front()->val);//將點紀錄到vector
            //由於同一個度上右邊的點最先被推入
            //所以我們紀錄的點一定是最靠右的
            while(degn)
            {
                TreeNode* node=q.front();
                q.pop();
                //從右邊的點開始優先推入queue
                if(node->right) 
                    q.push(node->right);
                if(node->left) 
                    q.push(node->left);
                --degn;
            }
        }
        return order;
    }
};