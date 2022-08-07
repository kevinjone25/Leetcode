class Solution {
public:
    int countVowelPermutation(int n) {
        long a = 1, e = 1, i = 1, o = 1, u = 1, mod = 1e9+7;
        long a2, e2, i2, o2, u2; 
        /*
        a後可以接e,i,u
        e後可以接a,i
        i後可以接e,o
        o後可以接i
        u後可以接i,o
        用各個變數存以該字母為首的字串數量
        接著按照規則更新不同字母為首的字串數量
        */
        for (int j = 2; j <= n; ++j) 
        {
            a2 = (e + i + u) % mod;
            e2 = (a + i) % mod;
            i2 = (e + o) % mod;
            o2 = i;
            u2 = (i + o) % mod;
            
            a = a2, e = e2, i = i2, o = o2, u = u2;
        }
        return (a + e + i + o + u) % mod;
    }
};