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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>ans;
        if(!root)
            return ans;
        //Morris Traversal
        TreeNode* cur = root, *mostRight;
        while(cur)
        {
            if(!cur->left)//如果cur沒有左子節點，
            {
                ans.push_back(cur->val);
                cur = cur->right;//cur向右移動
            }
            else//如果cur有左子節點
            {
                //找到左子樹上最右的節點mostRight
                mostRight = cur->left;
                while(mostRight->right != NULL && mostRight->right != cur)
                    mostRight = mostRight->right;
                
                if(mostRight->right == NULL)//如果mostRight右子節點為空
                {//將其右子節點設為cur(連接起來，之後從這路徑回溯)
                    mostRight->right = cur;
                    cur = cur->left;
                }
                else//如果mostRight右子節點不為空，代表回溯過了，斷開連結
                {
                    mostRight->right = NULL;
                    ans.push_back(cur->val);
                    cur = cur->right;
                }
            }
        }
        return ans;
    }
};