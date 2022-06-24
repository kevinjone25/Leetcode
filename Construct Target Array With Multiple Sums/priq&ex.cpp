class Solution {
public:
    bool isPossible(vector<int>& target) {
        priority_queue<int>t;
        long long sum=0;
        for(auto n:target)
        {
            sum+=n;
            t.push(n);
        }
        while(t.top()!=1)
        {
            int maxn=t.top();//x
            t.pop();
            sum-=maxn;//現在的sum變為除x以外總和
            if(maxn==1)//最大元素為1時
                return true;
            if(sum==1)//[1,x]的情況
                return true;
            if(sum==0||sum>=maxn)//[x]或sum>=x
                return false;
            int r=maxn%sum;
            if(r==0)//[a,b,k*(a+b)]
                return false;
            t.push(r);
            sum+=r;
        }
        return true;
    }
};