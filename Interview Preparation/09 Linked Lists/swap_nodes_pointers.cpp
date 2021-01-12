// swap the nodes with values x and y in the linked list
// swap the nodes in the list without swapping values
void swapNodes(Node *head, int x, int y) {
    if(x == y) 
        return;
    
    Node *prevX = NULL, *currX = head;
    while(currX and currX->data != x) {
        prevX = currX;
        currX = currX->next;
    }

    Node *prevY = NULL, *currY = head;
    while(currY and currY->data != y) {
        prevY = currY;
        currY = currY->next;
    }

    if(currX == NULL or currY == NULL)
        return;
    
    // swap the nodes
    if(prevX != NULL)
        prevX->next = currY;
    else
        head = currY;
    
    if(prevY != NULL)
        prevY->next = currX;
    else
        head = currX;
    
    // swap the next pointers
    Node *temp = currX->next;
    currX->next = currY->next;
    currY->next = temp;
}