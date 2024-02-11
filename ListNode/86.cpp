#include <iostream>

#include "ListNode.h"

using namespace std;

// 分隔链表
class Solution {
public:
    ListNode* separate(ListNode* head, int x) {
        // 存放小于x的链表
        ListNode* dummy1 = new ListNode(-1);
        // 存放大于等于x的链表
        ListNode* dummy2 = new ListNode(-1);

        ListNode *p1 = dummy1, *p2 = dummy2;

        ListNode* p = head;

        while (p != nullptr) {
            if (p->val >= x) {
                p2->next = p;
                p2 = p2->next;
            } else {
                p1->next = p;
                p1 = p1->next;
            }

            ListNode* temp = p->next;
            p->next = NULL;
            p = temp;
        }

        p1->next = dummy2->next;

        return dummy1->next;
    }
};