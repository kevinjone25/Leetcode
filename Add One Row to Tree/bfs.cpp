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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth==1)
        {
            TreeNode* dummy=new TreeNode(val);
            dummy->left=root;
            return dummy;
        }
        int d=1;
        queue<TreeNode*>q;
        q.push(root);
        //用bfs，深度到了就插入點
        while(++d<=depth)
        {
            int s=q.size();
            while(s--)
            {
                TreeNode* n=q.front();
                q.pop();
                if(d==depth)
                {
                    TreeNode *l=new TreeNode(val);
                    TreeNode *r=new TreeNode(val);
                    l->left=n->left;
                    r->right=n->right;
                    n->left=l;
                    n->right=r;
                }
                else
                {
                    if(n->left)
                        q.push(n->left);
                    if(n->right)
                        q.push(n->right);
                }
            }
        }
        return root;
    }
};