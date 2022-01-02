class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int pairs=0,r[60]={0};
        for(auto t:time)
        {
            int x=t%60;
            pairs+=r[(60-x)%60];//把相加起來為60的數量加上去
            ++r[x];//對應的位置新增一首歌
        }
        return pairs;
    }
};