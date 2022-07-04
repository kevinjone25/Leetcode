class Solution {
public:
    int candy(vector<int>& ratings) {
        int l=ratings.size(),candy=l,i=1;
        while(i<l)
        {
            if(ratings[i]==ratings[i-1])
            {
                ++i;
                continue;
            }
            
            int up=0;
            while(i<l && ratings[i-1]<ratings[i])//升序
            {
                candy+=++up;
                ++i;
            }
      
            int dw=0;
            while(i<l && ratings[i-1]>ratings[i])//降序
            {
                candy+=++dw;
                ++i;
            }
                
            candy-=min(up,dw);
        }
        return candy;
    }
};