/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* temp;
    
    bool check(ListNode* head) {
        if(NULL == head)
            return true;
        //head是迴文的後面，temp是前面
        bool res = check(head->next) & (temp->val == head->val);
        temp = temp->next;
        return res;
    }
    
    bool isPalindrome(ListNode* head) {
        temp = head;
        return check(head);
    }
};