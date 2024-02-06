#include <iostream>

#include "ListNode.h"

// 两数相加
// 官方题解
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *result = nullptr, *temp = nullptr;
        int carry = 0;
        while (l1 || l2) {
            int n1 = l1 ? l1->val : 0;
            int n2 = l2 ? l2->val : 0;
            int sum = n1 + n2 + carry;
            if (!result) {
                result = temp = new ListNode(sum % 10);
            } else {
                temp->next = new ListNode(sum % 10);
                temp = temp->next;
            }
            carry = sum / 10;
            if (l1) {
                l1 = l1->next;
            }
            if (l2) {
                l2 = l2->next;
            }
        }
        if (carry > 0) {
            temp->next = new ListNode(carry);
        }
        return result;
    }
};

int main() {
    ListNode* l1 = new ListNode(2);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(3);

    ListNode* l2 = new ListNode(5);
    l2->next = new ListNode(6);
    l2->next->next = new ListNode(4);

    Solution solution;
    ListNode* result = solution.addTwoNumbers(l1, l2);

    ListNode* cur = result;
    while (cur != nullptr) {
        std::cout << cur->val;
        cur = cur->next;
    }

    std::cin.get();
    return 0;
}