class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        //將翻動令牌所需力量遞增排序
        //為了達到最大分數，從小的令牌獲取分數，力量不夠則從大的令牌那獲取
        sort(tokens.begin(),tokens.end());
        //因此前面的牌朝上，後面牌朝下
        int up=0,down = tokens.size(),n = down;
        while(up < down)
        {
            if(power >= tokens[up]) 
                power -= tokens[up++];
            else if(up - (n - down) && down > up + 1)
                power += tokens[--down];
            else
                break;
            //面朝上-面朝下就是分數(up - (n - down))
            //down > up + 1避免重複翻牌
        }
        return up - (n - down);
    }
};