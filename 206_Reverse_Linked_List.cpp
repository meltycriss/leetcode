#include <iostream>
using namespace std;

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
    ListNode* reverseList(ListNode* head) {
      ListNode* prev = NULL;
      ListNode* curr = head;
      while(curr){
        ListNode* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
      }
      return prev;
    }
    ListNode* reverseListRecur(ListNode* curr, ListNode* prev){
      if(curr == NULL) return prev;
      else{
        ListNode* next = curr->next;
        curr->next = prev;
        return reverseListRecur(next, curr);
      }
    }
};
