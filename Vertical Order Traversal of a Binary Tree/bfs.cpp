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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,map<int,multiset<int>>>mp;
        //multiset會保留重複的元素
        vector<vector<int>> ans;
        queue<pair<TreeNode*,pair<int,int>>>q;
        q.push({root,{0,0}});
        //用BFS遍歷，並依position紀錄至map
        while(!q.empty())
        {
            root=q.front().first;
            int c=q.front().second.first,r=q.front().second.second;
            q.pop();
            mp[c][r].insert(root->val);
            if(root->left) 
                q.push({root->left,{c-1,r+1}});
            if(root->right)
                q.push({root->right,{c+1,r+1}});
        }
        //遍歷map把答案轉為vector
        for(auto x:mp)
        {
            vector<int> col;
            for(auto y:x.second)
            {
                for(auto ele:y.second)
                    col.push_back(ele);
            }
            ans.push_back(col);
        }
        return ans;
    }
};