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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        
        ListNode* curr = head;
        ListNode* prev = new ListNode(-1);  // Dummy node
        ListNode* temp = prev;
        prev -> next = head;
        unordered_map<int, bool> mp;

        // Populate the map with values from nums
        for (auto i : nums) {
            mp[i] = true;
        }

        while (curr != nullptr) {
            if (mp[curr->val]) {
                // Skip the current node by updating the `next` of `prev`
                prev->next = curr->next;
            } else {
                // Move the prev pointer forward if current node is kept
                prev = curr;
            }
            // Move to the next node
            curr = curr->next;
        }
        
        return temp->next;  // Return the modified list starting from head
    }
};
