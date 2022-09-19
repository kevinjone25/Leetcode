class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        unordered_map<string, vector<string>>hash;
        //用map紀錄相同內容的文件
        for(auto p : paths)
        {
            stringstream ss(p);
            string dir;
            string file;
            ss>>dir;
            while(ss>>file) 
            {
                string content = file.substr(file.find('(') + 1, file.find(')') - file.find('(') - 1);//內容
                string path = dir + '/' + file.substr(0, file.find('('));//路徑
                hash[content].push_back(path);
            }
        }
        vector<vector<string>> res;
        for(auto it = hash.begin(); it != hash.end(); ++it) 
        {
            if (it->second.size() > 1)//內容為此的文件超過1個
                res.push_back(it->second);
        }
        return res;
    }
};