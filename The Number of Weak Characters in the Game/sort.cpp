class Solution {
public:
    static bool cmp(vector<int> &a,vector<int> &b){
        if(a[0]!=b[0])
            return a[0]>b[0];
        return a[1]<b[1];
    }
    int numberOfWeakCharacters(vector<vector<int>>& prop) {
        //照攻擊由大至小排列，攻擊相同則依防禦小到大
        sort(prop.begin(),prop.end(),cmp);
        int maxTillNow = INT_MIN;
        int ans=0;
        for(auto p:prop)
        {
            if(maxTillNow>p[1])//當前防禦小於最大防，代表當前屬性是弱者 
                ++ans;
            else//當前防禦大於最大防則更新最大防禦
                maxTillNow=p[1];
        }
        return ans;
    }
};