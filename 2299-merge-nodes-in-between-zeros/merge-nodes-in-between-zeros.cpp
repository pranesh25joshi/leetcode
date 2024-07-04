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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* dummy = new ListNode(0);  // Dummy node to handle the result list
        ListNode* curr = dummy;  // Pointer to construct the result list
        ListNode* ptr = head->next;  // Pointer to traverse the input list
        
        int sum = 0;  // Sum between zeros
        
        while (ptr != nullptr) {
            if (ptr->val == 0) {
                // If we hit a zero, we complete the current segment
                curr->next = new ListNode(sum);  // Create a new node with the sum
                curr = curr->next;  // Move to the next node in the result list
                sum = 0;  // Reset the sum for the next segment
            } else {
                sum += ptr->val;  // Accumulate values between zeros
            }
            ptr = ptr->next;  // Move to the next node in the input list
        }
        
        return dummy->next;  // Return the result list, skipping the dummy node
    }
};
