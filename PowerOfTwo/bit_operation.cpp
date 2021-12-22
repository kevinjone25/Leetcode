class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n<=0) return false;
        return ((n&(n-1))==0); //因為n-1不會擁有n的2進位位數 其實也是因為結論得出來的
        // 'Always remember bit manipulation techniques are usually based on observations from multiple examples' by大佬
    }
};