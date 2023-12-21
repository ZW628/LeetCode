#include <iostream>
#include <vector>

#include "ListNode.h"
using namespace std;

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* dummyHead = new ListNode(0); // 设置一个虚拟头结点
        dummyHead->next = head;                // 将虚拟头结点指向head，这样方便后面做删除操作
        ListNode* cur = dummyHead;
        while (cur->next != nullptr && cur->next->next != nullptr) {
            ListNode* tmp = cur->next;              // 记录临时节点
            ListNode* tmp1 = cur->next->next->next; // 记录临时节点

            cur->next = cur->next->next;  // 步骤一
            cur->next->next = tmp;        // 步骤二
            cur->next->next->next = tmp1; // 步骤三

            cur = cur->next->next; // cur移动两位，准备下一轮交换
        }
        return dummyHead->next; // 返回虚拟头结点的下一个节点，即新的头结点
    }
};

int main() {
    // 创建链表
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);

    // 打印原始链表
    cout << "Original List: ";
    ListNode* cur = head;
    while (cur != NULL) {
        cout << cur->val << " ";
        cur = cur->next;
    }
    cout << endl;

    Solution solution;
    ListNode* newHead = solution.swapPairs(head);

    // 打印删除节点后的链表
    cout << "List after swap of nodes with value "
         << ": ";
    cur = newHead;
    while (cur != NULL) {
        cout << cur->val << " ";
        cur = cur->next;
    }
    cout << endl;

    cin.get();
    return 0;
}