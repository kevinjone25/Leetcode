class Solution {
public:    
    int numFactoredBinaryTrees(vector<int>& arr) {
        int mod = 1e9 + 7;
        sort(arr.begin(), arr.end());
        unordered_map <int, long> Treescnt;
        for(auto num : arr)
        {
            long count = 1;//節點本身就是一棵樹
            /*
            尋找map中有沒有相乘為num的數
            有的話代表找到左子樹和右子樹(左右固定)
            將左右子樹的數量相乘，得到其組合數量
            最後加總並記錄至map中
            */
            for(auto t : Treescnt)
            {
                int root = t.first;
                if(num % root == 0 && Treescnt.find(num / root) != Treescnt.end())
                    count += Treescnt[root]*Treescnt[num/root];
            }
            Treescnt[num] = count;
        }
        int res = 0;
        for(auto r : Treescnt)
            res = (res + r.second) % mod;
        return res;
    }
};