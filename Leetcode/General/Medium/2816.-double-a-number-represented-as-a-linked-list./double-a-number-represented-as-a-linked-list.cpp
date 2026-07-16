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
    ListNode* doubleIt(ListNode* head) {
        stack<int> st;
        ListNode * curr = head;

        while(curr != NULL){
            st.push(curr->val);
            curr = curr->next;
        }

        stack<int> stk;

        int carry = 0;
        while(!st.empty()){
         int temp = st.top() * 2;
         st.pop();
         int val = temp % 10;
         stk.push(val+carry);
         carry = temp / 10;
        }
        if(carry != 0) stk.push(carry);
        ListNode * prev = new ListNode(stk.top());
        curr = prev;
        stk.pop();
        while(!stk.empty()){
            int temp = stk.top();
            stk.pop();
            ListNode * head = new ListNode(temp);
            curr->next = head;
            curr = head;
        }
        return prev;
    }
};