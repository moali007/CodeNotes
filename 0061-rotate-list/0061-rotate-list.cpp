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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || head->next == NULL || k == 0) return head;

        //step 1: find length
        int n = 1;
        ListNode* tail = head;
        
        while(tail->next != NULL){
            tail = tail->next;
            n++;
        }

        //step 2: make circular
        tail->next = head;

        k = k % n;

        //step 3: find new tail
        ListNode* newTail = head;

        for(int i = 1; i < n-k; i++){
            newTail = newTail->next;
        }
        
        //break circular
        ListNode* newHead = newTail->next;
        newTail->next = NULL;

        return newHead;

    }
};