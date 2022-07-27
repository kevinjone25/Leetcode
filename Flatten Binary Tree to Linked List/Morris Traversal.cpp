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
	void flatten(TreeNode* root) {
		TreeNode* cur = root;
		TreeNode* pre = NULL;
		while(cur)
        {
			if(cur->left)
            {
				pre = cur->left;
				while(pre->right)//找出左子樹的最後一個節點(節點越靠右越後面)
                    pre = pre->right;
                //將左子樹最後一個節點連接上右子樹
				pre->right = cur->right;
                //將左子樹移為右子樹(原本的右子樹已接到左子樹上)
				cur->right = cur->left;
                //左節點清空
				cur->left = NULL;
			}
			cur = cur->right;
		}
	}
};