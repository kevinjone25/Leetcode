class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        int mid=1,i=0;
        ListNode* tail=head;
        while(tail->next)//找到尾巴
        {
            tail=tail->next;
            ++mid;
        }
        mid/=2;//得到中間索引
        while(i!=mid)//得到中間點
        {
            head=head->next;
            ++i;
        }
        return head;
    }
};