class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size(),n=grid[0].size(),res=0;
        for(int i=0;i<m;++i)
        {
            for(int j=0;j<n;++j)
            {
                if(grid[i][j]=='1')
                {
                    ++res;
                    dfs(grid,i,j,m,n);
                }
            }
        }
        return res;
    }
    void dfs(vector<vector<char>>& g,int y,int x,int m,int n)
    {
        if(x==n||x<0||y==m||y<0||g[y][x]=='0')
            return;
        g[y][x]='0';
        dfs(g,y+1,x,m,n);
        dfs(g,y-1,x,m,n);
        dfs(g,y,x+1,m,n);
        dfs(g,y,x-1,m,n);
        return;
    }
};