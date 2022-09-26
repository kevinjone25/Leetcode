class Solution {
    //存取每個點的根節點
    int root[26];
    //找到根節點
    int rootfind(int x) {
        return root[x] == x ? x : (root[x] = rootfind(root[x]));
    }
public:
    bool equationsPossible(vector<string>& equations) {
        //將每個點的根節點設為自己
        for(int i = 0; i < 26; ++i)
            root[i] = i;
        for(auto e : equations) 
        {
            //將等式左邊點的根節點指向右邊點的根節點
            if(e[1] == '=')
                root[rootfind(e[0] - 'a')] = rootfind(e[3] - 'a'); 
        }
        //經過上述步驟，等值群體裡的點都會指向同一個根節點
        for(auto e : equations) 
        {
            //最後只要判斷邏輯有沒有衝突就好了
            if(e[1] == '!' && rootfind(e[0] - 'a') == rootfind(e[3] - 'a')) 
                return false;
        }
        return true;
    }
};