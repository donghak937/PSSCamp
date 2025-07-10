class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* new_head = head;
        ListNode* prev = nullptr;

        while(new_head != nullptr){
             ListNode* temp = new_head->next;
             new_head->next = prev;
             prev = new_head;
             new_head = temp;
        }
        return prev;
    }
};