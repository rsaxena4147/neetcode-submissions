/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
   public:
    ListNode* rev(ListNode* node){
        ListNode* curr = node , *prev = NULL , *frd = NULL;

        while(curr != NULL){
            frd = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = frd;
        }
        return prev;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
       
       head = rev(head);

        ListNode* temp = head;
        if(n == 1){
            temp = temp ->next;
            
            return rev(temp);
        }

        while(n > 2){
            temp = temp -> next;
            n--;
        }

        temp -> next = temp -> next -> next;
        
        return rev(head);

    }
};
