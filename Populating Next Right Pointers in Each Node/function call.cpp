class Solution {
public:
    Node* connect(Node* root) {
        //不斷呼叫函式將現在節點的子節點連接起來
        if(!root)//無節點，傳回NULL
            return NULL;
        if(root->left)//如果左子節點存在，將他與右子節點連接
            root->left->next=root->right;
        if(root->right && root->next)//若右子節點及右邊節點存在，將右子節點與右邊節點的左子節點連接
            root->right->next=root->next->left;
        connect(root->left);
        connect(root->right);
        return root;
    }
};