class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int minT=0;
        for(int i=colors.size();i>0;--i)
        {
            if(colors[i]==colors[i-1])
            {
                //遇到連續顏色的氣球
                //不要拿花最大時間的氣球就好了
                //代表只要計算區間總和再扣掉最大值
                //就是要拿掉的氣球的總時間
                int total=0,maxT=-1,j=i;
                while(j>=0 && colors[j]==colors[i])
                {
                    total+=neededTime[j];
                    if(neededTime[j]>maxT)
                        maxT=neededTime[j];
                    --j;
                }
                minT+=(total-maxT);
                i=j+1;
            }
        }
        return minT;
    }
};