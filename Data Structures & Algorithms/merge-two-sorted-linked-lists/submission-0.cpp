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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* p1 = list1;
        ListNode* p2 = list2;
        ListNode* ans = new ListNode();
        ListNode* head = ans;
        while(p1 && p2) {
            if(p1->val > p2->val) {
                ListNode* x = new ListNode(p2->val);
                ans->next = x;
                ans = ans->next;
                p2 = p2->next;
            } else {
                ListNode* x = new ListNode(p1->val);
                ans->next = x;
                ans = ans->next;
                p1 = p1->next;
            }
        }

        while(p1) {
            ListNode* x = new ListNode(p1->val);
            ans->next = x;
            ans = ans->next;
            p1 = p1->next;
        }

        while(p2) {
            ListNode* x = new ListNode(p2->val);
            ans->next = x;
            ans = ans->next;
            p2 = p2->next;
        }

        return head->next;
    }
};
