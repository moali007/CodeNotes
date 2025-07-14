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
    int getDecimalValue(ListNode* head) {
        string s = "";
        while(head != NULL){
            s += (head->val + '0');
            head = head->next;
        }

        reverse(s.begin(), s.end());
        int ans = 0;
        
        for(int i=0; i < s.length(); i++){
            int val = (s[i] - '0') * (1 << i);
            ans += val;
        }

        return ans;
    }
};