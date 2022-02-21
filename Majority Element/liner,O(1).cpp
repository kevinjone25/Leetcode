class Solution {
public:
    int majorityElement(vector<int>& nums) {
        /*
        保證一定會有一個數出現次數大於[n/2]
        設count來計數，maj代表出現最多的元素
        可以確定maj出現次數大於其他數的出現次數總和
        所以遍歷一次數組
        若count為0，則更新maj並將count+1
        不為0時，若當前數字與maj相同將count+1
        否則將count-1
        由於maj出現次數最多，最後絕對會把其他數的count抵銷
        所以最後maj一定會更新成正確答案
        */
        int maj,count=0;
        for(auto num:nums)
        {
            if(count==0)
            {
                maj=num;
                ++count;
            }
            else if(num==maj)
                ++count;
            else
                --count;
        }
        return maj;
    }
};