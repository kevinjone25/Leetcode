class Solution {
public:
	vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();
        int left = 0, right = n - k, startIdx = 0;
        //用二分搜不斷去逼近
        //使startIdx最後落在最接近x的區間的第一個位置
        while (left <= right) 
        {
            int mid = left + (right - left) / 2;
            if(mid+k == n || x - arr[mid] <= arr[mid+k] - x)
            {
                startIdx = mid;
                right = mid - 1;
            } 
            else
                left = mid + 1;
        }
        return vector<int>(arr.begin() + startIdx, arr.begin() + startIdx + k);
	}
};