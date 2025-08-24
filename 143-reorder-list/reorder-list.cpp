class Solution {
public:
    void reorderList(ListNode* head) {
        if (!head || !head->next) return;

        // Push all nodes into stack
        stack<ListNode*> s;
        ListNode* curr = head;
        while (curr != nullptr) {
            s.push(curr);
            curr = curr->next;
        }

        int n = s.size();
        curr = head;

        for (int i = 0; i < n / 2; i++) {
            // take last node
            ListNode* tail = s.top(); 
            s.pop();

            // save the next node in sequence
            ListNode* next = curr->next;

            // re-link
            curr->next = tail;
            tail->next = next;

            // move forward
            curr = next;
        }

        // terminate list to avoid cycle
        curr->next = nullptr;
    }
};
