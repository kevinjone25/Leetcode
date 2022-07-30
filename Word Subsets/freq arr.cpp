class Solution {
public:
     vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
         vector<string> ans;
         //紀錄words2裡字母出現的最大次數
         vector<int>universal(26,0);
         for(int i=0;i<words2.size();++i)
         {
             vector<int> temp(26,0);
             for(char &ch : words2[i])
                 if(universal[ch-'a'] < ++temp[ch-'a']) 
                     ++universal[ch-'a'];
         }
         //如果words1的字母出現次數小於之前紀錄的最大頻率
         //代表words2裡有不屬於該字串的子集
         for(string str : words1)
         {
             vector<int> freq(26,0);
             for(char &ch : str) 
                 ++freq[ch-'a'];
             int i=0;
             for(;i<26;++i)
                 if(freq[i]<universal[i]) 
                     break;
             if(i==26) 
                 ans.push_back(str);
         }
         return ans;
    }
};