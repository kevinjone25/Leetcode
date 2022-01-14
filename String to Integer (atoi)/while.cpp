class Solution {
public:
    int myAtoi(string s) {
        int sign=1,i=0;
        long long ans=0;
        while(i<s.length()&&s[i]==' ')//跳過空白
            ++i;
        if(i<s.length()&&(s[i]=='-'||s[i]=='+'))//判斷正負
        {
            if(s[i]=='-')   
                sign=-1;
            ++i;
        }
        while(i<s.length()&&s[i]>='0'&&s[i]<='9')
        {
            int d=(s[i]-'0')*sign;
            ans=ans*10+d;
            if(ans>INT_MAX)//正數溢位判斷
                return INT_MAX;
            if(ans<INT_MIN)//負數溢位判斷
                return INT_MIN;
            ++i;
        }
        return int(ans);
    }
};