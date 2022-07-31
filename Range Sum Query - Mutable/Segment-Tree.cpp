class NumArray {
public:
    vector<int> seg;
    int n;
    //建立線段樹
    void buildTree(vector<int>& nums, int pos, int left, int right){
        if(left == right)
        {
            seg[pos] = nums[left]; 
            return;
        }
        //利用遞迴從下往上建立線段樹
        int mid = (left+right)/2;
        buildTree(nums, 2*pos+1, left, mid);
        buildTree(nums, 2*pos+2, mid+1, right);
        seg[pos]=seg[2*pos+1]+ seg[2*pos+2];
    }
    //單點修改
    void updateUtil(int pos, int left, int right, int index, int val) {
        //若是不被影響的的區間就直接返回
        if(index <left || index >right)
            return;
        //欲修改的點
        if(left==right)
        {
            if(left==index)
                seg[pos]=val;
            return;
        }

        //單點修改也會修改區間
        //跟建立線段樹時一樣，用遞迴修改
        int mid=(left+right)/2;
        updateUtil(2*pos+1,left,mid,index,val);
        updateUtil(2*pos+2,mid+1,right,index,val);
        seg[pos]=seg[2*pos+1]+seg[2*pos+2];
    }

    int rangeUtil(int qlow, int qhigh, int low, int high, int pos){
        if (qlow <= low && qhigh>= high)//節點被查詢區間包圍就直接回傳
            return seg[pos];
        if (qlow > high || qhigh < low)
            return 0;
        int mid = low+(high-low)/2;
        return (rangeUtil(qlow, qhigh, low, mid, 2*pos+1) + rangeUtil(qlow, qhigh, mid+1, high, 2*pos+2));
    }
    
    //初始化
    NumArray(vector<int>& nums) {
        if(nums.size() > 0)
        {
            n = nums.size();
            seg.resize(4*n,0);
            buildTree(nums, 0, 0, n-1);
        }
    }
    
    //呼叫單點修改
    void update(int index, int val) {
        if(n==0)return;
        updateUtil(0,0,n-1, index, val);
    }
    //呼叫求區間和
    int sumRange(int left, int right) {
        if(n==0)
            return 0;
        return rangeUtil(left, right, 0, n-1, 0); 
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */