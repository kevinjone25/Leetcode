class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        vector<vector<int>> charMap(26);
        int n=s.length();
        for(int i=0;i<n;++i)
            charMap[s[i]-'a'].push_back(i);//將每個字母出現的索引記錄下來
        
        int ans=words.size();
        for(auto& word:words) 
        {
            int last=-1;//紀錄在s裡的位置
            for(char c:word)
            {
                auto& cIndexes=charMap[c-'a'];
                //對該字母存取的索引進行二分搜
                //upper_bound找出「大於」last的「最小值」的位置
                auto it=upper_bound(cIndexes.begin(),cIndexes.end(),last);
                if(it==cIndexes.end())//再往後找不到相符字元
                {
                    --ans;
                    break;
                } 
                else//找到相符字元，更新last
                    last=*it;
            }
        }
        return ans;
    }
};