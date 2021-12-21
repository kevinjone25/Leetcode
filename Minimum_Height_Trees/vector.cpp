class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<vector<int>>graph(n);
        vector<int>connect(n,0),ans;
        queue<int>q;
        if(n==1)
        {
            ans.push_back(0);
            return ans;
        }
        for(auto node:edges)
        {
            graph[node[0]].push_back(node[1]);
            graph[node[1]].push_back(node[0]);
            ++connect[node[0]];
            ++connect[node[1]];
        }
        for(int i=0;i<n;++i)
        {
            if(connect[i]==1)
            {
                q.push(i);
                --connect[i];
            }   
        }
        while(!q.empty())
        {
            int s=q.size();
            ans.clear();
            while(s--)
            {
                int curr=q.front();
                q.pop();
                ans.push_back(curr);
                for(auto node:graph[curr])
                {
                    --connect[node];
                    if(connect[node]==1)
                        q.push(node);
                }
            }
        }
        return ans;
    }
};