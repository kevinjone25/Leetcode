class Solution {
public:
    static bool cmp (vector<int>& first, vector<int>& second) {
        return first[1] < second[1];
    }
    int scheduleCourse(vector<vector<int>>& courses) {
        int maxcrs=0,nowday=0;//最大路程數,累積路程
        priority_queue<int>crs;
        //根據路程的期限，從先到後來排序
        sort(courses.begin(),courses.end(),cmp);
        //排序好後只要不斷去試著壓縮路程就好
        for(int i=0;i<courses.size();++i)
        {
            if(nowday+courses[i][0]<=courses[i][1])//路程在期限內就加進去
            {
                ++maxcrs;
                nowday+=courses[i][0];
                crs.push(courses[i][0]);
            }
            else if(!crs.empty() && courses[i][0]<crs.top())
            {
                //當此路程加上去後超過期限
                //跟之前走過最長路程判斷那個更短
                //由於依照期限排序過，更短的絕對能與更長的替換(替換後路程數不變)
                //路程數不變，累積路程更短絕對是更優解
                nowday-=(crs.top()-courses[i][0]);
                crs.pop();
                crs.push(courses[i][0]);
            }
        }
        return maxcrs;
    }
};