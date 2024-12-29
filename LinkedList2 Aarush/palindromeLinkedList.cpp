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
        ListNode* slow=head, *fast=head;

        while(fast!=nullptr && fast->next!=nullptr) {
            slow=slow->next;
            fast=fast->next->next;
        }
        
        ListNode* prev=nullptr, *curr=slow;

        while(curr) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        ListNode* firstHalf=head;
        ListNode* secondHalf=prev;

        while(secondHalf) {
            if (firstHalf->val != secondHalf->val) {
                return false;  // If there's a mismatch, it's not a palindrome
            }
            firstHalf = firstHalf->next;
            secondHalf = secondHalf->next;
         }
        
        return true;
    }
};
