#include <iostream>
#include <vector>

#include "ListNode.h"
using namespace std;

class Solution {
public:
    ListNode *deleteTailN(ListNode *head, int n) {
        ListNode *dummyhead = new ListNode(0);
        dummyhead->next = head;
        // ListNode *cur = dummyhead;
        ListNode *fast = dummyhead, *low = dummyhead;
        while (n-- && fast != NULL) {
            fast = fast->next;
        }
        fast = fast->next;

        while (fast != NULL) {
            fast = fast->next;
            low = low->next;
        }
        low->next = low->next->next;

        return dummyhead->next;
    }
};

int main() {
    Solution solution;
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    int n = 2;
    ListNode *result = solution.deleteTailN(head, n);

    ListNode *cur = result;
    while (cur != NULL) {
        cout << cur->val;
        cur = cur->next;
    }

    cin.get();
    return 0;
}
// 输入：head = [1,2,3,4,5], n = 2 输出：[1,2,3,5]