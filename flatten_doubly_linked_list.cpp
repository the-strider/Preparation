/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    void merge(Node * h1, Node * h2) {
        Node * temp = h1 -> next;
        h1 -> child = NULL;
        while(h2) {
            h1 -> next = h2;
            h2 -> prev = h1;
            h2 = h2 -> next;
            h1 = h1 -> next;
        }

        h1 -> next = temp;
        if(temp) {
            temp -> prev = h1;
        }
    }

    Node* flatten(Node* head) {
        if(!head) {
            return NULL;
        }
        if(head -> child) {
            merge(head, flatten(head -> child));
        }
        head -> next = flatten(head -> next);
        return head;
    }
};