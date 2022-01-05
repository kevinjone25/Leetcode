class Solution {
public:
    bool ispalindrome(string s,int left,int right)//判斷是不是回文的函式
    {
        while(left<right)
        {
            if(s[left]!=s[right])
                return false;
            ++left;
            --right;
        }
        return true;
    }
    void partition(string s,int start,vector<string>&result,vector<vector<string>>&ans)   
    {//判斷所有子字串的函式(DFS)
        int l=s.length();
        if(start==l)//沒有子字串可以新增了，將此種結果推入答案中
            ans.push_back(result);
        else
        {
            for(int i=start;i<l;++i)
            {
                if(ispalindrome(s,start,i))
                {
                    result.push_back(s.substr(start,i-start+1));//新增這一層的子字串
                    partition(s,i+1,result,ans);//往下探訪到下一層
                    result.pop_back();//這層往下的所有結果都加入答案了，因此pop掉，更新這一層
                }
            }
        }  
    }
    vector<vector<string>> partition(string s) {
        /*利用DFS的概念不斷往下，將各種結果(路徑)加進答案中
        當所在層數往下的結果都探訪過後，就更新這一層，繼續尋找新路徑*/
        vector<vector<string>>ans;
        vector<string>result;
        partition(s,0,result,ans);
        return ans;
    }
};