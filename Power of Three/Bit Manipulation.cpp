class Solution {
public:
    bool isPowerOfThree(int n) {
        //int上限的3的冪的最大數字是3**19（1162261467）
        //如果可以被整除就代表是3的冪次
        return n > 0 && !(1162261467 % n);
    }
};