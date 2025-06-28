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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head || (!head->next && n==1)) return nullptr;
        
        ListNode* dummy = new ListNode(0);
        ListNode* h1, *h2;

        dummy->next = head;
        h1 = dummy;
        h2 = dummy;

        for(int i = 0; i<=n; i++){
            h2 = h2->next;
        }

        while(h2){
            h2 = h2->next;
            h1 = h1->next;
        }

        h1->next = h1->next->next;

        return dummy->next;
    }
};