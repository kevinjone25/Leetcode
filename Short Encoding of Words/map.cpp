class Solution {
public:
    static bool cmp (string& first, string& second) {
        return first.size() > second.size();
    }
    int minimumLengthEncoding(vector<string>& words) {
        unordered_map<string,int>m;
        //字串從長排到短
        sort(words.begin(),words.end(),cmp);
        int ans=0;
        //把每個字串對應的map值+1
        for(int i=0;i<words.size();++i)
            ++m[words[i]];
        //因為長字串不可能是短字串的子字串，
        //所以從前面開始將字串所有可能的後綴從map裡移除
        for(int i=0;i<words.size();++i)
        {
            int k=words[i].size();
            //如果該字串還在map裡，答案加上字串和#長度
            if(m[words[i]])
                ans+=(k+1);
            //刪除現在字串所有後綴的map值
            for(int j=k-1;j>=0;j--)
            {
                string s=words[i].substr(j, k-j);
                m[s]=0;
            }
        }
        return ans;
    }
};