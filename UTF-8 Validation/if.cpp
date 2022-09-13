class Solution {
public:
    bool validUtf8(vector<int>& data) {
        int remaining = 0;
        for (auto& x : data)
        {
            if(remaining == 0)//比對每種character的開頭
            {
                if((x >> 5) == 0b110)//2 Bytes
                    remaining = 1;
                else if((x >> 4) == 0b1110)//3 Bytes
                    remaining = 2;
                else if((x >> 3) == 0b11110)//4 Bytes
                    remaining = 3;
                else if((x >> 7) != 0)//1 Bytes
                    return false;
            } 
            else//2,3,4 Bytes後面
            {
                if((x >> 6) != 0b10)//(都是10開頭)
                    return false;
                else 
                    --remaining;
            }
        }
        return remaining == 0;
    }
};