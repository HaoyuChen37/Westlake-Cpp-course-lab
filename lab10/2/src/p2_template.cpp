#include <bits/stdc++.h>
using namespace std;


#define MAX 1000 // Max size of Heap
 
// Function to heapify ith node in a Heap
// of size n following a Bottom-up approach
void heapify(int arr[], int n, int i)
{
// ********************** your code bellow **********************
    // Initialize largest as root
    int largest = i;
 
    // left = 2*i + 1
    int left = 2 * i + 1;
 
    // right = 2*i + 2
    int right = 2 * i + 2;
 
    // If left child is larger than root
    if (left < n && arr[left] > arr[largest])
        largest = left;
 
    // If right child is larger than largest so far
    if (right < n && arr[right] > arr[largest])
        largest = right;
 
    // If largest is not root
    if (largest != i) {
        swap(arr[i], arr[largest]);
 
        // Recursively heapify the affected sub-tree
        heapify(arr, n, largest);
    }
// ********************** your code above **********************
}
 
// Function to insert a new node to the Heap
void insertNode(int arr[], int& n, int Key)
{
// ********************** your code bellow **********************
    // First insert the new key at the end
    arr[n] = Key;
    n++;
 
    // Fix the max heap property if it is violated
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
 
    // Heapify the new node
    heapify(arr, n, n - 1);
// ********************** your code above **********************
}
 
// A utility function to print array of size n
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
 
    cout << "\n";
}
 
// Driver Code
int main()
{
    // Array representation of Max-Heap
    // 10
    // / \
    // 5 3
    // / \
    // 2 4
    int arr[MAX] = { 10, 5, 3, 2, 4 };
 
    int n = 5;
 
    int key = 15;
 
    insertNode(arr, n, key);
 
    printArray(arr, n);
    // Final Heap will be:
    // 15
    // / \
    // 5     10
    // / \ /
    // 2 4 3
    return 0;
}