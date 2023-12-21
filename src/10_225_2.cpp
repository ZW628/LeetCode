#include <iostream>
#include <queue>

using namespace std;

// 一个队列来模拟栈
class MyStack {
public:
    queue<int> que;
    /** Initialize your data structure here. */
    MyStack() {}
    /** Push element x onto stack. */
    void push(int x) { que.push(x); }
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int size = que.size();
        size--;
        while (size--) { // 将队列头部的元素（除了最后一个元素外） 重新添加到队列尾部
            que.push(que.front());
            que.pop();
        }
        int result = que.front(); // 此时弹出的元素顺序就是栈的顺序了
        que.pop();
        return result;
    }

    /** Get the top element. */
    int top() { return que.back(); }

    /** Returns whether the stack is empty. */
    bool empty() { return que.empty(); }
};

int main() {
    MyStack stack;

    // 入栈操作
    stack.push(1);
    stack.push(2);
    stack.push(3);

    // 出栈操作
    cout << "Pop: " << stack.pop() << endl;

    // 检查队列是否为空
    cout << "Is the queue empty? " << (stack.empty() ? "Yes" : "No") << endl;

    cin.get();
    return 0;
}