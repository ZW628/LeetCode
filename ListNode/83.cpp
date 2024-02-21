#include <iostream>
#include <vector>

#include "ListNode.h"
using namespace std;

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr) return nullptr;
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast != nullptr) {
            if (fast->val != slow->val) {
                slow->next = fast;
                slow = slow->next;
            }
            fast = fast->next;
        }
        slow->next = nullptr;
        return head;
    }
};

int main() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(1);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(3);
    head->next->next->next->next = new ListNode(3);

    Solution solution;
    ListNode* result = solution.deleteDuplicates(head);

    ListNode* cur = result;
    while (cur != nullptr) {
        cout << cur->val;
        cur = cur->next;
    }

    cin.get();
    return 0;
}