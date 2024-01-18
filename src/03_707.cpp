#include <iostream>

#include "ListNode.h"

using namespace std;

class MyListNode {
public:
    // 虚拟头节点
    MyListNode() {
        _dummyHead = new ListNode(0);
        _size = 0;
    }

    // 获取到第index个节点数值，如果index是非法数值直接返回-1， 注意index是从0开始的，第0个节点就是头结点
    int get(int index) {
        if (index > (_size - 1) || index < 0) {
            return -1;
        }
        ListNode *cur = _dummyHead->next;
        while (index--) {
            cur = cur->next;
        }
        return cur->val;
    }

    // 在链表最前面插入一个节点，插入完成后，新插入的节点为链表的新的头结点
    void addHead(int val) {
        ListNode *newNode = new ListNode(val);
        newNode->next = _dummyHead->next;
        _dummyHead->next = newNode;
        _size++;
    }

    // 在链表最后面添加一个节点
    void addAtTail(int val) {
        ListNode *newNode = new ListNode(val);
        ListNode *cur = _dummyHead;
        while (cur->next != nullptr) {
            cur = cur->next;
        }
        cur->next = newNode;
        _size++;
    }

    // 在第index个节点之前插入一个新节点，例如index为0，那么新插入的节点为链表的新头节点
    // 如果index 等于链表的长度，则说明是新插入的节点为链表的尾结点
    // 如果index大于链表的长度，则返回空
    // 如果index小于0，则在头部插入节点
    void addAtIndex(int index, int val) {
        if (index > _size) return;
        if (index < 0) index = 0;
        ListNode *newNode = new ListNode(val);
        ListNode *cur = _dummyHead;
        while (index--) {
            cur = cur->next;
        }
        newNode->next = cur->next;
        cur->next = newNode;
        _size++;
    }

    // 删除第index个节点，如果index 大于等于链表的长度，直接return，注意index是从0开始的
    void deleteAtIndex(int index) {
        if (index >= _size || index < 0) return;
        ListNode *cur = _dummyHead;
        while (index--) {
            cur = cur->next;
        }
        ListNode *tmp = cur->next;
        cur->next = cur->next->next;
        delete tmp;
        tmp = nullptr;
        _size--;
    }

    // 打印链表
    void printListList() {
        ListNode *cur = _dummyHead;
        while (cur->next != nullptr) {
            cout << cur->next->val << " ";
            cur = cur->next;
        }
        cout << endl;
    }

private:
    ListNode *_dummyHead;
    int _size;
};

int main() {
    MyListNode myListNode;
    myListNode.addHead(1);
    myListNode.addAtTail(3);
    myListNode.addAtIndex(1, 2);
    cout << myListNode.get(1) << endl;
    myListNode.deleteAtIndex(1);
    cout << myListNode.get(1) << endl;

    cin.get();
    return 0;
}