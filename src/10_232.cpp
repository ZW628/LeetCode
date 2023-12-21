#include <iostream>
#include <stack>

using namespace std;

class MyQueue {
public:
    stack<int> stIn;  // 输入栈，用于入队操作
    stack<int> stOut; // 输出栈，用于出队操作

    // 构造函数，初始化对象
    MyQueue() {}
    // 入队操作，将元素 x 推入队列的尾部
    void push(int x) { stIn.push(x); }

    // 出队操作，删除队列的头部元素并返回
    int pop() {
        // 只有当stOut为空的时候，再从stIn里导入数据（导入stIn全部数据）
        if (stOut.empty()) {
            // 从stIn导入数据直到stIn为空
            while (!stIn.empty()) {
                stOut.push(stIn.top());
                stIn.pop();
            }
        }
        // 返回 stOut 的栈顶元素（即队列的头部元素）
        int result = stOut.top();
        stOut.pop();
        return result;
    }

    // 获取队列的头部元素，但不删除
    int peek() {
        // this 指的是调用该函数的 MyQueue 类的对象
        int res = this->pop(); // 直接使用已有的pop函数
        stOut.push(res);       // 因为pop函数弹出了元素res，所以再添加回去
        return res;
    }

    /** Returns whether the queue is empty. */
    bool empty() { return stIn.empty() && stOut.empty(); }
};

int main() {
    MyQueue queue;

    // 入队操作
    queue.push(1);
    queue.push(2);

    // 获取头部元素，但不删除
    cout << "Peek: " << queue.peek() << endl;

    // 出队操作
    cout << "Pop: " << queue.pop() << endl;

    // 检查队列是否为空
    cout << "Is the queue empty? " << (queue.empty() ? "Yes" : "No") << endl;

    cin.get();
    return 0;
}