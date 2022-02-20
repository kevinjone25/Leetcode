class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        /*
        排序過後保證數組以l遞增排序
        只要更新判斷用的[l,r]就可以輕鬆知道下一組區間有沒有被覆蓋，
        */
        int l=intervals[0][0],r=intervals[0][1],ans=intervals.size();
        for(int i=0;i<intervals.size()-1;++i)
        {
            if(r>=intervals[i+1][1])
                --ans;
            else
            {
                if(l==intervals[i+1][0])//被下一個區間覆蓋
                    --ans;
                else
                    l=intervals[i+1][0];//更新l
                r=intervals[i+1][1];//更新r
            }   
        }
        return ans;
    }
};