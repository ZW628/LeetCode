#include <iostream>
#include <vector>

#include "ListNode.h"
using namespace std;

// 面试题 02.07. 链表相交
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *curA = headA;
        ListNode *curB = headB;
        int lenA = 0, lenB = 0;
        while (curA != NULL) { // 求链表A的长度
            lenA++;
            curA = curA->next;
        }
        while (curB != NULL) { // 求链表B的长度
            lenB++;
            curB = curB->next;
        }
        curA = headA;
        curB = headB;
        // 让curA为最长链表的头，lenA为其长度
        if (lenB > lenA) {
            swap(lenA, lenB);
            swap(curA, curB);
        }
        // 求长度差
        int gap = lenA - lenB;
        // 让curA和curB在同一起点上（末尾位置对齐）
        while (gap--) {
            curA = curA->next;
        }
        // 遍历curA 和 curB，遇到相同则直接返回
        while (curA != NULL) {
            if (curA == curB) {
                return curA;
            }
            curA = curA->next;
            curB = curB->next;
        }
        return NULL;
    }
};

#include <iostream>

#include "ListNode.h" // 假设你的头文件正确包含了 ListNode 类的定义
using namespace std;

int main() {
    // 创建链表A
    ListNode *headA = new ListNode(4);
    headA->next = new ListNode(1);
    headA->next->next = new ListNode(8);
    headA->next->next->next = new ListNode(4);
    headA->next->next->next->next = new ListNode(5);

    // 创建链表B
    ListNode *headB = new ListNode(5);
    headB->next = new ListNode(0);
    headB->next->next = new ListNode(1);
    headB->next->next->next = new ListNode(8);
    headB->next->next->next->next = new ListNode(4);
    headB->next->next->next->next->next = new ListNode(4);

    // 创建 Solution 实例
    Solution solution;

    // 找到链表的交点
    ListNode *interNode = solution.getIntersectionNode(headA, headB);

    // 输出结果
    if (interNode) {
        cout << "yes:" << interNode->val << endl;
    } else {
        cout << "no:" << endl;
    }

    // 记得释放动态分配的内存
    delete headA;
    delete headB;

    cin.get();
    return 0;
}
