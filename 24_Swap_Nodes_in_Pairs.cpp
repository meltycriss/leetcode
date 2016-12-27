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
//    ListNode* swapPairs(ListNode* head) {
//      if(head==NULL || head->next==NULL) return head;
//      ListNode* next = head->next;
//      ListNode* p = swapPairs(next->next);
//      head->next = p;
//      next->next = head;
//      return next;
//    }
//    ListNode* swapPairs(ListNode* head) {
//      ListNode* curr = head;
//      head = new ListNode(-1);
//      head->next = curr;
//      ListNode* prev = head;
//      while(curr!=NULL && curr->next!=NULL){
//        ListNode* next = curr->next;
//        ListNode* tail = next->next;
//        curr->next = tail;
//        next->next = curr;
//        prev->next = next;
//        curr=tail;
//        prev=next->next;
//      }
//      ListNode* res = head->next;
//      delete head;
//      return res;
//    }
    ListNode* swapPairs(ListNode* head) {
      ListNode **p = &head, *a, *b;
      while((a=*p) && (b=a->next)){
        a->next = b->next;
        b->next = a;
        *p = b;
        p = &(a->next);
      }
      return head;
    }
};
