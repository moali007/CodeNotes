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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* prev = new ListNode(-1);
        ListNode* dummy = prev;
        ListNode* curr = head;

        while (curr != NULL) {
            int flag = 0;
            while(curr->next != NULL and curr->val == curr->next->val){
                flag = 1;
                curr = curr->next;
            }

            if(flag == 1){
               curr = curr->next; 
            }
            else{
                prev->next = new ListNode(curr->val);
                prev = prev->next;
                curr = curr->next;
            }
        }

        return dummy->next;
    }
};