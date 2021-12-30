class Solution {
public:
    int smallestRepunitDivByK(int k) {
        int r[100000]={0},n=0,l=0;
        while(1)
        {
            ++l;
            n=(n*10+1)%k;//計算跟n的差
            if(!n)//差為0則可以整除
                return l;
            if(r[n])//如果這個餘數出現過，代表進入無限迴圈了
                return -1;
            r[n]=1;
        }
    }
};