class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n=nums.size(), steps = 0;
        nth_element(nums.begin(), nums.begin()+(n/2), nums.end());
        //這個函式會將排序後第n小的元素K移至位置n
        //並且所有位于K之前的元素都比K小，所有位于K之后的元素都比K大(不保證次序)
        int median = nums[n/2];
        //偶數個數的中位數最後還是取平均，所以選哪個答案都一樣
        for(int i=0; i<n; i++){
            steps += abs(nums[i] - median);
        }
        return steps;
    }
};