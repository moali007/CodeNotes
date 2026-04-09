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

    int getLength(ListNode* head) {
        int len = 0;
        ListNode* temp = head;
        while(temp != NULL) {
            temp = temp -> next; 
            len++;
        }
        return len;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==NULL){
            return 0;
        }
        int len = getLength(head);
        if(k > len) {
            //cout << "Enter valid value for k " << endl;
            return head;
        }

        ListNode* prev=NULL;
        ListNode* curr=head;
        // ListNode* forward=curr->next;
        int count=0;

        while(count < k){
            ListNode* forward=curr->next;
            curr->next=prev;
            prev=curr;
            curr=forward;
            count++;
        }

        if(curr != NULL){
            head->next=reverseKGroup(curr,k);
        }
        
        return prev;
    }
};