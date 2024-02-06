#include <iostream>

#include "ListNode.h"

// 两数相加
// 暴力解法
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int unit1, deca1, hund1, unit2, deca2, hund2;
        if (l1 != nullptr && l2 != nullptr) {
            unit1 = l1->val;
            deca1 = l1->next->val;
            hund1 = l1->next->next->val;

            unit2 = l2->val;
            deca2 = l2->next->val;
            hund2 = l2->next->next->val;
        }
        int num1 = hund1 * 100 + deca1 * 10 + unit1;
        int num2 = hund2 * 100 + deca2 * 10 + unit2;
        int num3 = num1 + num2;

        int unit3 = num3 % 10;
        int deca3 = (num3 % 100) / 10;
        int hund3 = num3 / 100;

        ListNode* result = new ListNode(unit3);
        result->next = new ListNode(deca3);
        result->next->next = new ListNode(hund3);

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