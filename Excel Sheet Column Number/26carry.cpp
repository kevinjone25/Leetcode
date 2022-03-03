class Solution {
public:
    int titleToNumber(string columnTitle) {
        //26進位
        int ans=0;
        for(auto c:columnTitle)
            ans=ans*26+(c-'@');
        return ans;
    }
};