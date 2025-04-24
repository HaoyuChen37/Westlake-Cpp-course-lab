#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x): val(x), next(nullptr) {}
};

// Create linked list
ListNode* createList(const vector<int>& vals) {
    if (vals.empty()) return nullptr;
    ListNode* head = new ListNode(vals[0]);
    ListNode* curr = head;
    for (size_t i = 1; i < vals.size(); ++i) {
        curr->next = new ListNode(vals[i]);
        curr = curr->next;
    }
    return head;
}

// Print linked list
void printList(ListNode* head) {
    cout << "[";
    while (head) {
        cout << head->val;
        if (head->next) cout << ", ";
        head = head->next;
    }
    cout << "]";
}

ListNode* removeAllTargetNodes(ListNode* head, int n) {
    ListNode dummy(0);
    dummy.next = head;
    ListNode* curr = &dummy; 

    while (curr->next != nullptr) {
        ListNode* nextNode = curr->next; // nextNode 指向当前节点的下一个节点
        if (nextNode->val == n) {
            // 如果当前节点的值等于 n，删除当前节点
            curr->next = nextNode->next; // 删除 nextNode
            delete nextNode; // 释放 nextNode 的内存
        } else {
            curr = curr->next; // 移动 curr 指针
        }
    }

    ListNode* curr1 = &dummy; // 重置 curr 为 dummy

    while (curr1->next != nullptr) {
        ListNode* prev1 = curr1; // prev 指向当前节点
        ListNode* prev2 = curr1->next; // prev2 指向当前节点的下一个节点
        if (prev2 == nullptr) break; // 如果 prev2 为空，退出循环
        ListNode* curr2 = prev2->next; // curr2 指向当前节点的下一个节点

        while (curr2 != nullptr) {
            if (curr->next->val + curr2->next->val == n) {
                // 如果找到满足条件的节点对，删除这两个节点
                prev1->next = prev1->next->next; // 删除 curr1
                delete prev1->next; // 释放 curr1 的内存
                prev2->next = prev2->next->next; // 删除 curr2
                delete prev2->next; // 释放 curr2 的内存
                break; // 退出内层循环
            } else {
                prev2 = prev2->next; // 移动 prev2 指针
            }
            curr2 = curr2->next; // 移动 curr2 指针
        }

                
    }


    return dummy.next;
}

// Test function
void testCase(const vector<int>& inputList, int target) {
    // Print input
    cout << "Input: head = ";
    printList(createList(inputList));  
    cout << ", n = " << target << endl;

    // Construct and modify
    ListNode* head = createList(inputList);
    head = removeAllTargetNodes(head, target);

    // Print result
    cout << "Output: ";
    printList(head);
    cout << "\n\n";
}

int main() {
    // Test cases
    testCase({1, 2, 3, 4, 5}, 5);     // Expected output: [1, 3, 4, 5]
    testCase({1, 2, 4, 5, 7}, 8);     // Expected output: [2, 4, 5]
    testCase({1, 2, 3, 4, 5}, 2);     // Expected output: [1, 3， 4, 5]
    testCase({1, 2}, 3);             // Expected output: []
    testCase({1, 2, 3}, 3);          // Expected output: []
    testCase({1, 3, 4, 5, 7, 10}, 9);// Expected output: [1, 3, 7, 10]
    testCase({1, 3, 4, 5, 7, 10}, 2);// Expected output: [1, 3, 4, 5, 7, 10]

    return 0;
}
