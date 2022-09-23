class Solution {
public:
    //計算n轉成2進位的長度
    int numberOfBits(int n) {
		  return log2(n) + 1;
    }
    int concatenatedBinary(int n) {
        long ans = 0, MOD = 1e9 + 7;
        
        for(int i = 1; i <= n; ++i)
        {
            int len = numberOfBits(i);
            //將答案往左推移再加上去就行了
            ans = ((ans << len) % MOD + i) % MOD;
        }
        return ans;
    }
};