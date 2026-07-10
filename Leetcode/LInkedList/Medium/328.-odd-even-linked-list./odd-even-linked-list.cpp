*     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL) return NULL; 
        ListNode* Even = head->next;
        ListNode* Odd = head;
        ListNode* prev = head->next;

        while(Even != NULL && Even->next != NULL){
            Odd->next = Even->next;
            Even->next = Even->next->next;

        if(head->next == NULL) return head;