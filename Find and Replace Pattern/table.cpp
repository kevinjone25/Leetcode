class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string>res;
        int l=pattern.length();
        for(int i=0;i<words.size();++i)
        {
            vector<int>v(26,-1),b(26,0);
            int j=0;
            for(;j<l;++j)
            {
                //存取字母的映射狀況並判斷有沒有重疊等情況
                if(v[pattern[j]-'a']<0 && !b[words[i][j]-'a'])
                {
                    v[pattern[j]-'a']=words[i][j]-'a';
                    b[words[i][j]-'a']=1;
                }
                else if(v[pattern[j]-'a']!=words[i][j]-'a')
                {
                    break;
                }
            }
            if(j==l)
                res.push_back(words[i]);
        }
        return res;
    }
};