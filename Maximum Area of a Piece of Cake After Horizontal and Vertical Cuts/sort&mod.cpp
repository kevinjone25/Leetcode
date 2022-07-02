class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        sort(horizontalCuts.begin(),horizontalCuts.end());
        sort(verticalCuts.begin(),verticalCuts.end());
        //找出最大的寬和高
        int maxh=horizontalCuts[0],maxv=verticalCuts[0],i;
        for(i=0;i<horizontalCuts.size()-1;++i)
            if(horizontalCuts[i+1]-horizontalCuts[i]>maxh)
                maxh=horizontalCuts[i+1]-horizontalCuts[i];
        if(h-horizontalCuts[i]>maxh)
            maxh=h-horizontalCuts[i];
        for(i=0;i<verticalCuts.size()-1;++i)
            if(verticalCuts[i+1]-verticalCuts[i]>maxv)
                maxv=verticalCuts[i+1]-verticalCuts[i];
        if(w-verticalCuts[i]>maxv)
            maxv=w-verticalCuts[i];
        long long mod=(1e+9)+7;
        return ((maxh%mod)*(maxv%mod))%mod;
    }
};