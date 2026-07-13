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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        ListNode* temp = head;
        int n = 0;
        while(temp != NULL){
            n++;
            temp = temp->next;
        }

        int each = n/k;
        int rem = n%k;

        vector<ListNode*> ans(k,NULL);
        ListNode* curr = head;
        ListNode* prev = NULL;

        for(int i =0;i<k;i++){
            ans[i] = curr;
            for(int count = 1;count<=each + (rem > 0 ? 1 : 0);count++){
                prev = curr;
                curr = curr->next;
            }
            if(prev != NULL)
            prev->next = NULL;
            rem--;
        }

    return ans;
    }
};