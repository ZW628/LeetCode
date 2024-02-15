#include <iostream>

#include "ListNode.h"
using namespace std;

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
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
    ListNode* result = solution.middleNode(head);

    ListNode* cur = result;
    while (cur != nullptr) {
        cout << cur->val;
        cur = cur->next;
    }

    cin.get();
    return 0;
}
