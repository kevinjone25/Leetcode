class Solution {
public:
    string addBinary(string a, string b) {
        int ai=a.length()-1,bi=b.length()-1,carry=0,an,bn,s;
        string ans="";
        //得到a,b字串每一位數，若字串已到頭則給0，接著做運算再用到ans字串上
        while(ai>=0||bi>=0)
        {
            if(ai>=0)
            {
                an=a[ai]-'0';
                --ai;
            }
            else
                an=0;
            if(bi>=0)
            {
                bn=b[bi]-'0';
                --bi;
            }
            else
                bn=0;
            s=an+bn+carry;
            ans=to_string(s%2)+ans;
            carry=s/2;
        }
        if(carry)
            ans=to_string(1)+ans;
        return ans;
    }
};