class Solution {
public:
    static bool cmp (vector<int>& first, vector<int>& second) {
        if(first[0] == second[0])
            return first[1] < second[1];
        return first[0] > second[0];
    }
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        //體重大到小排序，體重相同則依照k小到大
        sort(people.begin(),people.end(),cmp);
        vector<vector<int>>rq;
        //排序過後照順序插入第k個即可
        for(int i=0;i<people.size();++i)
           rq.insert(rq.begin()+people[i][1],people[i]);
        return rq;
    }
};