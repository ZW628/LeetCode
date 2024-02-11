#include <iostream>

#include "ListNode.h"

using namespace std;

// 合并两个有序链表
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(-1);
        ListNode *p = dummy, *p1 = l1, *p2 = l2;

        while (p1 != NULL && p2 != NULL) {
            if (p1->val > p2->val) {
                p->next = p2;
                p2 = p2->next;
            } else {
                p->next = p1;
                p1 = p1->next;
            }
            p = p->next;
        }

        if (p1 != NULL) {
            p->next = p1;
        }

        if (p2 != NULL) {
            p->next = p2;
        }

        return dummy->next;
    }
};

int main() {
    ListNode* l1 = new ListNode(1);
    l1->next = new ListNode(2);
    l1->next->next = new ListNode(4);

    ListNode* l2 = new ListNode(1);
    l2->next = new ListNode(3);
    l2->next->next = new ListNode(4);

    Solution solution;
    ListNode* res = solution.mergeTwoLists(l1, l2);

    ListNode* cur = res;
    while (cur != nullptr) {
        cout << cur->val;
        cur = cur->next;
    }

    cin.get();
    return 0;
}