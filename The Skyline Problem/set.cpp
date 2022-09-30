class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        multiset<int> st = {0};
        multiset<vector<int>> walls;
        vector<vector<int>>ans;
        int curHeight = 0;
        for(auto b:buildings)
        {//用正負區分building起點終點
            walls.insert({b[0],-b[2]});
            walls.insert({b[1],b[2]});
        }
        for(auto w:walls)
        {
            if(w[1] < 0)//將該building的高度加進st
                st.insert(-w[1]);
            else//將該高度從st裡移除
                st.erase(st.find(w[1]));
            
            //目前最高的高度跟現在高度對不上
            //代表該高度已被移除，加入下一個高度
            if(*st.rbegin() != curHeight)
                ans.push_back({w[0],curHeight=*st.rbegin()});
        }
        return ans;
    }
};