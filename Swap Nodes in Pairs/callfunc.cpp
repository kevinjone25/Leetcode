class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        //遞迴並從尾端修改至前端
        if(!head)
            return nullptr;
        if(!head->next)
            return head;
        ListNode* nt=head->next;
        head->next=swapPairs(nt->next);
        nt->next=head;
        return nt;
    }
};