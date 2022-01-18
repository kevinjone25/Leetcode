class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        /*
        由於區間不相交的氣球不管如何都是無法一起燒掉的
        所以不用特地去找哪個區間重疊最多，因此sort過後
        讓起點靠前的氣球排在最前面，接著用迴圈跑一遍
        再用while迴圈判斷哪些氣球重疊可跳過，過程不斷更新重疊區間最小右邊界(避免蓋過獨立區間)
        無法重疊後回到for迴圈，繼續判斷另一個重疊區間，並將箭矢數+1
        */
        int minarr=0,l=points.size();
        sort(points.begin(),points.end());
        for(int i=0;i<l;++i)
        {
            ++minarr;
            if(i==l-1)
                break;
            int ni=i+1,right=points[i][1];
            while(right>=points[ni][0])
            {
                right=min(right,points[ni][1]);
                ++ni;
                if(ni==l)
                    break;
            }
            i=ni-1;
        }
        return minarr;
    }
};