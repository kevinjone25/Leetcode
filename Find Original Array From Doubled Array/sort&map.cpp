class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        if (changed.size() & 1) 
            return {};
        unordered_map<int, int> m;
        //用map紀錄頻率再比對數量
        for(auto x: changed) 
            ++m[x];
        vector<int> ans;
        sort(changed.begin(), changed.end());
        //刪除重複元素
        changed.erase(unique(changed.begin(), changed.end()), changed.end());
        for(auto x : changed) 
        {
            if(m[x] > m[x * 2])
                return {};
            for(int i = 0; i < m[x]; ++i)
            {
                ans.push_back(x);
                m[x * 2] -= 1;
            }
        }
        return ans;
    }
};