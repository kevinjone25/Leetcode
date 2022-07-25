class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if(!binary_search(nums.begin(),nums.end(),target)) 
            return {-1,-1};
        auto low = lower_bound(nums.begin(),nums.end(),target);
        auto up = upper_bound(nums.begin(),nums.end(),target);
          
        int first = low - nums.begin();
        int last = up - nums.begin()-1;
        
        return {first ,last};
    }
};