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
    pair<ListNode*,ListNode*> rev(ListNode* head , int k){
        ListNode* curr = head , *prev = NULL, *frd = NULL;
        int cnt = 0;
        ListNode* temp = head;
        while(temp != NULL){
            cnt++;
            temp = temp -> next;
        }
        if(cnt < k)return {head , NULL};

        while(curr != NULL && k--){
            frd = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = frd;
        }
        return {prev , frd};
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        
        ListNode* ans = new ListNode(0);
        ListNode* dummy = ans;

        ListNode* temp = head;

        while(temp != NULL){

            pair<ListNode* , ListNode* > p = rev(temp, k);
            ans -> next = p.first;
            while(ans -> next != NULL)ans = ans -> next;
            temp = p.second;
        }
        return dummy -> next;
    }
};
