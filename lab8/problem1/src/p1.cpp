#include <queue>
#include <stack>
#include <iostream>
using namespace std;

class MyStack {
private:
    queue<int> q1;  // 主队列（存储栈元素）
    queue<int> q2;  // 辅助队列

public:
    MyStack() {}
    
    void push(int x) {
        // TODO 新元素先进入辅助队列
        q2.push(x);

        // TODO 将主队列元素依次转移到辅助队列
        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }

        // TODO 交换队列，确保q1始终是栈顶在前
        swap(q1, q2);
    }
    
    int pop() {
        // TODO 返回并删除最前面的元素
        int topElement = q1.front();
        q1.pop();
        return topElement;
    }
    
    int top() {
        // TODO 返回最前面的元素
        return q1.front();
    }
    
    bool empty() {
        // TODO 检查是否为空
        return q1.empty();
    }
};





class MyQueue {
private:
    stack<int> inStack;   // 输入栈，用于入队操作
    stack<int> outStack;  // 输出栈，用于出队操作


    void transfer() {
        // TODO 将输入栈元素转移到输出栈（仅在输出栈为空时触发）
        while (!inStack.empty()) {
            outStack.push(inStack.top());
            inStack.pop();
        }
    }

public:
    MyQueue() {}

    void push(int x) {
        // TODO 直接压入输入栈
        inStack.push(x);
    }

    int pop() {
        // TODO 判断输出栈是否为空，空则触发元素转移
        if (outStack.empty()) {
            transfer();
        }

        // TODO 返回并删除上方元素
        int topElement = outStack.top();
        outStack.pop();
        return topElement;
    }

    int peek() {
        // TODO 判断输出栈是否为空，空则触发元素转移
        if (outStack.empty()) {
            transfer();
        }

        // TODO 返回上方元素
        return outStack.top();
    }

    bool empty() {
        // TODO 检查是否为空
        return inStack.empty() && outStack.empty();
    }
};


int main() {
    MyStack myStack = MyStack();
    myStack.push(1);
    myStack.push(2);
    std::cout << myStack.top(); // Returns 2
    std::cout << myStack.pop(); // Returns 2
    std::cout << myStack.empty(); // Returns false


    MyQueue myQueue = MyQueue();
    myQueue.push(1);
    myQueue.push(2);
    std::cout << myQueue.peek(); // Returns 1
    std::cout << myQueue.pop(); // Returns 1
    std::cout << myQueue.empty(); // Returns false
}