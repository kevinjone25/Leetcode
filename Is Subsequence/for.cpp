class Solution {
public:
    bool isSubsequence(string s, string t) {
        int si=0,ti=0;
        for(;ti<t.length();++ti)
            if(t[ti]==s[si])
                ++si;
        if(si==s.length())
            return true;
        else
            return false;
    }
};