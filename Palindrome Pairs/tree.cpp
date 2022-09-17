struct TrieNode {
    TrieNode *next[26] = {};
    int index = -1;
    vector<int> palindromeIndexes;
};

class Solution {
    TrieNode root;
    //將字串反過來記錄成樹
    void add(string &s, int i) {
        auto node = &root;
        for(int j = s.size() - 1; j >= 0; --j) 
        {
            if(isPalindrome(s, 0, j))//到j時前綴是迴文，記錄下來
                node->palindromeIndexes.push_back(i);
            int c = s[j] - 'a';
            if(!node->next[c])
                node->next[c] = new TrieNode();
            node = node->next[c];
        }
        node->index = i;
        node->palindromeIndexes.push_back(i);
    }
    //判斷是不是迴文
    bool isPalindrome(string &s, int i, int j) {
        while(i < j && s[i] == s[j])++i ,--j;
        return i >= j;
    }
    
public:
    vector<vector<int>> palindromePairs(vector<string>& A) {
        int N = A.size();
        //將字串加進樹中
        for(int i = 0; i < N; ++i) 
            add(A[i], i);
        
        vector<vector<int>>ans;
        
        for(int i = 0; i < N; ++i)
        {
            auto s = A[i];
            auto node = &root;
            for(int j = 0; j < s.size() && node; ++j)
            {//字串與A[i]前綴相配，A[i]後綴為迴文情況
                //EX:abcdxxx配dcba
                if(node->index != -1 && node->index != i && isPalindrome(s, j, s.size() - 1)) ans.push_back({ i, node->index }); 
                node = node->next[s[j] - 'a'];//往下個節點
            }
            if(!node)
                continue;
            for(int j : node->palindromeIndexes)
            {//後綴(or字串)與A[i]相同，前綴是迴文的字串(包括空字串"")
                //EX：abcd配dcba,lls配sssll,s配lls
                if(i != j) 
                    ans.push_back({ i, j });
            }
        }
        return ans;
    }
};