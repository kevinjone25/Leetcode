class Solution {
public:
    bool hasCycle(ListNode *head) {
        /*
        設兩個pointer，slow和fast
        slow走一步，fast走兩步
        如果有循環則遲早會相遇
        沒有就會到尾
        */
        if(head == NULL)
            return false;
        ListNode *fast=head,*slow=head;
        while(fast != NULL && fast ->next != NULL)
        {
            fast = fast->next->next;
            slow = slow->next;
            if(fast == slow)
                return true;
        }
        return false;
    }
};