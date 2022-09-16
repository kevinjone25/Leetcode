class Solution {
public:
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        int n = nums.size(), m = multipliers.size();
        vector<int> dp(m + 1);
        /*
        在multipliers裡的第一個倍數，只能選nums第一個左邊或右邊的數
        而第m-1個倍數有可能選到從左邊或右邊的第M個數
        因此從第m-1個倍數開始記錄可能最高分數
        */
        for (int i = m-1; i >= 0; --i) 
        {
            for (int j = 0; j <= i; ++j) 
            {
                dp[j] = max(
                    //左邊
                    multipliers[i] * nums[j] + dp[j + 1], 
                    //右邊
                    multipliers[i] * nums[j + (n - (i + 1))] + dp[j]
                );
            }
        }
        return dp[0];
    }
};