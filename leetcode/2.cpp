class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* p1 = l1;
        ListNode* p2 = l2;
        ListNode* ret = new ListNode(0);
        ListNode* pSum = ret;
        while(p1 && p2) {
            pSum->val = p1->val + p2->val;
            p1 = p1->next;
            p2 = p2->next;
            if(p1 && p2) {
                pSum->next = new ListNode(0);
                pSum = pSum->next;
            }
        }
        if( !p1 ) {
            p1 = p2;
        }
        pSum->next = p1;
        pSum = ret;
        while(pSum) {
            if(pSum->val >= 10) {
                if(pSum->next) {
                    pSum->next->val += pSum->val/10;
                } else {
                    pSum->next = new ListNode(pSum->val/10);
                }
                pSum->val =  pSum->val % 10;
            }
            pSum = pSum->next;
        }
        return ret;
    }
};
