class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int>ans;
        int c[26]={0},l=s.length();
        for(int i=l-1;i>=0;--i)//紀錄每個字母最後一次出現位置
        {
            if(!c[s[i]-'a'])
                c[s[i]-'a']=i;
        }
        int cnt=0,nfar=0;
        /*cnt紀錄現在子字串長度
        nfar紀錄子字串中字元在陣列c裡最後面的位置
        */
        for(int i=0;i<l;++i)
        {
            if(c[s[i]-'a']>nfar)
                nfar=c[s[i]-'a'];
            ++cnt;
            if(nfar==i)
            {
                ans.push_back(cnt);
                cnt=0;
            }
        }
        return ans;
    }
};