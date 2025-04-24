// Question 5
// #include <iostream>
// #include <stdexcept>

// template <typename T>
// class DoublyLinkedList {
// private:
//     struct Node {
//         T data;
//         Node* prev;
//         Node* next;
//         Node(const T& value) 
//             : data(value), prev(nullptr), next(nullptr) {}
//     };

//     Node* head;
//     Node* tail;
//     size_t size;

// public:
//     DoublyLinkedList() : head(nullptr), tail(nullptr), size(0) {}
    
//     ~DoublyLinkedList() {
//         Node* current = head;
//         while (current) {
//             Node* next = current->next;
//             delete current;
//             current = next;
//         }
//     }
    
//     // Insert at head
//     void insertAtHead(const T& value) {
//         Node* newNode = new Node(value);
//         if (empty()) {
//             head = tail = newNode;
//         } else {
//             newNode->next = head;
//             head->prev = newNode;
//             head = newNode;
//         }
//         size++;
//     }
    
//     // Delete at tail
//     void deleteAtTail() {
//         if (empty()) return;
        
//         if (size == 1) {
//             delete head;
//             head = tail = nullptr;
//         } else {
//             Node* oldTail = tail;
//             tail = tail->prev;
//             tail->next = nullptr;
//             delete oldTail;
//         }
//         size--;
//     }
    
//     // Traversal operations
//     void forwardTraversal() const {
//         Node* current = head;
//         std::cout << "Forward: [ ";
//         while (current) {
//             std::cout << current->data << " ";
//             current = current->next;
//         }
//         std::cout << "]\n";
//     }
    
//     void backwardTraversal() const {
//         Node* current = tail;
//         std::cout << "Backward: [ ";
//         while (current) {
//             std::cout << current->data << " ";
//             current = current->prev;
//         }
//         std::cout << "]\n";
//     }
    
//     bool empty() const { return size == 0; }
//     size_t getSize() const { return size; }
// };

// // Example usage
// int main() {
//     DoublyLinkedList<int> list;
//     list.insertAtHead(3);
//     list.insertAtHead(2);
//     list.insertAtHead(1);
    
//     list.forwardTraversal();  // [1 2 3 ]
//     list.backwardTraversal(); // [3 2 1 ]
    
//     list.deleteAtTail();
//     list.forwardTraversal();  // [1 2 ]
    
//     return 0;
// }




// Question 6
// #include <stack>
// #include <unordered_map>
// #include <iostream>
// #include <string>

// using namespace std;

// bool isValidBrackets(const std::string& s) {
//     std::stack<char> bracketStack;
//     std::unordered_map<char, char> bracketPairs = {
//         {')', '('},
//         {']', '['},
//         {'}', '{'}
//     };

//     for (char c : s) {
//         if (bracketPairs.count(c)) {  // Closing bracket case
//             if (bracketStack.empty() || 
//                 bracketStack.top() != bracketPairs.at(c)) {
//                 return false;
//             }
//             bracketStack.pop();
//         } else if (c == '(' || c == '[' || c == '{') {  // Opening bracket case
//             bracketStack.push(c);
//         }
//         // Non-bracket characters are ignored
//     }
    
//     return bracketStack.empty();  // Stack must be empty for valid string
// }

// //% 测试用例集合
// struct TestCase {
//     std::string input;
//     bool expected;
// };

// int main() {
//     TestCase testCases[] = {
//         {"()", true},
//         {"()[]{}", true},
//         {"(]", false},
//         {"([)]", false},
//         {"{[]}", true},
//         {"([a+b]*{c/d})", true},
//         {"([a+b]*{c/d})[", false},
//         {"([a+b]*{c/d})]", false},
//         {"([a+b]*{c/d})[a+b]", true}
//     };
//     for (const auto& testCase : testCases) {
//         bool result = isValidBrackets(testCase.input);
//         std::cout << "Input: " << testCase.input 
//                   << ", Expected: " << std::boolalpha << testCase.expected 
//                   << ", Result: " << result << std::endl;
//     }

//     return 0;
// }


// Question 7
#include <iostream>

class CircularLinkedList {
private:
    struct Node {
        int data;
        Node* next;
        Node(int val) : data(val), next(nullptr) {}
    };
    Node* tail;  // Points to last node (tail->next = head)

public:
    CircularLinkedList() : tail(nullptr) {}

    ~CircularLinkedList() {
        if (!tail) return;
        Node* current = tail->next;
        while (current != tail) {
            Node* next = current->next;
            delete current;
            current = next;
        }
        delete tail;
    }

    // O(1) insertion at head (front)
    void insertAtHead(int val) {
        Node* newNode = new Node(val);
        if (!tail) {
            tail = newNode;
            tail->next = tail;
        } else {
            newNode->next = tail->next;
            tail->next = newNode;
        }
    }

    // O(1) insertion at tail (end)
    void insertAtTail(int val) {
        insertAtHead(val);
        tail = tail->next;  // Update tail to new node
    }

    void deleteHead() {
        if (!tail) return;
        
        Node* oldHead = tail->next;
        if (oldHead == tail) {
            delete tail;
            tail = nullptr;
        } else {
            tail->next = oldHead->next;
            delete oldHead;
        }
    }
    
    void display() {
        if (!tail) return;
        Node* current = tail->next;
        do {
            std::cout << current->data << " ";
            current = current->next;
        } while (current != tail->next);
        std::cout << "\n";
    }
};

// Test Case
int main() {
    CircularLinkedList cl;
    cl.insertAtHead(2);
    cl.insertAtTail(3);
    cl.insertAtHead(1);
    cl.display();  // Output: 1 2 3
    cl.deleteHead();
    cl.display();  // Output: 2 3
    return 0;
}