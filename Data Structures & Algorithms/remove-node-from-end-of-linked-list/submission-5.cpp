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
        ListNode* nl = new ListNode();
        nl->val = -1;
        nl->next = head;
        ListNode* p1 = nl;
        ListNode* p2 = nl->next;

        for(int i=0;i<n-1;i++) {
            p2 = p2->next;
        }

        while(p2->next) {
            p1 = p1->next;
            p2 = p2->next;
        }
        p1->next = p1->next->next;
        if(p1->val==-1) head = p1->next;
        return head;
    }
};
