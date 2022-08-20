class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int n=stations.size();
        int currFuel=startFuel, i=0;
        int res=0;

        priority_queue<int> pq;
        /*
        最少次加油到達目的地
        實際上就是讓總油量盡快到達目標
        */
        while(currFuel < target)
        {
            //把目前燃料能到的加油站推入優先佇列
            while(i<n && currFuel >= stations[i][0])
            {
                pq.push(stations[i][1]);
                ++i;
            }

            if(pq.empty())//還沒到目的地，油也不夠到任何加油站 
                return -1;

            currFuel += pq.top();//到目前儲油量最多的加油站加油
            //佇列裡都是確定能去的，不用管取出的順序，實際上是順路
            pq.pop();

            ++res;
        }
        return res;
    }
};