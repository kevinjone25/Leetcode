class Solution {
private:
    bool canMake(int ni,int d,vector<int>&sticks,vector<int>&side){ 
        if(ni==sticks.size()) 
            return side[0]==side[1] && side[1]==side[2] && side[2]==side[3];
        for(int i=0;i<4;++i)
        {
            if(side[i]+sticks[ni]>d) 
                continue;  
            /*
            少了下面這段效能差很多
            個人理解是因為遞迴到最後若構不成邊
            就會把上一個邊的棍子取出來給下一個邊
            這時候如果判斷到有相同邊的情形
            代表上一個相同的邊加上棍子後因構不成邊所以把棍子給別人了
            這時如果繼續的話，又會重複多次這個無解的情況
            所以必須跳過
            */
            int j=i;
            while(--j>=0) 
                if(side[i]==side[j])
                    break;
            if(j!=-1)
                continue;
            
            side[i]+=sticks[ni];
            if(canMake(ni+1,d,sticks,side)) 
                return true;
            side[i]-=sticks[ni];
        }
        return false;
    }
public:
    bool makesquare(vector<int>& matchsticks) { 
        int sum=accumulate(matchsticks.begin(), matchsticks.end(),0);
        if(sum==0 || sum%4) 
            return false;
        sort(matchsticks.begin(),matchsticks.end(),greater<int>());
        vector<int>side(4,0);
        return canMake(0,sum/4,matchsticks,side);
    }
};