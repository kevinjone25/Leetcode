class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        //使用優先佇列存取，保證距離最大的點會在最前面
        priority_queue<vector<int>>d;
        vector<vector<int>>ans;
        for(auto p:points)
        {
            d.push({p[0]*p[0]+p[1]*p[1],p[0],p[1]});
            if(d.size()>k)//佇列裡的點超過k個，就把現在距離最大的點pop掉
                d.pop();
        }
        while(!d.empty())//資料存入vector
        {
            auto p=d.top();
            ans.push_back({p[1],p[2]});
            d.pop();
        }
        return ans;
    }
};