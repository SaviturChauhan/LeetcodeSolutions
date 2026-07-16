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
    ListNode* mergeNodes(ListNode* head) {
        stack<int> st;
        ListNode * curr = head;
        while(curr != NULL){
            st.push(curr->val);
            curr = curr->next;
        }

        st.pop();
        ListNode * begin = new ListNode(101);
        ListNode * prev = begin;

        while(!st.empty()){
            int curr = 0;
            while(st.top() != 0){
                curr += st.top();
                st.pop();
            }
            if(st.top() == 0) st.pop();
            ListNode* temp = new ListNode(curr);
            prev->next = temp;
            prev = temp;
        }
        return reversell(begin->next);
    }
};