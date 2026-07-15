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
    bool isPalindrome(ListNode* head) {
        ListNode * temp = head;
        int n = 0;
        vector<int> vec;
        while(temp != NULL){
            n++;
            vec.push_back(temp->val);
            temp = temp->next;
        }
        int i = 0;
        int j = n-1;
        while( i <= j){
            if(vec[i] == vec[j]){
                i++;
                j--;
            }
            else return false;
        }
        return true;
    }
};