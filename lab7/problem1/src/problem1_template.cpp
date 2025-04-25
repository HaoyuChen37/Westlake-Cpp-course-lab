#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void insertionSortWithIndices(std::vector<int>& nums, std::vector<int>& indices) {
// **************** Your answer code begin here! ****************
    int n = nums.size();

    for (int i = n-1; i>=1; --i){
        int Maxpnt = i;
        for (int j = 0; j<i; ++j){
            if (nums[j] > nums[Maxpnt]){
                Maxpnt = j;
            }

            int temp = nums[i];
            nums[i] = nums[Maxpnt];
            nums[Maxpnt] = temp;
            temp = indices[i];
            indices[i] = indices[Maxpnt];
            indices[Maxpnt] = temp;
        }
    }

// **************** Your answer code end here!   ****************
}

/*
examples for debug:
input:
4
4 2 9 1
output:
Sorted array: 1 2 4 9 
Indices: 3 1 0 2 

input:
5
10 20 10 30 20
output:
Sorted array: 10 10 20 20 30 
Indices: 0 2 1 4 3 
*/
int main() {
    int n;
    vector<int> nums;
    cin>>n;
    for (int i = 0; i < n; ++i) {
        int num;
        cin>>num;
        nums.push_back(num);
    }

    std::vector<int> indices(n);

    // Initialize indices
    for (int i = 0; i < nums.size(); ++i) indices[i] = i;

    // Sort the array using insertion sort while tracking the indices
    insertionSortWithIndices(nums, indices);

    // Output the sorted array
    std::cout << "Sorted array: ";
    for (const auto& num : nums) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // Output the original indices
    std::cout << "Indices: ";
    for (const auto& index : indices) {
        std::cout << index << " ";
    }
    std::cout << std::endl;

    return 0;
}
