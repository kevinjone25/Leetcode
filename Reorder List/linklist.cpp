class Solution {
public:
    void reorderList(ListNode* head) {
        if(!head||!head->next||!head->next->next)//至少要有3個點才能插入
            return;
        ListNode* secondlast=head;
        while(secondlast->next->next)//找倒數第二個點
            secondlast=secondlast->next;
        
        //移動並連接最後一個點
        secondlast->next->next=head->next;
        head->next=secondlast->next;
        
        secondlast->next=nullptr;//更新尾端
        reorderList(head->next->next);//往下繼續
    }
};