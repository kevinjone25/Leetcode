class Solution {
public:
    int maxProfit(int k, vector<int>& price) {
        
        vector<int> dp(2*k+1, INT_MIN);
        //k次交易，可以做2*k次操作(買入、賣出)
        dp[0] = 0;
        //dp[i]代表在第i次操作時的最大利潤
        for(auto p:price)
        {
            for(int i=0;i+2<=2*k;i+=2)
            {
                dp[i+1] = max(dp[i+1],dp[i]-p);
                dp[i+2] = max(dp[i+2],dp[i+1]+p);
            }
        }
        return *max_element(dp.begin(),dp.end());
    }
};