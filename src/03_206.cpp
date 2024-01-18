#include <iostream>

#include "ListNode.h"

using namespace std;

// 反转链表
// 双指针法
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* temp;
        ListNode* cur = head;
        ListNode* pre = NULL;
        while (cur) {
            temp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = temp;
        }
        return pre;
    }
};

int main() {
    // 创建链表
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    Solution solution;
    ListNode* newList = solution.reverseList(head);

    ListNode* cur = newList;
    while (cur != NULL) {
        cout << cur->val << " ";
        cur = cur->next;
    }

    cin.get();
    return 0;
}