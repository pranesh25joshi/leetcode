class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode* dummy = new ListNode(0, head); // dummy -> head
    ListNode* fast = dummy;
    ListNode* slow = dummy;

    // Move fast ahead by n+1 steps
    for(int i = 0; i <= n; i++) {
        fast = fast->next;
    }

    // Move both until fast hits end
    while(fast != nullptr) {
        fast = fast->next;
        slow = slow->next;
    }

    // Delete the node
    slow->next = slow->next->next;

    return dummy->next; // return new head (in case old head was removed)
}

};
