class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string>dict(wordList.begin(),wordList.end());//加入set方便搜索
        if(dict.find(endWord)==dict.end())//找不到結尾單詞，無解
            return {};
        dict.erase(beginWord);
        dict.erase(endWord);
        
        unordered_map<string,int>steps{{beginWord,1}};//每個單詞擴展的最短步數
        unordered_map<string,vector<string>>parents;//單詞可以由哪些單詞擴展而來
        queue<string> q;
        q.push(beginWord);
        
        vector<vector<string>> ans;
        
        const int l = beginWord.length();
        int step = 0;        
        bool found = false;
        
        while(!q.empty() && !found)
        {
            ++step;            
            for(int size = q.size();size > 0;--size) 
            {
                const string p = q.front();//備份單詞 
                q.pop();
                string w = p;
                for(int i = 0;i < l;++i) 
                {
                    const char ch = w[i];
                    for(int j = 'a';j <= 'z';++j) 
                    {
                        if(j == ch)
                            continue;
                        w[i] = j;
                        if(w == endWord)//找到結尾單詞
                        {
                            parents[w].push_back(p);
                            found = true;
                        } 
                        else if(steps.find(w)!=steps.end() && step < steps.at(w))
                        {//如果單詞被擴展過(另一個路徑)，判斷它的步數
                            parents[w].push_back(p);//更新父子關係
                        }
                        if(dict.find(w)==dict.end())//單詞不在dict直接跳過
                            continue;
                        dict.erase(w);//刪掉單詞
                        q.push(w);
                        steps[w] = steps.at(p) + 1;//紀錄步數
                        parents[w].push_back(p);//更新父子關係
                    }
                    w[i] = ch;
                }
            }
        }
        
        if (found)
        {
            vector<string> curr{endWord};
            getPaths(endWord,beginWord,parents,curr,ans);
        }
    
        return ans;
    }
private:
    void getPaths(const string& word, 
                  const string& beginWord, 
                  const unordered_map<string, vector<string>>& parents,
                  vector<string>& curr,
                  vector<vector<string>>& ans) {        
        //反向查找的DFS
        if(word == beginWord)
        {
            ans.push_back(vector<string>(curr.rbegin(),curr.rend()));
            return;
        }
        
        for(const string& p : parents.at(word)) 
        {
            curr.push_back(p);
            getPaths(p, beginWord, parents, curr, ans);
            curr.pop_back();
        }        
    }
};