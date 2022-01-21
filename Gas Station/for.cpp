class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {    
        /*
        storegas代表【i車站加的油】減掉【往下一個車站消耗的油】後可儲存的油量
        totald是【總加油量】減掉【總消耗量】
        可以完成一個循環代表加油總量一定不會低於消耗總量(totald>=0)
        storegas<0的話不可能是起點，反之，storegas>=0就有可能是起點
        由於題目保證只有一解或無解，因此在連續storegas>=0的子區間內，起點只可能是最左邊的點
        */
        int storegas=0,totald=0,start=0;
        for(int i=0;i<gas.size();++i)
        {
            storegas+=gas[i]-cost[i];
            totald+=gas[i]-cost[i];
            if(storegas<0)//無法循環，存油量歸零，更新起點
            {
                start=i+1;
                storegas=0;
            }
        }
        return totald>=0?start:-1;
    }
};