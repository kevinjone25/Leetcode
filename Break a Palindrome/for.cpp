class Solution {
public:
    string breakPalindrome(string palindrome) {
        int l=palindrome.length();
        if(l==1)//長度只有1一定是迴文
            return "";
        for(int i=0;i<l/2;++i)//由於是迴文，跑一半就好
        {
            if(palindrome[i]!='a')//遇到不是a的改成a後回傳答案
            {
                palindrome[i]='a';
                return palindrome;
            }
        }
        //能破壞迴文的位置都是a
        palindrome[l-1]='b';//從最後一格改起
        return palindrome;
    }
};