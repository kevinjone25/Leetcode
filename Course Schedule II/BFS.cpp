class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>order,indegree(numCourses);
        vector<vector<int>>g(numCourses);
        queue<int>q;
        for(auto pre:prerequisites)
        {
            g[pre[1]].push_back(pre[0]);//先後順序存成圖
            ++indegree[pre[0]];
        }
        for(int i=0;i<numCourses;++i)//將葉節點推入
            if(!indegree[i])
                q.push(i);
        while(!q.empty())//BFS
        {
            int course=q.front();
            q.pop();
            order.push_back(course);
            for(auto i:g[course])
            {
                --indegree[i];
                if(!indegree[i])
                    q.push(i);
            }
        }
        if(order.size()==numCourses)
            return order;
        else
            return {};//無法全都走過
    }
};