class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int ans=0,diff=INT_MAX;
        for(int i=0; i<n-2; ++i)
        {
            int left=i+1; int right=n-1;
            //從左右往中間逼近，找出最接近target的sum
            while(left<right)
            {
                int sum=nums[i]+nums[left]+nums[right];
                if (sum > target)
                    --right;
                else if(sum < target)
                    ++left;
                else 
                    return target;
                if(abs(target-sum) < diff)
                {
                    diff=abs(target-sum);
                    ans=sum;
                }
            }
        }
        return ans;
    }
};