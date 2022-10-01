class Solution {
public:
    int numDecodings(string s) {
        
        int dp[s.size()+2];
        memset(dp,0,sizeof(dp));
        dp[s.size()] = 1;
        //從後面開始dp
        for(int i = s.size()-1; i >= 0; --i)
        {
            if(s[i] == '0')
            {
                //0一定是跟前面的配對，只會有"10"和"20"
                //因此出現s開頭為0,"00","30"等情況就無法解碼，回傳0
                if(i-1<0 || s[i-1] == '0' || s[i-1]-'0' > 2) 
                    return 0;
                //跳過0，直接記錄到0的下一項
                //這樣子遇到"220"才不會紀錄到(22 0)這種錯誤的情況
                --i;
                dp[i] += dp[i+2];
            }
            else
            {
                dp[i] += dp[i+1];
                if(s[i]-'0' < 3)//1和2可以接上一項
                {
                    //確認沒超過26
                    if((s[i]-'0' > 1 && s[i+1]-'0' < 7) || s[i]-'0' < 2)
                        dp[i] += dp[i+2];
                }
            }
        }   
        return dp[0];
    }
};