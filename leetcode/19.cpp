class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* p1 = head;
        ListNode* p2 = head;
        while(n--) p2 = p2->next;
        while(p2 && p2->next) {
            p1=p1->next;
            p2=p2->next;
        }
        if(p2) {
            p1->next = p1->next->next;
        } else {
            head = head->next;
        }
        return head;
    }
};
