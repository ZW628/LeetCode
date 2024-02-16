#include <iostream>

#include "ListNode.h"

using namespace std;

// 环形链表2
// 双指针法
class Solution {
public:
    ListNode* detectCycle(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;

        while (fast != nullptr && fast->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow) break;
        }

        if (fast == nullptr || fast->next == nullptr) {
            return nullptr;
        }

        slow = head;

        while (slow != fast) {
            fast = fast->next;
            slow = slow->next;
        }
        return slow;
    }
};

int main() {
    ListNode* head = new ListNode(3);
    head->next = new ListNode(2);
    head->next->next = new ListNode(0);
    head->next->next->next = new ListNode(-4);
    head->next->next->next->next = head->next;

    Solution solution;
    ListNode* res = solution.detectCycle(head);

    if (res != nullptr) {
        cout << res->val;
    } else {
        cout << "No cycle found.";
    }

    cin.get();
    return 0;
}