class Solution {
public:
    bool isPowerOfFour(int n) {
        //n>0確保為正
        //n&(n-1)確保為2的冪
        //4的冪次只會有一個1，每次移兩位，判斷1在不在正確位置上就好
        //5是0101，0x555...與這個表確認位置是否正確
        return n>0 && (n&(n-1))==0 && (n&0x55555555);
    }
};