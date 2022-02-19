class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        /*
        先將奇數乘2(去除其中一種操作)，再用set存所有數
        接著當set中最大元素還是偶數時，不斷執行除2和更新diff(縮小全距)
        若最大值為奇數，則代表無法再縮小diff，返回diff
        */
        set<int>s;
        for(auto n:nums)
        {
            if(n&1)//奇數乘2
                s.insert(n*2);
            else
                s.insert(n);
        }
        int diff=*s.rbegin()-*s.begin();
        while(!(*s.rbegin()&1))//當最大值還是偶數時
        {
            int num=*s.rbegin();
            s.erase(num);
            s.insert(num/2);
            diff=min(diff,*s.rbegin()-*s.begin());
        }
        return diff;
    }
};