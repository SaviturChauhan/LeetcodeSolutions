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
    ListNode* partition(ListNode* head, int x) {
        ListNode* lo = new ListNode(100);
        ListNode* hi = new ListNode(101);
        ListNode* tlo = lo;
        ListNode* thi = hi;
        ListNode* temp = head;
        while(temp!=NULL){
            if(temp->val < x){
                tlo->next = temp;
                temp = temp->next;
                tlo = tlo->next;
            }
            else{
                thi->next = temp;
                temp = temp->next;
                thi = thi->next;
            }
        }  
        tlo->next = hi->next;
        thi->next = NULL;
        return lo->next;      
    }
};