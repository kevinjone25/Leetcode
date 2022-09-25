class MyCircularQueue {
public:
    MyCircularQueue(int k) :q(k),arrsize(k){}
    //循環佇列是用陣列實作queue時更有效率使用記憶體的做法
    //在pop掉元素後前面閒置的記憶體會被重複利用
    bool enQueue(int value) {
        if(isFull()) 
            return false;
        //利用mod來計算循環的index
        q[(front + size++) % arrsize] = value;
        return true;
    }
    bool deQueue() {
        if(isEmpty())
            return false;
        front = (front + 1) % arrsize;
        --size;
        return true;
    }
    int Front() {
        if(isEmpty()) 
            return -1;
        return q[front];
    }
    int Rear() {
        if(isEmpty())
            return -1;
        return q[(front + size - 1) % arrsize];
    }
    bool isEmpty() {
        return !size;
    }
    bool isFull() {
        return size == arrsize;
    }
private:
    vector<int>q;
    int front=0,size=0,arrsize;
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */