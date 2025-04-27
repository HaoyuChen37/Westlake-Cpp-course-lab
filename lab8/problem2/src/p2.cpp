#include <queue>
#include <deque>
#include <iostream>

class Checkout {
private:
    std::queue<int> main_queue;    // 主队列（FIFO）
    std::deque<int> max_deque;     // 辅助双端队列维护最大值（单调递减）

public:
    Checkout() {}

    // 添加商品到队列尾部
    void add(int value) {

        // TODO 添加商品到队列尾部
        main_queue.push(value);


        // TODO 维护max_deque单调性：移除尾部所有小于当前值的元素
        while (!max_deque.empty() && max_deque.back() < value) {
            max_deque.pop_back();
        }
        // TODO 将当前值添加到max_deque
        max_deque.push_back(value);
    }

    // 移除队列头部商品
    int remove() {

        // TODO 判断是否为空
        if (main_queue.empty()) {
            throw std::runtime_error("Queue is empty");
        }

        // TODO 弹出商品并删除
        int value = main_queue.front();
        main_queue.pop();

        // TODO 若移除元素是当前最大值，同步更新max_deque
        if (value == max_deque.front()) {
            max_deque.pop_front();
        }
        return value;
    }

    // 获取当前队列中的最高价格
    int get_max() {
        // TODO 获取当前队列中的最高价格
        if (max_deque.empty()) {
            throw std::runtime_error("Queue is empty");
        }
        return max_deque.front();
    }

    // 判断队列是否为空
    bool empty() {
        // TODO 判断队列是否为空
        return main_queue.empty();
    }
};

int main() {
    Checkout checkout;
    checkout.add(4);       // 队列: [4], max_deque: [4]
    checkout.add(7);       // 队列: [4,7], max_deque: [7]
    std::cout << checkout.get_max();  // 输出7
    std::cout << checkout.remove();   // 移除4 → 队列: [7], max_deque保持[7]
    std::cout << checkout.get_max();  // 输出7
}