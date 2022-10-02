class Solution {
public:
    int numRollsToTarget(int n, int k, int target) {
        if(n > target)
            return 0;
        vector<int>dp(target+1,0);
        int MOD = 1e9+7;
        //我先把一個骰子的情況先設好
        //這樣就不用將dp[0]設1，之後再設0了(line24)
        //雖然可以把長度縮小，但索引1~target更方便閱讀
        for(int i=1;i<=k && i<=target;++i)
            dp[i]=1;

        for(int i=2;i<=n;++i)//幾顆骰子
        {
            for(int j=target;j>=1;--j)//目標值
            {
                //用額外的count去計算
                //這樣就可以用一維陣列節省空間
                long count = 0;
                for(int d=1;d<=k;++d)//骰到多少
                {
                    if(j-d>0)
                        count += dp[j-d];//將配對的情況加進去
                    count %=MOD;
                }
                dp[j] = (int) count;
            }
            /*if(i==1)
                dp[0] = 0;*/
        }
        return dp[target];
    }
};