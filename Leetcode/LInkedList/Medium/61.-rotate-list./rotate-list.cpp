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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || head->next == NULL || k == 0) return head;
        ListNode* tail = head;
        int l = 1;
        while (tail->next != NULL) {
            tail = tail->next;
            l++;
        }
        k = k % l;
        if(k == 0) return head;

        tail->next = head;

        ListNode* temp = head;

        for(int count = 1;count<l-k;count++){
           temp = temp->next;
        }
        ListNode * newhead = temp->next;
        temp->next = NULL;
        return newhead;
    }
};