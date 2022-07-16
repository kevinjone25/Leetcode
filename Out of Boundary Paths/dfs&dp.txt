class Solution {
public:
    int dp[55][55][55];
    long long mod =1e9+7;
    int dfs(int i, int j, int n, int m, int moves)
    {   
        if(i<0 || i==n || j<0 || j==m)//到達邊界
            return 1;
        if(moves==0)//移動數變0
            return 0;
        if(dp[i][j][moves] != -1)//已經計算過就直接回傳
            return dp[i][j][moves];
        
        //往四個方向探訪下去
        int up=dfs(i-1,j,n, m,moves-1);
        int down=dfs(i+1,j,n,m,moves-1);
        int left=dfs(i,j-1,n,m,moves-1);
        int right=dfs(i,j+1,n,m,moves-1);
        
        //回傳該位置所有路徑可能數
        return dp[i][j][moves]=(up%mod + down%mod + left%mod + right%mod)%mod;
    }
    
    int findPaths(int n, int m, int maxMove, int startRow, int startColumn) {
        //初始dp所有值為-1
        memset(dp,-1,sizeof(dp));
        return dfs(startRow,startColumn,n,m,maxMove);
    }
};