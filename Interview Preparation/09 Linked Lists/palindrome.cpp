/*
    Given a singly linked list, determine if it is a palindrome.

    Example 1:

    Input: 1->2
    Output: false
    Example 2:

    Input: 1->2->2->1
    Output: true
    Follow up:
    Could you do it in O(n) time and O(1) space?
*/
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
    
    ListNode* reverse(ListNode *head) {
        ListNode *P = NULL;
        ListNode *C = head;
        ListNode *N;
        
        while(C != NULL) {
            N = C->next;
            C->next = P;
            P = C;
            C = N;
        }
        return P;
    }
    
    bool isPalindrome(ListNode* head) {
        ListNode *slow = head, *fast = head;
        
        while(fast and fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        
        fast = head;
        slow = reverse(slow);
        
        while(slow) {
            if(fast->val != slow->val)
                return false;
            
            fast = fast->next;
            slow = slow->next;
        }
        return true;
    }
};