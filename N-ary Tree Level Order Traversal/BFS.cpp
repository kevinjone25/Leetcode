/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>>ans;
        if(!root)
            return ans;
        //BFS去遍歷
        queue<Node*>q;
        q.push(root);
        while(!q.empty())
        {
            vector<int>lev;
            int l=q.size();
            while(l--)
            {
                Node* n=q.front();
                q.pop();
                lev.push_back(n->val);
                for(auto c:n->children)
                    q.push(c);
            }
            ans.push_back(lev);
        }
        return ans;
    }
};