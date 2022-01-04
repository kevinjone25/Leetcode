class Solution {
public:
    int bitwiseComplement(int n) {
       //~是取一補數
        if(n == 0) return 1;
        unsigned mask=~0;//全是1的遮罩(位移運算盡量用無號數)
        /*
          num: ...00000101 = 5
         ~num: ...11111010
         mask: ...11111000<=(下面迴圈)...11111111
    ~num^mask: ...00000010 = 2
        */
        while(n&mask)
            mask=mask<<1; //跟476題一樣
        return ~n^mask;

    }
};