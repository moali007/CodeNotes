class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;

        while(curr != NULL){
            ListNode* front = curr->next;
            curr->next = prev;
            prev = curr;
            curr = front;
        }

        return prev;
    }

    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(head == NULL || head->next == NULL) return head;

        ListNode* dummy = new ListNode(-1);
        dummy->next = head;

        ListNode* leftPart = head;
        for(int i = 1; i < left; i++) {
            leftPart = leftPart->next;
        }

        ListNode* l = leftPart->next;
        ListNode* r = l;
        for(int i = left; i < right; i++) {
            r = r->next;
        }

        ListNode* rightPart = r->next;
        r->next = NULL;

        ListNode* reversedHead = reverseList(l);
        leftPart->next = reversedHead;
        l->next = rightPart;

        return head;
    }
};
