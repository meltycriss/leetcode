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
    ListNode* removeElements(ListNode* head, int val) {
      removeElementsAux(&head, val);
      return head;

    }
    void removeElementsAux(ListNode** head, int val){
      ListNode* curr = *head;
      if(curr==NULL){
        return;
      }
      ListNode* next = curr->next;
      if(curr->val == val){
        delete curr;
        *head = next;
        removeElementsAux(head, val);
      }
      else{
        removeElementsAux(&curr->next, val);
      }
    }
};
