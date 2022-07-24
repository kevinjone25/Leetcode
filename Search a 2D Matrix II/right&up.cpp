class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int m = matrix.size();
        int n = matrix[0].size();
        
        int i = m - 1;
        int j = 0;
        /*
        由左下角開始搜索
        如果目前值<目標，因為左上方的值都比現在值小
        所以將索引往右移
        如果目前值>目標，因為右邊的值都比現在值大
        所以將索引往上移
        重複步驟直到結束
        */
        while(i>=0 && j<n)
        {
            if(matrix[i][j] == target) 
                return true;
            else if(matrix[i][j] < target) 
                ++j;
            else
                --i;
        }
        return false;  
    }
};
