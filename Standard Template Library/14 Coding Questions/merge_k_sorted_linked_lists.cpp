/*
    You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.

    Merge all the linked-lists into one sorted linked-list and return it.

    Example 1:

    Input: lists = [[1,4,5],[1,3,4],[2,6]]
    Output: [1,1,2,3,4,4,5,6]
    Explanation: The linked-lists are:
    [
    1->4->5,
    1->3->4,
    2->6
    ]
    merging them into one sorted list:
    1->1->2->3->4->4->5->6
    Example 2:

    Input: lists = []
    Output: []
    Example 3:

    Input: lists = [[]]
    Output: []
*/

/*
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Compare {
    public:
        bool operator()(ListNode *a, ListNode *b) {
            // minHeap implementation, larger elements will settle down
            return a->val > b->val; 
        }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode head;
        ListNode *curr = &head;
        
        priority_queue<ListNode*, vector<ListNode*>, Compare> minHeap;
        
        // insert the first 
        for(ListNode* list : lists) {
            if(list)
                minHeap.push(list);                
        }
        
        while(!minHeap.empty()) {
            ListNode *temp = minHeap.top();
            minHeap.pop();
            // move to the next element in the current list if present
            if(temp->next) 
                minHeap.push(temp->next);
            
            // add the popped out min node to the final list
            curr->next = temp;
            curr = temp;
        }
        return head.next; // pointer to the first node in the linked list
    }
};