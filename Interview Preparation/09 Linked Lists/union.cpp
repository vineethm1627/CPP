/*
    Given two linked lists, your task is to complete the function makeUnion(), that returns the union of two linked lists. This union should include all the distinct elements only.

    Example 1:

    Input:
    L1 = 9->6->4->2->3->8
    L2 = 1->2->8->6->2
    Output: 1 2 3 4 6 8 9
*/
struct Node* makeUnion(struct Node* head1, struct Node* head2) {
    set<int> s;
    
    Node * ptr = head1;
    while(ptr != NULL) {
        s.insert(ptr->data);
        ptr = ptr->next;
    }
    
    ptr = head2;
    while(ptr != NULL) {
        s.insert(ptr->data);
        ptr = ptr->next;
    }
    
    Node *start = NULL;
    Node *end = NULL;
    
    for(int x : s) {
        if(start == NULL) {
            start = end = new Node(x);
        }
        else {
            end->next = new Node(x);
            end = end->next;
        }
    }
    return start;
}