#include <iostream>
#include <vector>

using namespace std;


// Helper function to merge two sorted subarrays and count inversions
int mergeAndCount(vector<int>& nums, int left, int mid, int right) {
    int n1 = mid - left + 1; // Size of the left subarray
    int n2 = right - mid;    // Size of the right subarray

    // Create temporary arrays
    vector<int> L(n1);
    vector<int> R(n2);

    // Copy data to temporary arrays
    for (int i = 0; i < n1; i++) {
        L[i] = nums[left + i];
    }
    for (int j = 0; j < n2; j++) {
        R[j] = nums[mid + 1 + j];
    }

    int i = 0, j = 0, k = left, inversions = 0;

    // Merge the two subarrays back into nums[left...right]
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            nums[k++] = L[i++];
        } else {
            nums[k++] = R[j++];
            inversions += (mid - left - i + 1); // Count inversions
        }
    }

    // Copy remaining elements of L[], if any
    while (i < n1) {
        nums[k++] = L[i++];
    }

    // Copy remaining elements of R[], if any
    while (j < n2) {
        nums[k++] = R[j++];
    }

    return inversions;
}

// Function to recursively divide the array and count inversions
int mergeSortAndCount(vector<int>& nums, int left, int right) {
    int inversions = 0;
    if (left < right) {
        int mid = left + (right - left) / 2;

        // Recursively count inversions in both halves
        inversions += mergeSortAndCount(nums, left, mid);
        inversions += mergeSortAndCount(nums, mid + 1, right);

        // Merge the two halves and count inversions during merge
        inversions += mergeAndCount(nums, left, mid, right);
    }
    return inversions;
}

int minSwaps(vector<int>& nums) {
    int swaps = 0;
// **************** Your answer code begin here! ****************
    int n = nums.size();
    return mergeSortAndCount(nums, 0, n - 1);
// **************** Your answer code end here!   ****************
    // return swaps;
}

/*
examples for debug:
input:
4
5 3 6 1
output:
4
*/

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    int result = minSwaps(nums);
    cout << result << endl;

    return 0;
}
