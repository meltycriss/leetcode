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
    bool isPalindrome(ListNode* head) {
      if(head==NULL || head->next==NULL){
        return true;
      }
      ListNode* slow = head;
      ListNode* fast = head;
      // * * x * *
      // * x * *
      while(fast->next!=NULL && fast->next->next!=NULL){
        slow = slow->next;
        fast = fast->next->next;
      }
      slow->next = reversedList(slow->next);
      slow = slow->next;
      while(slow!=NULL){
        if(slow->val != head->val){
          return false;
        }
        slow=slow->next;
        head=head->next;
      }
      return true;
    }

    ListNode* reversedList(ListNode* head){
      ListNode* prev = NULL;
      ListNode* next = NULL;
      while(head!=NULL){
        next = head->next;
        head->next = prev;
        prev = head;
        head = next;
      }
      return prev;
    }
};
