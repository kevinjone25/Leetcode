class Solution {
public:
    vector<int> countBits(int n) {
        /*
        在位元運算裡面，左移一次相當於數字乘2
        此時Bits裡1的數目依然相等
        按照這特性，我們可以推出ans[i]=ans[i/2](偶數情況下)
        至於奇數的話只要再補個1就好
        因此最後得出ans[i]=ans[i/2]+i%2
        */
        vector<int>ans(n+1);
        ans[0]=0;
        for(int i=1;i<n+1;++i)
            ans[i]=ans[i/2]+i%2;
        return ans;
    }
};