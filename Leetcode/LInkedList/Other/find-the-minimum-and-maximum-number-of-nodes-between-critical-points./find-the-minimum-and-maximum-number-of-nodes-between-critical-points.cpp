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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        ListNode* prev = head;
        ListNode* curr = head->next;
        int i = 1;
        int previdx = 0;
        int first = 0;
        int mini = INT_MAX;

        while (curr->next != NULL) {
            if (curr->val < prev->val && curr->val < curr->next->val ||
                curr->val > prev->val && curr->val > curr->next->val) {
                    if(previdx == 0){
                        previdx = i;
                        first = i;
                    }else{
                        mini = min(mini,i-previdx);
                        previdx = i;
                    }
            }
            i++;
            prev = curr;
            curr = curr->next;
        }
        if(mini == INT_MAX) return {-1,-1};
        return {mini,previdx-first};
    }
};