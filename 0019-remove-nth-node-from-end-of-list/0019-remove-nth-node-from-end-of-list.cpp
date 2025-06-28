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
        int size = 0;
        ListNode* temp = head;
        while(temp){
            size++;
            temp = temp->next;
        }

        int removeIdx = size - n;

        if(removeIdx == 0) return head->next;
        temp = head;

        for(int i = 0; i<removeIdx-1; i++){
            temp = temp->next;
        }

        temp->next = temp->next->next;

        return head;

    }
};