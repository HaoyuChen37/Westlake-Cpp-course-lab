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

    bool changed;
    do {
        changed = false;

        // Step 1: Remove all individual nodes equal to n
        ListNode* prev = &dummy;
        ListNode* curr = dummy.next;
        while (curr) {
            if (curr->val == n) {
                prev->next = curr->next;
                curr = prev->next;
                changed = true;
            } else {
                prev = curr;
                curr = curr->next;
            }
        }

        // Step 2: Remove all pairs of nodes whose sum equals n (only one pair at a time)
        ListNode* outerPrev = &dummy;
        ListNode* node1 = dummy.next;

        bool pairDeleted = false;
        while (node1 && !pairDeleted) {
            ListNode* innerPrev = node1;
            ListNode* node2 = node1->next;

            while (node2) {
                if (node1->val + node2->val == n) {
                    // Delete node1 and node2
                    if (innerPrev == node1) {
                        // Adjacent nodes
                        outerPrev->next = node2->next;
                    } else {
                        outerPrev->next = node1->next;
                        innerPrev->next = node2->next;
                    }
                    changed = true;
                    pairDeleted = true;
                    break;
                }
                innerPrev = node2;
                node2 = node2->next;
            }

            if (!pairDeleted) {
                outerPrev = node1;
                node1 = node1->next;
            }
        }

    } while (changed);

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
