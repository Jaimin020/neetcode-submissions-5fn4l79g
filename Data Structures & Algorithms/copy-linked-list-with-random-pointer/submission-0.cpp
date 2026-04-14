/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, int> org;
        unordered_map<int, Node*> nList;
        Node* tem = head;
        int cou = 0;

        Node* nl = new Node(-1);
        Node* temNl = nl;
        while(tem) {
            org[tem] = cou;

            temNl->next = new Node(tem->val);
            temNl = temNl->next;
            
            nList[cou] = temNl;
            tem = tem->next;
            cou++;
        }

        tem = head;
        temNl = nl->next;

        while(tem) {
            if(tem->random) {
                temNl->random = nList[org[tem->random]];
            }
            tem = tem->next;
            temNl = temNl->next;
        }

        return nl->next;

    }
};
