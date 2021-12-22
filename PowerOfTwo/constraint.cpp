class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n==0) return false;
        return (n>0)&&(1073741824%n==0); //利用題目限制的寫法 因為最大的2進位數除以比較小的一定會整除
    }
};