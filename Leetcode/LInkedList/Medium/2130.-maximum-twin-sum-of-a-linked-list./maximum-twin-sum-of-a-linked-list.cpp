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
    int pairSum(ListNode* head) {
        int n = 0;
        ListNode* temp = head;
        ListNode* trav = head;
        while (temp != NULL) {
            n++;
            temp = temp->next;
        }

        if (n % 2 != 0)
            return 0;

        vector<int> sum(n / 2, 0);
        int i = 0;
        int maxi = -1e9;
        while (trav != NULL ) {
            if (i < n / 2)
                sum[i] += trav->val;
            else
                sum[n-1-i] += trav->val;
            i++;
            trav = trav->next;
        }
        for(int i = 0;i<sum.size();i++) {
            maxi = max(sum[i],maxi);
            }
        return maxi;
    }
};