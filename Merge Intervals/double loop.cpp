class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>>ans;
        int i,j,right;//因為有可能完全把下一個區間覆蓋住，所以設right來判斷右邊界
        sort(intervals.begin(),intervals.end());
        for(i=0;i<intervals.size();++i)
        {
            j=i;
            right=intervals[i][1];
            while(j+1<intervals.size()&&right>=intervals[j+1][0])//不斷往後判斷能覆蓋到哪
            {
                right=max(right,intervals[j+1][1]);//更新右邊界
                ++j;
            }   
            ans.push_back({intervals[i][0],right});
            i=j;
        }
        return ans;
    }
};