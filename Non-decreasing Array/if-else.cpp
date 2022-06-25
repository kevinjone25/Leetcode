class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int mod=1,left;
        if(nums.size()==1)
            return true;
        else
        {
            if(nums[1]<nums[0])//開頭兩點遞減修改最左點絕對是最佳狀況
                mod=0;//修改次數用完
        }
        //已確保左中兩點遞增
        /*剩下兩種情況
        1.左點>右點，則右點往上移
        2.左點<=右點，中點往下移
        保持三點遞增且極值最小
        */
        for(int i=1;i<nums.size()-1;++i)
        {
            if(nums[i]>nums[i+1])
            {
                if(nums[i-1]>nums[i+1] && mod)//左點>右點
                {
                    nums[i+1]=nums[i];
                    mod=0;
                }
                else if(mod)//左點<=右點
                {
                    nums[i]=nums[i-1];
                    mod=0;
                }
                else
                    return false;
            }
        }
        return true;
    }
};