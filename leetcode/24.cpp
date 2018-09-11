class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(!head) return head;
        ListNode* d = new ListNode(0);
        d->next = head;
        ListNode* p1 = d;
        ListNode* p2 = p1->next;
        ListNode* p3 = p2->next;
        while(p3) {
            p1->next = p3;
            p2->next = p3->next;
            p3->next = p2;
            
            p1 = p2;
            if(!p1) break;
            p2 = p1->next;
            if(!p2) break;
            p3 = p2->next;
        }
        return d->next;
    }
};
