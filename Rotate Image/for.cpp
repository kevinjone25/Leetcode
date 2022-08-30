class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int i = 0, n = matrix.size();
        int k = n-1;
        //從外圍往內，順時針旋轉每個環，直到中心的環沒有元素(偶數)或剩一個元素(奇數)
        while(k>0)
        {
            for(int j=0; j<k; ++j)
            {
                int t = matrix[i][i+j];
                matrix[i][i+j] = matrix[n-i-1-j][i];
                matrix[n-i-1-j][i] =  matrix[n-i-1][n-i-1-j];
                matrix[n-i-1][n-i-1-j] = matrix[i+j][n-i-1];
                matrix[i+j][n-i-1] = t;
            }
            ++i;
            k-=2;
        }
        return;
    }
};