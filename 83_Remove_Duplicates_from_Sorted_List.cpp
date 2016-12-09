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
    ListNode* deleteDuplicates(ListNode* head) {
      if(head==NULL) return head;
      ListNode* curr = head;
      ListNode* next = head->next;
      while(next){
        if(curr->val==next->val){
          ListNode *tmp = next;
          curr->next = next->next;
          next = next->next;
          delete tmp;
        }
        else{
          curr = curr->next;
          next = next->next;
        }
      }
      return head;
    }
};
