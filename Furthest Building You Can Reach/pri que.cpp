class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int fur;
        if(!bricks && !ladders)
        {
            for(fur=0;fur<heights.size()-1;++fur)
                if(heights[fur+1]-heights[fur]>0)
                    break;
            return fur;
        }//這個都為0時的特例判斷是可以刪的
        priority_queue<int,vector<int>,greater<int>>q;
        //要到達最遠的大樓需要把使用梯子的效率最大化
        //使用優先佇列來維持
        for(fur=0;fur<heights.size()-1;++fur)
        {
            int dh=heights[fur+1]-heights[fur];
            if(dh>0)//高度差為正才需要做判斷
            {
                if(q.size()==ladders)//沒有可用的梯子
                {
                    if(ladders && q.top()<dh)//有更高的差來使用梯子
                    {
                        //維持梯子使用效率
                        q.push(dh);
                        dh=q.top();
                        q.pop();
                    }   
                    bricks-=dh;
                    if(bricks<0)
                        break;
                }
                else if(ladders)
                    q.push(dh);
            }
        }
        return fur;
    }
};