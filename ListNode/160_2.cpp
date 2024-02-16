#include <iostream>

#include "ListNode.h"

using namespace std;

// 相交链表
class Solution {
public:
    ListNode* getInterSectionNode(ListNode* headA, ListNode* headB) {
        // 计算两个链表长度
        int lenA = 0, lenB = 0;
        for (ListNode* p1 = headA; p1 != nullptr; p1 = p1->next) {
            lenA++;
        }
        for (ListNode* p2 = headB; p2 != nullptr; p2 = p2->next) {
            lenB++;
        }
        // 长的链表先走
        ListNode *p1 = headA, *p2 = headB;
        if (lenA > lenB)
            for (int i = 0; i < lenA - lenB; i++) {
                p1 = p1->next;
            }
        if (lenB > lenA)
            for (int i = 0; i < lenB - lenA; i++) {
                p2 = p2->next;
            }
        // 同时走
        while (p1 != p2) {
            p1 = p1->next;
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