class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        /*
        由於區間不相交的氣球不管如何都是無法一起燒掉的
        所以不用特地去找哪個區間重疊最多，因此sort過後
        讓起點靠前的氣球排在最前面，接著用迴圈跑一遍
        不斷壓縮現在判斷的重疊區間，避免蓋過其他獨立區間
        這是比較簡潔的版本
        */
        int minarr=1,left=points[0][0],right=points[0][1];
        sort(points.begin(),points.end());
        for(auto r:points)
        {
            if(right>=r[0])
                right=min(right,r[1]);
            else
            {
                ++minarr;
                right=r[1];
            }
            left=r[0];//不管那種結果都要更新左邊界就順便移到這邊了
        }
        return minarr;
    }
};