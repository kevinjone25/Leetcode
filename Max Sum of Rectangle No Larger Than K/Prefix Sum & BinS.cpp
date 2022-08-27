class Solution {
public:
    
    //找到不大於k的最大子序列和
    int find_max(vector<int>& arr, int k)
    {
        int n = arr.size();
        int maxi = INT_MIN; 
        
        //計算目前前綴和
        int curr_sum = 0;
        //set紀錄所有前綴和
        set<int> s;
        //如果curr_sum == k,不必扣掉任何前綴和
        s.insert(0);
        //利用前綴和相減可以得出所有子序列
        for(int i = 0; i < n; i++)
        {
            curr_sum += arr[i];
            
            //找到讓curr_sum減掉最靠近k的前綴和(sum = curr_sum - k)
            auto it = s.lower_bound(curr_sum - k);
            
            //找到就更新最大值
            if(it != s.end())
                maxi = max(maxi, curr_sum - *it);
            
            //將前綴和放入set
            s.insert(curr_sum);
        }
        return maxi;
    }
    
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        
        int n = matrix.size();
        int m = matrix[0].size();
        int maxi = INT_MIN;
        
        //取兩個行之間列的累積和(將2維壓成一維)
        for(int start_row = 0; start_row < n; start_row++)
        {
            vector<int> col_array(m, 0);
            for(int end_row = start_row; end_row < n; end_row++)
            {
                //計算列的累積和
                for(int col = 0; col < m; col++)
                    col_array[col] += matrix[end_row][col];
                //找不大於k的最大子序列和
                int curr_max = find_max(col_array, k); 
                //更新最大值     
                maxi = max(maxi, curr_max);
            }
        }   
        return maxi;
    }
};