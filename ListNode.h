#ifndef LISTNODE_H
#define LISTNODE_H
#include <iostream>
#include <vector>

struct ListNode {
    int val;        // 存储节点的整数值
    ListNode* next; // 指向下一个节点的指针,next 是一个指向 ListNode 类型的指针

    // 默认构造函数，初始化 val 和 next 为默认值
    ListNode() : val(0), next(nullptr) {}

    // 构造函数，接受一个整数参数 x，初始化 val 为 x，next 为 nullptr
    ListNode(int x) : val(x), next(nullptr) {}

    // 构造函数，接受两个参数，分别是整数值 x 和指向下一个节点的指针 next
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

/*
int main {
    // 创建链表节点
    ListNode* node1 = new ListNode(1);
    ListNode* node2 = new ListNode(2);
    ListNode* node3 = new ListNode(3);

    // 连接链表节点
    node1->next = node2;
    node2->next = node3;

    return 0;
}
*/

#endif