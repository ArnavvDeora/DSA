class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        // Create a dummy node that points to head.
        // This simplifies deleting the head node itself.
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        
        ListNode* prev = dummy;
        ListNode* curr = head;
        
        while(curr != nullptr) {
            if(curr->val == val) {
                // Node found. Unlink it.
                prev->next = curr->next;
                
                // Delete the node from memory (C++ style)
                delete curr;
                
                // Move current forward, but KEEP prev where it is
                // because prev's new 'next' hasn't been checked yet.
                curr = prev->next;
            } else {
                // Node not found, move both pointers forward
                prev = curr;
                curr = curr->next;
            }
        }
        
        // Return the new head (skipping the dummy)
        ListNode* newHead = dummy->next;
        delete dummy; // Clean up the dummy node memory
        return newHead;
    }
};