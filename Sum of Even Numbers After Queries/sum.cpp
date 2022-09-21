class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int evenSum = 0;
        //先計算偶數和
        for(auto x : nums)
        {
            if(x % 2 == 0)
                evenSum += x;
        }
        vector<int> ans;
        for (auto q : queries)
        {
            int val = q[0], idx = q[1];
            //原先的數是偶數，先將它從偶數和移除
            if (nums[idx] % 2 == 0)
                evenSum -= nums[idx];
            //更新nums[idx]
            nums[idx] += val;
            //如果更新後的值是偶數再將它加回去
            if (nums[idx] % 2 == 0)
                evenSum += nums[idx];
            ans.push_back(evenSum);
        }
        return ans;
    }
};