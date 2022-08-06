class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        /*
        假設有p隻豬，N個水桶
        總共可以測試T次( T = timetoTest / TimetoDie )
        而這T次測試可以得到(T+1)個結果
        => 第一次死掉、第二次死掉...第T次死掉或都沒死掉
        接下來換個方向方便理解
        假設有15(N)個水桶，可以測試4(T)次
         0  1  2  3  4
         5  6  7  8  9
        10 11 12 13 14
        而現在有2(p)隻豬，一隻一次喝一個橫排的水桶，另一隻喝直排的水桶
        透過各結果相交的關係可以得知哪個水桶有毒
        轉成算式就是(4+1)*(4+1)>=15 ===>(4+1)^2>=15
        從這算式可以得知25個水桶的情況也還適用在兩隻豬能解決的範圍
        接著我們得出(T+1)^p>=N的算式
        而更多水桶和豬的情況就是擴展成更高維的狀況，三維以上就很難想像了
        之後就是得出p
        p >= log(N)/ log(T+1);
        */
        return ceil(log(buckets) / log(minutesToTest / minutesToDie + 1));
    }
};