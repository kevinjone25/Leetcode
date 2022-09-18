class Solution {
public:
    int trap(vector<int>& height) {
        int N = height.size(), ans = 0;
        
        vector<int> left(N, 0), right(N, 0);
        //最左右不會積水，可以忽略
        for(int i = 1; i < N; ++i)//找出該點左邊最高 
            left[i] = max(left[i - 1], height[i - 1]);
        
        for(int i = N - 2; i >= 0; --i)//找出該點右邊最高
            right[i] = max(right[i + 1], height[i + 1]);
        
        for(int i = 1; i < N - 1; ++i)//右邊和左邊最低減上該點高度就是積水高度
            ans += max(0, min(left[i], right[i]) - height[i]);
        
        return ans;
        
    }
};