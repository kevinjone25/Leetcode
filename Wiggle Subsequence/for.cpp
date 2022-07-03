class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        //1的情況
        if(nums.size()==1)//只有一個數
            return 1;
        int i=1;
        while(nums[i]==nums[0] && ++i<nums.size());  
        if(i==nums.size())//數列都是相同樹
            return 1;
        
        int maxl=2,b=1;//b判斷接下來的數要比較大還小
        if(nums[i++]>nums[0])//先確定一開始的差是正還是負
            b=-1;
        for(;i<nums.size();++i)
        {
            if((nums[i]-nums[i-1])*b>0)
            {
                b*=-1;
                ++maxl;
            }
        }
        return maxl;
    }
};