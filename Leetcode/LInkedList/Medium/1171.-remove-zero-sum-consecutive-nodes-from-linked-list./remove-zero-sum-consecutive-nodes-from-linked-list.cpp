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
    ListNode* removeZeroSumSublists(ListNode* head) {
        int sum = 0;
        unordered_map<int, ListNode*> mp;
        ListNode* prev = new ListNode(0, head);
        mp[0] = prev;

        while (head != NULL) {
            sum += head->val;
            if (mp.find(sum) != mp.end()) {
                // delete work
                ListNode* start = mp[sum];
                ListNode* temp = start;
                int psum = sum;

                while(temp != head){
                    temp = temp->next;
                    psum += temp->val;
                    if(temp != head){
                        mp.erase(psum);
                    }
                }
                start->next = head->next;
            } else {
                mp[sum] = head;
            }
            head = head->next;
        }

        return prev->next;
    }
};