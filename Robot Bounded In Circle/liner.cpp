class Solution {
public:
    bool isRobotBounded(string instructions) {
        /*把位置跟方向想成x-y坐標軸
        而重複走在一個圖形上有兩種情況

        第一種情況：指令完成後，x和y方向的位移皆為0。
        因為不管最後方向如何，完成指令後還是會回到原點。
        
        第二種情況：最後不是+y方向(北方，一開始的方向)。
        不管x和y位移多少，最後轉向只要不是+y方向，
        x和y的位移還是會因為不斷轉向，因此改變+-被抵銷掉
        */
        int x=0,y=0,d=0;//x位移,y位移,方向
        //這裡d以0,1,2,3分別代表北,東,南,西
        for(auto i:instructions)
        {
            if(i=='G')
            {
                switch(d)
                {
                    case 0://+y
                        ++y;
                        break;
                    case 1://+x
                        ++x;
                        break;
                    case 2://-y
                        --y;
                        break;
                    case 3://-x
                        --x;
                        break;
                }
            }
            else if(i=='L')
                d=(d+3)%4;//%4保證區間0~3
            else
                d=(d+1)%4;
        }
        return (x==0&&y==0)||d!=0;
    }
};