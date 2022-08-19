class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int,int>left;//key:數 ,val:還沒加進數列的數量
        unordered_map<int,int>seq;//key:以該數為結尾的數列, val:數量
        for(auto x: nums)
            ++left[x];

        for(auto x: nums)
        {
            if(left[x]==0)//x都加進數列了，直接跳過 
                continue;
			
            if(seq[x-1]>0)//以x-1結尾的數列存在
            {                
                --left[x];//減少x未加進數列數量
                seq[x-1]-=1;//刪除以x-1為結尾的數列
                seq[x]+=1;//新增以x為結尾的數列                
            }
            else//若x前面沒有數列，則試著新增一個長度為3(最低限)的數列
            {
                if(left[x+1]==0 || left[x+2]==0)//無法形成長度為3的數列
                    return false;
                left[x]--;
                left[x+1]--;
                left[x+2]--;
                seq[x+2]+=1;//新增以x+2為結尾的數列
            }
        }
        return true;        
    }
};