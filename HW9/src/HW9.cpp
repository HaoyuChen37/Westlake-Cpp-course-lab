// #include <iostream>
// using namespace std;
// // 1.2
// double Exponential1(double base, int exp) {
//     double ans = 1;
//     for (int i = 0; i < exp; ++i){
//         ans *= base;
//     }
//     return ans;
// }

// double Exponential2(double base, int exp) {
//     if (exp == 1){
//         return base;
//     }
//     return Exponential2(base, exp-1)*base;
// }

// double Exponential3(double base, int exp) {
//     if (exp == 1){
//         return base;
//     }
//     if (exp%2==1){
//         return Exponential3(base, exp-1)*base; 
//     }
//     else{
//         return Exponential3(base, exp/2)*Exponential3(base, exp/2);
//     }
// }

// int main(){
//     cout << Exponential1(3,2) << endl; // 9
//     cout << Exponential2(3,3) << endl; // 27
//     cout << Exponential3(3,4) << endl; // 81
//     cout << Exponential3(3,5) << endl; // 243
//     return 0;
// }


// 2.1.a without sorting
// #include <iostream>
// #include <vector>

// std::vector<int> removeDuplicatesWithoutSorting(const std::vector<int>& L) {
//     std::vector<int> result;

//     // 遍历数组中的每个元素
//     for (size_t i = 0; i < L.size(); ++i) {
//         bool isDuplicate = false;

//         // 检查当前元素是否已经在结果数组中
//         for (size_t j = 0; j < result.size(); ++j) {
//             if (L[i] == result[j]) {
//                 isDuplicate = true; // 如果找到重复项，标记为 true
//                 break;
//             }
//         }

//         // 如果当前元素不是重复项，则加入结果数组
//         if (!isDuplicate) {
//             result.push_back(L[i]);
//         }
//     }

//     return result;
// }

// int main() {
//     std::vector<int> L = {5, 1, 2, 1, 3, 5, 4};
//     std::vector<int> result = removeDuplicatesWithoutSorting(L);

//     std::cout << "Result without sorting: ";
//     for (int num : result) {
//         std::cout << num << " ";
//     }
//     std::cout << std::endl;

//     return 0;
// }


// 2.1.b with sorting
// #include <iostream>
// #include <vector>
// #include <algorithm>

// std::vector<int> removeDuplicatesWithSorting(std::vector<int> L) {
//     std::sort(L.begin(), L.end()); // Sort the array
//     std::vector<int> result;

//     for (size_t i = 0; i < L.size(); ++i) {
//         if (i == 0 || L[i] != L[i - 1]) { // If it's the first element or not a duplicate
//             result.push_back(L[i]); // Add it to the result
//         }
//     }

//     return result;
// }

// int main() {
//     std::vector<int> L = {5, 1, 2, 1, 3, 5, 4};
//     std::vector<int> result = removeDuplicatesWithSorting(L);

//     std::cout << "Result with sorting: ";
//     for (int num : result) {
//         std::cout << num << " ";
//     }
//     std::cout << std::endl;

//     return 0;
// }