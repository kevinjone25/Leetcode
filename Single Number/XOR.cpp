class Solution {
public:
    int singleNumber(vector<int>& nums) {
        //利用XOR運算，重複的數會被消去
        int ans=nums[0];
        for(int i=1;i<nums.size();++i)
            ans^=nums[i];
        return ans;
    }
};