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
        if(!head) return nullptr;
        Node* curr=head;
        while(curr) {
            Node* newNode = new Node(curr->val);
            newNode->next = curr->next;
            curr->next=newNode;
            curr=newNode->next;
        }
        curr=head;
        while(curr) {
            if(curr->random) {
                curr->next->random = curr->random->next;
            }
            curr=curr->next->next;
        }
        Node* newHead=head->next;
        Node* original=head;
        Node* copy=newHead;

        while(original) {
            original->next=original->next?original->next->next:nullptr;
            copy->next=copy->next?copy->next->next:nullptr;
            original = original->next;
            copy=copy->next;
        }

        return newHead;
    }
};
