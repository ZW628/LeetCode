#include <iostream>
#include <vector>

#include "ListNode.h"
using namespace std;

// 移除链表元素
// 直接使用原来的链表来进行移除节点操作
class Solution {
public:
    ListNode* removeElements(ListNode* head, int removal) {
        // 删除头节点
        // 使用 while 而不是 if 的原因在于可能需要连续删除链表头部的多个值相同的节点
        while (head != NULL && head->val == removal) {
            ListNode* temp = head;
            head = head->next;
            delete temp;
        }

        // 删除非头节点
        ListNode* cur = head;
        while (cur != NULL && cur->next != NULL) {
            if (cur->next->val == removal) {
                ListNode* temp = cur->next;
                cur->next = cur->next->next;
                delete temp;
            } else {
                cur = cur->next;
            }
        }
        return head;
    }
};

int main() {
    // 创建链表
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(6);
    head->next->next->next = new ListNode(3);
    head->next->next->next->next = new ListNode(4);
    head->next->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next->next = new ListNode(6);

    // 打印原始链表
    cout << "Original List: ";
    ListNode* cur = head;
    while (cur != NULL) {
        cout << cur->val << " ";
        cur = cur->next;
    }
    cout << endl;

    // 创建 Solution 对象
    Solution solution;

    // 调用 removeElements 函数
    int valToRemove = 6;
    ListNode* newHead = solution.removeElements(head, valToRemove);

    // 打印删除节点后的链表
    cout << "List after removal of nodes with value " << valToRemove << ": ";
    cur = newHead;
    while (cur != NULL) {
        cout << cur->val << " ";
        cur = cur->next;
    }
    cout << endl;

    cin.get();
    return 0;
}
