class Solution {
public:    
    bool bitadd(vector<int>& nums,int sum)
    {
        bitset<10001>bit(1);//max possible sum/2 = 10000
        for(int i:nums)
            bit|=(bit<<i);
        return bit[sum]&1;
        //每個bit代表在那一位的數字，往左推就相當於加上去，
        //用or運算不會讓先前的紀錄消失，於是之前的紀錄也會跟著左移
        //就相當於最後每種組合能得到的數都會記錄在裡面
    }
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(int i:nums)
            sum+=i;
        if(sum%2!=0)
            return false;
        else
            return bitadd(nums,sum/2);
    }
};