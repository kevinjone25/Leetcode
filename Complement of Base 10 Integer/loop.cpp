class Solution {
public:
    int bitwiseComplement(int n) {
        int xor_string = 0;     // 取補數 就是去xor 但是前面有0的問題要先解決
        int offset = 0;
        if(n == 0)
            return 1;
        while(n >> offset){
        offset++;           // 先算出n有幾位數
        xor_string <<= 1;   //依照每移一位 要xor的string就多一位
        xor_string += 1;    //移完要加1 不然會變0
        }
        return n ^ xor_string;

    }
};