#include <iostream>

#include "ListNode.h"

using namespace std;

// 相交链表
class Solution {
public:
    ListNode* getInterSectionNode(ListNode* headA, ListNode* headB) {
        ListNode* p1 = headA;
        ListNode* p2 = headB;
        while (p1 != p2) {
            if (p1 == nullptr)
                p1 = headB;
            else
                p1 = p1->next;
            if (p2 == nullptr)
                p2 = headA;
            else
                p2 = p2->next;
        }
        return p1;
    }
};

int main() {
    ListNode* a = new ListNode(1);
    a->next = new ListNode(2);
    a->next->next = new ListNode(3);
    a->next->next->next = new ListNode(9);

    ListNode* b = new ListNode(5);
    b->next = new ListNode(6);
    b->next->next = new ListNode(7);
    b->next->next->next = a->next->next;

    Solution solution;
    ListNode* res = solution.getInterSectionNode(a, b);

    if (res != nullptr) {
        cout << res->val;
    } else {
        cout << "No cycle found.";
    }

    cin.get();
    return 0;
}