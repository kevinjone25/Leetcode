class Solution {
public:
    bool wordPattern(string pattern, string str) {
        unordered_map<char, string> m;
        istringstream in(str);
        int i = 0, n = pattern.size();
        for (string word; in >> word; ++i) {  //用map來做 一個key只會對應到一個value
            if (i >= n) continue;             //若是遇到新的 則去檢查有沒有同key不同值的
            if (m.count(pattern[i])) {
                if (m[pattern[i]] != word) return false;
            } else {
                for (auto a : m) {
                    if (a.second == word) return false;
                }
                m[pattern[i]] = word;
            }
        }
        return i == n;
    }
};