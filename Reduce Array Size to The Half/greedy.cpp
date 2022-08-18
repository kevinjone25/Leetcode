class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int,int>m;
        int hn=arr.size()/2;
        for(int i = 0; i < arr.size(); ++i) 
            ++m[arr[i]];
        priority_queue<int> pq;
        for(auto it: m) 
            pq.push(it.second);
        int ans = 0, minus = 0;
        while(!pq.empty())
        {
            ++ans;
            minus += pq.top();
            if(minus >= hn) 
                return ans;
            pq.pop();
        }
        return ans;
    }
};