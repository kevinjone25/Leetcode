class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        
        vector<int>sub;
        /*
        維護一個遞增數列
        長度一樣時，元素更小的數列是最佳解
        遇到比尾端大的數時，擴展遞增數列
        若比尾端小
        則透過替換元素在不影響數列長度的同時
        將數列更新成最佳解
        */
        for(auto num : nums) 
        {
            if(sub.empty() || sub.back() < num)//比尾端元素大，擴展長度
                sub.push_back(num);
            else//二分搜尋找替換的元素
                *lower_bound(sub.begin(), sub.end(), num) = num;
        }
        return sub.size();
    }
};