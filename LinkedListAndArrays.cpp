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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head) return nullptr;
        if(!k) return head;
        ListNode* temp = head;
        int length = 1;
        while (temp->next) {
            temp = temp->next;
            length++;
        }

        temp->next = head;
        temp = head;
        k = k % length;

        for (int i = 0; i < length - k - 1; i++) {
            temp = temp->next;
        }

        ListNode* newHead = temp->next;
        temp->next = nullptr;
        
        return newHead;
    }
};
