class Solution {
public:
    int maxResult(vector<int>& nums, int k)
    {
        int n=nums.size();
        int dp[n];
        priority_queue<pair<int,int>>pq;
        for(int i=n-1 ; i>=0 ; --i)
        {
            while(!pq.empty() && pq.top().second>i+k)
                pq.pop();//將相差大於k步的紀錄排除
            //不斷將新的紀錄放進pq中，並再從中取出目前的最大分數更新紀錄
            dp[i]=nums[i];
            dp[i]+=(!pq.empty() ? pq.top().first : 0);
            pq.push({dp[i], i});
        }
        return dp[0];
    }
};