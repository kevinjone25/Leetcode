class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int>ans;
        //用unordered_map建立字串的頻率表
        unordered_map<string,int>mp;
        for(auto w:words) 
            ++mp[w];
        
        int n=words.size();//n個子字串
        int l=words[0].size();//每個子字串長度為l
        int total=l*n;//所有子字串連起來的長度
        if(s.size()<total)
            return ans;
        for(int i=0;i<=s.size()-total;++i)
        {
            unordered_map<string,int>temp;         
            int k;
            for(k=0;k<n;++k)
            {
                string sub=s.substr(i+k*l,l);//從s中取出長度為l的子字串
                if(mp.find(sub)==mp.end() || temp[sub]+1>mp[sub])//找不到字串
                    break;
                ++temp[sub];//紀錄頻率
            }
            if(k==n)//如果所有頻率符合，就紀錄答案
                ans.push_back(i);
        }
        return ans ;
    }
};