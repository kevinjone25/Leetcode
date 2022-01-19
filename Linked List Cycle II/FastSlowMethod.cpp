/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;
        /** head 到 cycle begin(node) 的距離為 a
cycle begin(node) 到 x 的距離為 b
x 到 cycle begin(node) 的距離為 c
在找到 x 時

oneStep 走了 a + b 的距離
twoStep 走了 a + b + c + b = a + 2b + c 的距離
twoStep 是 oneStep 的兩倍速度，所以可以推論
=> 2 ( a + b ) = a + 2b + c
=> 2a + 2b = a + 2b +c
=> 2a = a + c
=> a = c */
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast){
                slow = head;
                while(slow != fast){
                    slow = slow->next;
                    fast = fast->next;
                }
                return slow;
            }
        }
        return NULL;
    }
};