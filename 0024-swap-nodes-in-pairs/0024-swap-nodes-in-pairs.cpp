class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (head == NULL || head->next == NULL) return head;

        ListNode* dummy = new ListNode(-1);
        ListNode* prev = dummy;
        ListNode* curr = head;

        while (curr != NULL && curr->next != NULL) {
            ListNode* nxt = curr->next;
            ListNode* temp = nxt->next;

            // Swap
            prev->next = nxt;
            nxt->next = curr;

            // Move forward
            prev = curr;
            curr = temp;
        }

        // Attach last node if odd length
        if (curr != NULL) prev->next = curr;
        else prev->next = NULL;

        return dummy->next;
    }
};
