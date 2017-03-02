/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
      if(head==NULL) return true;
      ListNode *slow = head;
      ListNode *fast = head;
      bool ended = false;
      while(!ended){
        if(slow->next==NULL){
          ended = true;
          //must break, if not, [1] will return true
          break;
        }
        else{
          slow = slow->next;
        }
        if(fast->next==NULL || fast->next->next==NULL){
          ended = true;
          //must break, if not, [1] will return true
          break;
        }
        else{
          fast = fast->next->next;
        }
        if(slow==fast){
          return true;
        }
      }
      return false;
    }
};
