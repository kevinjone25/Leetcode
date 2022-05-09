class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string>v;
        int li=digits.length();
        if(li==0)
            return v;
        string str;
        com(v,digits,str,0,li);
        return v;
    }
    void com(vector<string>&v,string d,string s,int ni,int l)
    {
        if(ni==l)
        {
            v.push_back(s);
            return;
        }
        int o=3*(d[ni]-'2'),n;
        if(d[ni]-'0'==7||d[ni]-'0'==9)
            n=4;
        else
            n=3;
        if(d[ni]-'0'>7)
            ++o;        
        for(int i=0;i<n;++i)
        {
            string c;
            
            c.append(1,char('a'+o+i));
            com(v,d,s+c,ni+1,l);
        }
    }
};