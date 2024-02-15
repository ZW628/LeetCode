#include <iostream>

#include "ListNode.h"
using namespace std;

// 删除链表的倒数第N个节点
class Solution {
public:
    ListNode* removeNthFromeEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* x = findFromEnd(dummy, n + 1);
        x->next = x->next->next;
        return dummy->next;
    }

private:
    ListNode* findFromEnd(ListNode* head, int k) {
        ListNode* p1 = head;
        for (int i = 0; i < k; i++) {
            p1 = p1->next;
        }
        ListNode* p2 = head;
        while (p1 != nullptr) {
            p2 = p2->next;
            p1 = p1->next;
        }
        return p2;
    }
};

int main() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    int n = 2;

    Solution solution;
    ListNode* result = solution.removeNthFromeEnd(head, n);

    ListNode* cur = result;
    while (cur != nullptr) {
        cout << cur->val;
        cur = cur->next;
    }

    cin.get();
    return 0;
}
