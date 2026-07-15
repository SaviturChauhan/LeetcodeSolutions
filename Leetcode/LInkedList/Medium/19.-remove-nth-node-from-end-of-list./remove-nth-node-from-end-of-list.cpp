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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp = head;
        int l = 0;
        while (temp != NULL) {
            l++;
            temp = temp->next;
        }
        if(n == l) return head->next;
        int idx = l - n;
        temp = head;
        ListNode* prev = NULL;
        int i = 0;
        while (temp != NULL) {
            if (i == idx) {
                prev->next = temp->next;
                delete(temp);
                break;
            }
            prev = temp;
            temp = temp->next;
            i++;
        }
        return head;
    }
};