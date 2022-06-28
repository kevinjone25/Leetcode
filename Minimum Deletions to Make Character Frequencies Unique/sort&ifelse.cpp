class Solution {
public:
    int minDeletions(string s) {
        vector<int>c(26);
        int mind=0;
        for(auto i:s)
            ++c[i-'a'];
        sort(c.begin(),c.end());
        //sort過後當成遞增的長條圖來看
        //同樣數量按順序經過刪除後會變為差為1的嚴格遞增區塊
        //因此前面的數若大於後面經過刪除的數
        //必須刪除到比後面的數小為止
        for(int i=24;i>=0;--i)
        {
            if(c[i]==c[i+1]&&c[i]>0)
            {
                --c[i];
                ++mind;
            }
            else if(c[i]>c[i+1])
            {
                if(c[i+1]>0)
                {
                    mind+=(c[i]-c[i+1]+1);
                    c[i]=c[i+1]-1;
                }
                else
                {
                    mind+=c[i];
                    c[i]=0;
                }
            }      
        }
        return mind;
    }
};