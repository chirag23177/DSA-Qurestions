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
    bool isPalindrome(ListNode* head) {
        stack<int> st;
        ListNode* temp = head;
        while (temp != nullptr) {
            st.push(temp->val);
            temp = temp->next;
        }

        temp = head;

        if (st.empty())
            return true;

        while (!st.empty()) {
            if (temp->val != st.top()) {
                return false;
            }
            temp = temp->next;
            st.pop();
        }
       return true;
    }
};