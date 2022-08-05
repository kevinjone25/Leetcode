class Solution {
public:
    vector<int> dp;
    int help(vector<int> &nums, int T, int n){
		//T=0代表找到一個組合
        if(T==0)
            return 1;
        int ans=0; 
		//已經計算過的就直接使用
        if(dp[T]!=-1) 
            return dp[T];
		//若是現在的num加上去不大於T就繼續遞迴下去
        for(int i=0; i<n; i++)
        {
            if(nums[i]<=T)
                ans+=help(nums, T-nums[i], n);
        }
        return dp[T]= ans;
    }
    int combinationSum4(vector<int>& nums, int target) {
        int n=nums.size();
		//將dp值設為-1
        dp.resize(target+1,-1);
        return help(nums, target, n);
    }
};