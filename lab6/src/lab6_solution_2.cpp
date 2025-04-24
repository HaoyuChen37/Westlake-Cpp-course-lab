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
    cout << "]\n";
}

// Split the linked list into k parts and return the middle part
ListNode* splitAndReturnMiddle(ListNode* head, int k) {
    int totalLen = 0;
    ListNode* curr = head;
    while (curr) {
        totalLen++;
        curr = curr->next;
    }

    int baseSize = totalLen / k;
    int extra = totalLen % k;

    vector<ListNode*> parts(k, nullptr);
    curr = head;

    for (int i = 0; i < k; ++i) {
        if (!curr) break;

        parts[i] = curr;
        int partLen = baseSize + (i < extra ? 1 : 0);
        for (int j = 1; j < partLen; ++j) {
            curr = curr->next;
        }

        if (curr) {
            ListNode* nextPart = curr->next;
            curr->next = nullptr;
            curr = nextPart;
        }
    }

    int middleIndex = (k % 2 == 0) ? (k / 2 - 1) : (k / 2);
    return parts[middleIndex];
}

void testSplit(const vector<int>& vals, int k) {
    cout << "Input: head = ";
    printList(createList(vals));
    cout << "k = " << k << endl;

    ListNode* head = createList(vals);
    ListNode* result = splitAndReturnMiddle(head, k);

    cout << "Middle part output: ";
    printList(result);
    cout << endl;
}

int main() {
    testSplit({1, 2, 3}, 5);  // Output: [3]
    testSplit({1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, 3);  // Output: [5, 6, 7]
    testSplit({1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, 4);  // Output: [4, 5, 6]
    testSplit({1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, 9);  // Output: [6]
    return 0;
}
