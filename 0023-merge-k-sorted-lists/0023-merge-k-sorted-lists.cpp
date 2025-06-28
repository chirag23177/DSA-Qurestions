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
    // Helper function to merge two lists
    ListNode* mergeTwoList(ListNode* head1, ListNode* head2) {
        ListNode* dummy = new ListNode(0);
        ListNode* temp = dummy;

        while (head1 && head2) {
            if (head1->val <= head2->val) {
                temp->next = head1;
                head1 = head1->next;
            } else {
                temp->next = head2;
                head2 = head2->next;
            }
            temp = temp->next;
        }

        // Attach the remaining list
        if (head1) temp->next = head1;
        else temp->next = head2;

        return dummy->next;
    }

    // Main function to merge k lists
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) return nullptr;

        while (lists.size() > 1) {
            vector<ListNode*> merged;

            for (int i = 0; i < lists.size(); i += 2) {
                if (i + 1 < lists.size()) {
                    merged.push_back(mergeTwoList(lists[i], lists[i + 1]));
                } else {
                    merged.push_back(lists[i]);
                }
            }

            lists = merged;
        }

        return lists[0];
    }
};
