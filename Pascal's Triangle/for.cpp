class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>tri;
        tri.push_back({1});
        for(int i=0;i<numRows-1;++i)
        {
            vector<int>layer;
            layer.push_back(1);
            for(int j=1;j<=i;++j)
                layer.push_back(tri[i][j-1]+tri[i][j]);
            layer.push_back(1);
            tri.push_back(layer);
        }
        return tri;
    }
};