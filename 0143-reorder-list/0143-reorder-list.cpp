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

    ListNode* reverseList(ListNode* head){
        ListNode* prev = nullptr;
        while(head){
            ListNode* temp = head->next;
            head->next = prev;
            prev = head;
            head = temp;
        }

        return prev;

    }
    void reorderList(ListNode* head) {
        if(!head || !head->next || !head->next->next) return;
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast->next && fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* l2 = reverseList(slow->next);
        slow->next = nullptr; 
        ListNode* l1 = head;

        while(l1 && l2){
            ListNode* l1_next = l1->next;
            ListNode* l2_next = l2->next;

            l1->next = l2;
            l2->next = l1_next;

            l1 = l1_next;
            l2 = l2_next;
        }
    }
};