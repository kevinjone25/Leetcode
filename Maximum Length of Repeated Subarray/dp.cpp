class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        vector<int>dp(nums1.size()+1,0);
        int maxl=0;
        for(int i=0;i<nums1.size();++i)
        {
            //dp的每一格會記錄到該格以某元素為尾的子序列長度
            //代表外層迴圈每跑一次
            //dp裡每格的狀態會被更新為到該格以nums1[i]為尾的子序列長度
            for(int j=nums2.size()-1;j>=0;--j)
            {
                /*
                如果元素相同將該格的子序列長度更新為上一格紀錄的長度+1
                不一樣的話將該格歸0
                並更新最長子序列長度
                */
                if(nums1[i]==nums2[j])
                    dp[j+1]=dp[j]+1;
                else
                    dp[j+1]=0;
                maxl=max(maxl,dp[j+1]);
            }
        }
        //最後返回最大長度即可
        return maxl;
    }
};