class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue< int, vector<int>, greater<int> > q;
        int size = lists.size();
        for(int i=0; i<size; i++) {
            ListNode* p = lists[i];
            while(p) {
                q.push(p->val);
                p = p->next;
            }
        }
        size = q.size();
        ListNode* head = new ListNode(0);
        ListNode* p = head;
        while(size--) {
            p->next = new ListNode(q.top());
            q.pop();
            p = p->next;
        }
        return head->next;
    }
};
