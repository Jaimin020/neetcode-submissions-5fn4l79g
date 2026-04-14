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
    ListNode* prev;
    int cou;
    int n;
    void reorder(ListNode* curr) {
        if(!curr) {
            return;
        }
        reorder(curr->next);
        if(cou>0) {
            cou--;
            ListNode* tem = prev->next;
            prev->next = curr;
            curr->next = tem;
            prev = tem;
        } 
        return;
    }
    void reorderList(ListNode* head) {
        n = 0;
        ListNode* tem = head;
        while(tem) {
            n++;
            tem = tem->next;
        }

        prev = head;
        cou = n/2;
        reorder(head);
        tem = head;
        for(int i=0;i<n-1;i++) {
            tem = tem->next;
        }
        tem->next = nullptr;
    }
};
