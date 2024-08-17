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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // int tens = 1;
        int carry = 0;
        ListNode* node = new ListNode(-1);
        ListNode* s = node;
        while( l1  != nullptr && l2  != nullptr){
            int p = l1->val + l2->val + carry;
            ListNode* m = new ListNode(p % 10);
            node -> next = m;
            node = m;
            carry = p / 10;
            l1 = l1 -> next;
            l2 = l2 -> next;
        }

        ListNode* o = (l1 != nullptr) ? l1 : l2;
        while( o != nullptr){
            int p = o->val + carry;
            ListNode* m = new ListNode(p % 10);
            node -> next = m;
            node = m;
            carry = p / 10;
            o = o -> next;
        }
        if( carry != 0){
            ListNode* c = new ListNode(carry);
            node -> next = c;
        }
        return s -> next;
    }
};