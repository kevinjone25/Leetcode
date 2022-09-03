class Solution {
public:
    vector<int> numsSameConsecDiff(int n, int k) {
        //將第一位數放入deque
        deque<int> q{ 1, 2, 3, 4, 5, 6, 7, 8, 9 };
        //跑n-1次，用BFS方式擴展
        while(--n) 
        {
            int sz = q.size();
            for(int i = 0; i < sz; ++i) 
            {
                int p = q.front();
                q.pop_front();
                for (int j = 0; j < 10; ++j) 
                {
                  if (abs((p % 10) - j) == k)//擴展差為k的下一位數
                    q.push_back(p * 10 + j);
                }
            }
        }
        return vector<int>{q.begin(), q.end()};
    }
};