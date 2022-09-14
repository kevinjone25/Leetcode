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
    int ans = 0;
    int pseudoPalindromicPaths (TreeNode* root) {
        preorder(root, 0);
        return ans;
    }
    void preorder(TreeNode* node, int cnt) {
        if (node == NULL) 
            return;
        /*
        用bit和XOR運算去紀錄數字出現頻率是奇數還是偶數
        偶數次的結果是(x ^ x = 0)
        奇數次的結果是(x ^ x ^ x = (x ^ x) ^ x = 0 ^ x = x)
        */
        cnt ^= (1 << node->val);
        if(!node->left && !node->right)//到達路徑終點時判斷
            ans += (cnt & (cnt - 1)) == 0;
        /*
        (cnt & (cnt - 1))會把最右邊的1移除
        而迴文只有一個數奇數個而其他數偶數個或全部偶數個兩種情況
        也就是符合迴文條件的cnt，至多只會有一位的bit是1
        配合(cnt & (cnt - 1))運算後，結果為0時就代表是迴文，反之則否
        */
        preorder(node->left, cnt);
        preorder(node->right, cnt);
    }
};