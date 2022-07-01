class Solution {
public:
    static bool cmp (vector<int>& first, vector<int>& second) {
        return first[1] > second[1];
    }
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(),boxTypes.end(),cmp);
        int maxu=0;
        for(int i=0;i<boxTypes.size();++i)
        {
            if(truckSize>boxTypes[i][0])
            {
                truckSize-=boxTypes[i][0];
                maxu+=boxTypes[i][0]*boxTypes[i][1];
            }
            else
                return maxu+truckSize*boxTypes[i][1];
        }
        return maxu;
    }
};