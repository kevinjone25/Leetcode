class MyCalendar {
    map<int,int> mp;//<endTime, statIme>
public:  
    bool book(int start, int end) {
        auto itr = mp.upper_bound(start);//找第一個大於start的endTime
        //如果沒找到或區間不相交就加進日曆裡
        if(itr == mp.end() || end<= itr->second) 
        {
            mp[end]=start;
            return true;
        } 
        return false;
    }
};
/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */