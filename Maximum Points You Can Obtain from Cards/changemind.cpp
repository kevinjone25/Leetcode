class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        /*
        從N張牌取走k張，最後會剩下N-k張牌
        由於都是從頭尾取，可以保證剩下N-k張牌必定是連續的子序列
        所以只要得出子序列的最小值就可以得出k張牌的最大值
        */
        int n=cardPoints.size()-k,nsum=0;
        //求出第一個子序列總和
        for(int i=0;i<n;++i)
            nsum+=cardPoints[i];
        int minsum=nsum,sum=nsum;
        for(int i=n;i<cardPoints.size();++i)
        {
            sum+=cardPoints[i];//計算sum
            //減掉頭加上尾就是下一個子序列
            nsum+=(cardPoints[i]-cardPoints[i-n]);
            if(nsum<minsum)//更新最小值
                minsum=nsum;
        }
        return sum-minsum;
    }
};