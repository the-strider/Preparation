class Solution {
public:
    int countTotalNode(ListNode * head) {
      int cnt = 0;
      ListNode * temp = head;
      while(temp) {
        temp = temp -> next;
        cnt ++;
      }
      return cnt;
    }

    bool check(ListNode* head1, ListNode * head2) {
      // check both list are equal assuming both have same size 
      ListNode * p1 = head1;
      ListNode * p2 = head2;
      while(p1 and p2) {
        if(p1 -> val != p2 -> val) {
          return false;
        }
        p1 = p1 -> next;
        p2 = p2 -> next;
      }
      return true;
    }

    bool isPalindrome(ListNode* head) {
      if(!head) {
        return true;
      }

      // Get total number of nodes
      int cnt = countTotalNode(head);

      // Reverse first half of the node (inplace)
      int i = 0;
      ListNode * first_half = NULL;
      while(i < cnt / 2) {
        ListNode * temp = head -> next;
        head -> next = first_half;
        first_half = head;
        head = temp;
        i ++;
      }

      // since the pointer of head has changed, store the pointer to restore list later
      ListNode * restore_list = head;

      // Special care if the total node is odd
      if(cnt & 1) head = head -> next;

      // check if first half is identical to second half
      bool flag = check(first_half, head);

      while(first_half) {
        ListNode * temp = first_half -> next;
        first_half -> next = restore_list;
        restore_list = first_half;
        first_half = temp;
      }
      return flag;
    }
};