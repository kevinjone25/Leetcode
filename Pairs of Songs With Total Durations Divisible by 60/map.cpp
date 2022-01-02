class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int pairs=0,r[60]={0};
        for(auto t:time)
        {
            int x=t%60; // 不需要用加法 反過來用餘數考慮就好 e.g. 3%60
            pairs+=r[(60-x)%60];//把相加起來為60的數量加上去 pair+= r[57]這樣只要有除60餘57的就會被加到
            ++r[x];//%60對應的位置新增一首歌
        }
        return pairs;
    }
};