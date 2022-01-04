class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int>trusted(n+1,0);
        //法官的條件是被所有人(n-1)信任
        for(auto t:trust)
        {
            trusted[t[0]]=-1;//如果有信任的人，設為-1，排除其值最後不可能為n-1的可能
            ++trusted[t[1]];//被1人信任
        }
        for(int i=1;i<=n;++i)
            if(trusted[i]==n-1)//最後值仍是n-1的人為法官
                return i;
        return -1;
    }
};