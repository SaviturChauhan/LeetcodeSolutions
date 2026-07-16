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
    ListNode* reversell(ListNode * head){
        if(head == NULL || head->next == NULL) return head;
        ListNode* last = reversell(head->next);
        head->next->next = head;
        head->next = NULL;
        return last;
    }
    void reorderList(ListNode* head) {
        ListNode * slow = head;
        ListNode * fast = head;

        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode * rev = reversell(slow);
        ListNode * curr = head;

        while(rev->next != NULL){
            ListNode * temp = curr->next;
            ListNode * temprev = rev->next;

            curr->next = rev;
            rev->next = temp;

            curr = temp;
            rev = temprev;
        }
    }
};