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
    ListNode* reverse(ListNode* l) {
        ListNode* prev = nullptr;
        ListNode* curr = l;
        ListNode* next = l->next;

        while(curr) {
            curr->next = prev;
            prev = curr;
            curr = next;
            if(curr!=nullptr)
                next = curr->next;
        }

        return prev;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        //l1 = reverse(l1);
        //l2 = reverse(l2);
        ListNode* ans = new ListNode(-1);
        ListNode* tem = ans;
        int car = 0;

        while(l1 && l2) {
            int ans = l1->val + l2->val + car;
            if(ans>9) {
                car = 1;
            } else {
                car = 0;
            }
            tem->val = ans%10;
            tem->next = new ListNode(-1);
            tem = tem->next;

            l1 = l1->next;
            l2 = l2->next;
        }

        while(l1) {
            int ans = l1->val + car;
            if(ans>9) {
                car = 1;
            } else {
                car = 0;
            }
            tem->val = ans%10;
            tem->next = new ListNode(-1);
            tem = tem->next;

            l1 = l1->next;
        }

        while(l2) {
            int ans = l2->val + car;
            if(ans>9) {
                car = 1;
            } else {
                car = 0;
            }
            tem->val = ans%10;
            tem->next = new ListNode(-1);
            tem = tem->next;

            l2 = l2->next;
        }
        if(car==1) {
            tem->val = 1;
            tem->next = new ListNode(-1);
            tem = tem->next;
        }
        //ans = reverse(ans);
        tem = ans;
        while(tem->next->val!=-1) {
            tem = tem->next;
        }
        tem->next = nullptr;
        return ans;
    }
};
