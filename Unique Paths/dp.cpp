class Solution {
public:
    int uniquePaths(int m, int n) {
        int x=min(m,n),y=max(m,n);
        vector<int>dp(x,1);
        for(int i=1;i<y;++i)
            for(int j=1;j<x;++j)
                dp[j]+=dp[j-1];
        return dp[x-1];
    }
};