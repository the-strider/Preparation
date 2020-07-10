class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head) {
            return NULL;
        }
        Node * temp = head;
        while(temp != NULL) {
            Node * next_temp = temp -> next;
            temp -> next = new Node(temp -> val);
            temp -> next -> next = next_temp;
            temp = next_temp;
        }
        
        Node * first = head;
        Node * second = head -> next;
        
        while(first and second) {
            if(first -> random) {
                second -> random = first -> random -> next;
            }
            second = second -> next ? second -> next -> next: second -> next;
            first = first -> next ? first -> next -> next: first -> next;
        }
        
        first = head;
        second = head -> next;

        Node * old_list = head;
        Node * new_list = head -> next;
        while(old_list and new_list) {
            old_list -> next = old_list -> next ? old_list -> next -> next : old_list -> next;
            new_list -> next = new_list -> next ? new_list -> next -> next : new_list -> next;
            
            old_list = old_list -> next;
            new_list = new_list -> next;
        }
        return second;
    }
};