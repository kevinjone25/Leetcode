class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        
        int l = arr.size();
        sort(arr.begin(), arr.end());
        vector<vector<int> > ans;
        int dmin=INT_MAX;
        
        for (int i = 0; i < arr.size() - 1; ++i) {
            dmin = min(arr[i + 1] - arr[i], dmin);
        }
        for (int i = 0; i < arr.size() - 1; ++i) {
            if (arr[i + 1] - arr[i] == dmin)
                ans.push_back({arr[i], arr[i + 1]}); //將一元vector推進二元vector
        }    
                
        return ans;

    }
};