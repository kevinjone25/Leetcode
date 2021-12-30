class Solution {
public:
    int calculate(string s) {
        vector<int>nums;
        char op='+';//上一個運算符號
        long long ans=0;
        int curr=0;
        /*
              1           +     3      /        2......
          (已計算過)      op   curr   s[i]     (未計算過) 
          
          過程大概像上面那樣
         */
        for(int i=0;i<s.length();++i)
        {
            if(s[i]>='0'&&s[i]<='9')//算現在的數
                curr=curr*10+(s[i]-'0');
            if(i==s.length()-1||s[i]=='+'||s[i]=='-'||s[i]=='*'||s[i]=='/')
            {//如果是運算符號就做出相應運算，結尾時也要計算
                if(op=='+')
                    nums.push_back(curr);
                else if(op=='-')
                    nums.push_back(-curr);
                else if(op=='*')
                {
                    int num=nums.back();//取出上一個數
                    nums.pop_back();
                    nums.push_back(num*curr);
                }
                else if(op=='/')
                {
                    int num=nums.back();//取出上一個數
                    nums.pop_back();
                    nums.push_back(num/curr);
                }
                curr=0;//歸零，準備算下一個數
                op=s[i];//更新運算符號
            }
        }
        while(!nums.empty())
        {
            ans+=nums.back();
            nums.pop_back();
        }
        return ans;
    }
};