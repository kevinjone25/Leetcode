class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<pair<int,int>>time;
        int p=0;
        //依照時間順序將乘客的增減做排序
        for(auto tr:trips)
        {
            time.push_back({tr[1],tr[0]});
            time.push_back({tr[2],-tr[0]});
        }
        sort(time.begin(),time.end());
        //sort預設從小到大，因此同一時間減少乘客一定會比增加乘客優先，不用擔心誤判
        for(auto t:time)
        {
            p+=t.second;
            if(p>capacity)//超載
                return false;
        }
        return true;
    }
};