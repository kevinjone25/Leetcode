class MyCalendarThree {
public:
    MyCalendarThree() {
        
    }
    int book(int start, int end) {
        ++mp[start];
        --mp[end];
        int ans=0, cnt=0;
        //每次都掃過一次map，得出最大重疊次數
        for(auto x: mp)
        {
            cnt+=x.second;
            ans=max(ans, cnt);
        }
        return ans;
    }
private:
    map<int,int> mp;
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */