#include <vector>
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
      int lenA = lengthOfList(headA);
      int lenB = lengthOfList(headB);
      ListNode *ptA = headA;
      ListNode *ptB = headB;
      if(lenA > lenB){
        for(int i=0; i<lenA-lenB; ++i){
          ptA = ptA->next;
        }
      }
      else{
        for(int i=0; i<lenB-lenA; ++i){
          ptB = ptB->next;
        }
      }
      while(ptA!=NULL && ptA!=ptB){
        ptA = ptA->next;
        ptB = ptB->next;
      }
      return ptA;
    }
    int lengthOfList(ListNode *head){
      int res = 0;
      while(head!=NULL){
        ++res;
        head = head->next;
      }
      return res;
    }
};

int main(){
  ListNode *a1 = new ListNode(1);
  ListNode *a2 = new ListNode(2);
  ListNode *b1 = new ListNode(11);
  ListNode *b2 = new ListNode(12);
  ListNode *b3 = new ListNode(13);
  ListNode *c1 = new ListNode(21);
  ListNode *c2 = new ListNode(22);
  ListNode *c3 = new ListNode(23);
  a1->next = a2;
  a2->next = c1;
  b1->next = b2;
  b2->next = b3;
//  b3->next = c1;
  c1->next = c2;
  c2->next = c3;
  cout << Solution().getIntersectionNode(a1, b1)->val << endl;
  return 0;
  
}
