class Solution {
public:
    int minPartitions(string n) {
        /*
        組成的數只會有0和1
        因此只要找位數的數字最大到哪就好
        實際上跟字串代表的數字大小無關
        */
        int maxn=0;
        for(auto num:n)
        {
            if(num-'0'>maxn)
            {
                maxn=num-'0';
                if(maxn==9)
                    return maxn;
            }      
        }
        return maxn;
    }
};