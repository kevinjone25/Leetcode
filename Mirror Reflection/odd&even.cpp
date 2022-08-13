class Solution {
public:
    int mirrorReflection(int p, int q) {
        /*
        問題轉化成 m * p = n * q(反射路徑可以額外畫成鏡像空間)
        m = 房間擴展的數量+1。
        n = 光反射的數量+1。
        如果光反射的數量是奇數（n是偶數），代表最後落點在左邊。終點可能是2。
        否則落點就在右邊。終點可能是0和1。
        若是落點在右邊。
        並且房間擴展數是偶數（m是奇數），代表終點是1，否則終點是0。
        m 是偶數 & n 是奇數 => return 0.
        m 是奇數 & n 是奇數 => return 1.
        m 是奇數 & n 是偶數 => return 2.
        */
        while (p % 2 == 0 && q % 2 == 0)//除2直到有一方為奇數
        { 
            p/=2;
            q/=2;
        }
        return 1 - p % 2 + q % 2;
    }
};