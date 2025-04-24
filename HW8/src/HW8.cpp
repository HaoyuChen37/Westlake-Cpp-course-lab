// A.2
// #include <vector>
// #include <stack>
// #include <iostream>
// using namespace std;

// vector<int> JumbleUp(const vector<int>& sequence, int startIdx, int endIdx) {
//     vector<int> result = sequence; // Copy the original sequence
//     stack<int> elementsStack;

//     // Push elements from startIdx to endIdx onto the stack
//     for (int i = startIdx; i <= endIdx; ++i) {
//         elementsStack.push(result[i]);
//     }

//     // Replace elements from startIdx to endIdx by popping from the stack
//     for (int i = startIdx; i <= endIdx; ++i) {
//         result[i] = elementsStack.top();
//         elementsStack.pop();
//     }

//     return result;
// }

// // Helper function to compare two vectors and print result
// bool TestJumbleUp(
//     const vector<int>& input,
//     int startIdx,
//     int endIdx,
//     const vector<int>& expected
// ) {
//     vector<int> output = JumbleUp(input, startIdx, endIdx);
//     if (output == expected) {
//         cout << "Test Passed" << endl;
//         return true;
//     } else {
//         cout << "Test Failed!" << endl;
//         cout << "   Input: ";
//         for (int num : input) cout << num << " ";
//         cout << "\n   [" << startIdx << ", " << endIdx << "]" << endl;
//         cout << "   Expected: ";
//         for (int num : expected) cout << num << " ";
//         cout << "\n   Received: ";
//         for (int num : output) cout << num << " ";
//         cout << endl;
//         return false;
//     }
// }

// int main() {
//     // 示例测试用例（用户提供的例子）
//     TestJumbleUp(
//         {1, 2, 3, 4, 5, 6, 7},  // 原序列
//         3,                      // startIdx (对应元素4)
//         5,                      // endIdx   (对应元素6)
//         {1, 2, 3, 6, 5, 4, 7}  // 期待结果: 4,5,6 → 6,5,4
//     );

//     // 测试：反转整个数组
//     TestJumbleUp(
//         {1, 2, 3, 4}, 0, 3,
//         {4, 3, 2, 1}
//     );

//     // 测试：单元素不用改变
//     TestJumbleUp(
//         {5}, 0, 0,
//         {5}
//     );

//     // 测试：更长的序列
//     TestJumbleUp(
//         {10, 20, 30, 40, 50, 60, 70, 80}, 2, 5,
//         {10, 20, 60, 50, 40, 30, 70, 80}  // 30-60 → 60-30
//     );

//     // 选中的部分在头部
//     TestJumbleUp(
//         {9, 8, 7, 6}, 0, 2,
//         {7, 8, 9, 6}  // 9,8,7 → 7,8,9
//     );

//     // 选中的部分在尾部
//     TestJumbleUp(
//         {100, 200, 300, 400}, 2, 3,
//         {100, 200, 400, 300}
//     );

//     return 0;
// }



// A.3
// #include <vector>
// #include <stack>
// using namespace std;

// int WhichIsMore(const vector<int>& input) {
//     stack<int> s;
    
//     for (int num : input) {
//         if (!s.empty() && s.top() != num) {
//             s.pop();
//         } else {
//             s.push(num);
//         }
//     }
    
//     if (s.empty()) {
//         return -1;
//     } else {
//         return s.top();
//     }
// }


// B.1
// #include <vector>
// #include <stack>
// #include <iostream>
// using namespace std;

// enum Direction { Up, Down, Left, Right };

// template <typename T1, typename T2>
// class Pair {
// public:
//     T1 first;
//     T2 second;
//     Pair(T1 f, T2 s) : first(f), second(s) {}
//     bool operator==(const Pair<T1, T2>& other) const {
//         return first == other.first && second == other.second;
//     }
// };

// Pair<int, int> computeNewPos(const Pair<int, int>& current, Direction dir) {
//     switch (dir) {
//         case Up: return Pair<int, int>(current.first + 1, current.second);
//         case Down: return Pair<int, int>(current.first - 1, current.second);
//         case Left: return Pair<int, int>(current.first, current.second - 1);
//         case Right: return Pair<int, int>(current.first, current.second + 1);
//     }
//     return current;
// }

// void printPath(Pair<int, int> start, vector<Direction> commands) {
//     stack<Pair<int, int>> path;
//     path.push(start);

//     for (const Direction& cmd : commands) {
//         Pair<int, int> current = path.top();
//         Pair<int, int> newPos = computeNewPos(current, cmd);

//         stack<Pair<int, int>> tempStack;
//         bool found = false;

//         // Check if newPos exists in the current path
//         while (!path.empty()) {
//             Pair<int, int> top = path.top();
//             if (top == newPos) {
//                 found = true;
//                 break;
//             }
//             tempStack.push(top);
//             path.pop();
//         }

//         if (found) {
//             // Clear the backtracked positions from tempStack
//             while (!tempStack.empty()) {
//                 tempStack.pop();
//             }
//         } else {
//             // Restore the original stack and push newPos
//             while (!tempStack.empty()) {
//                 path.push(tempStack.top());
//                 tempStack.pop();
//             }
//             path.push(newPos);
//         }
//     }

//     // Print the path in reverse order
//     vector<Pair<int, int>> reversedPath;
//     while (!path.empty()) {
//         reversedPath.push_back(path.top());
//         path.pop();
//     }

//     for (auto it = reversedPath.rbegin(); it != reversedPath.rend(); ++it) {
//         cout << "(" << it->first << ", " << it->second << ")";
//         if (next(it) != reversedPath.rend()) {
//             cout << " -> ";
//         }
//     }
//     cout << endl;
// }

// int main() {
//     Pair<int, int> start(1, 1);
//     vector<Direction> commands = { Up, Up, Right, Right, Down, Up, Left, Up };
//     printPath(start, commands); // Expected output: (1,1) -> (2,1) -> (3,1) -> (3,2) -> (4,2)
//     return 0;
// }


// B.2
// #include <stack>
// #include <iostream>
// using namespace std;

// int facS(int n) {
//     stack<int> exeS;
//     int result;
//     exeS.push(n);
//     while (!exeS.empty()) {
//         int current = exeS.top();
//         exeS.pop();
//         if (current >= 0) {
//             // Winding phase (function call)
//             cout << "Function fac(" << current << ") started" << endl;
//             if (current == 0) {
//                 result = 1;
//                 cout << "Function fac(" << current << ") ended. Return value = " << result << endl;
//             } else {
//                 // Schedule the return phase and next recursive call
//                 exeS.push(-current);
//                 exeS.push(current - 1);
//             }
//         } else {
//             // Unwinding phase (return from call)
//             int pos_current = -current;
//             result *= pos_current;
//             cout << "Function fac(" << pos_current << ") ended. Return value = " << result << endl;
//         }
//     }
//     return result;
// }

// int main() {
//     facS(3);
//     return 0;
// }


// B.3
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>  // 添加algorithm头文件
#include <string>     // 添加string头文件
using namespace std;

class TowerOfHanoi {
private:
    vector<stack<int>> poles;
    int numDiscs;

public:  // 将打印函数移至public区域
    // 横向打印柱子状态（示例：P0: [3 2 1]）
    void printHorizontal() {
        for (int i = 0; i < 3; i++) {
            cout << "P" << i << ": [";
            stack<int> temp = poles[i];
            vector<int> discs;
            while (!temp.empty()) {
                discs.push_back(temp.top());
                temp.pop();
            }
            reverse(discs.begin(), discs.end());  // 已修复：需要<algorithm>
            for (size_t j = 0; j < discs.size(); j++) {
                cout << discs[j];
                if (j != discs.size()-1) cout << " ";
            }
            cout << "]" << endl;
        }
    }

    // 纵向打印柱子状态（示例：3 2 1 在 P0 下方）
    void printVertical() {
        int maxWidth = to_string(numDiscs).length();
        vector<vector<string>> displayLines(3, vector<string>(numDiscs + 2, ""));
        
        // 生成每个柱子的显示内容
        for (int i = 0; i < 3; i++) {
            stack<int> pole = poles[i];
            vector<int> discs;
            while (!pole.empty()) {
                discs.push_back(pole.top());
                pole.pop();
            }
            reverse(discs.begin(), discs.end());  // 已修复
            
            // 填充圆盘行
            for (int j = 0; j < numDiscs; j++) {
                if (j < discs.size()) {
                    string disc = to_string(discs[j]);
                    disc = string(maxWidth - disc.length(), ' ') + disc;
                    displayLines[i][j] = disc;
                } else {
                    displayLines[i][j] = string(maxWidth, ' ');
                }
            }
            // 分隔线和标签
            displayLines[i][numDiscs] = string(maxWidth, '-');
            displayLines[i][numDiscs + 1] = "P" + to_string(i);
        }

        // 合并输出
        for (int line = 0; line < numDiscs + 2; line++) {
            for (int pole = 0; pole < 3; pole++) {
                cout << displayLines[pole][line] << "  ";
            }
            cout << endl;
        }
    }

    TowerOfHanoi(int n) : numDiscs(n) {
        poles.resize(3);
        for (int i = n; i >= 1; i--) {
            poles[0].push(i);
        }
    }

    void move(int from, int to, bool vertical = false) {
        if (poles[from].empty()) throw "Invalid move";
        if (!poles[to].empty() && poles[to].top() < poles[from].top()) {
            throw "Cannot place larger disc on smaller";
        }

        poles[to].push(poles[from].top());
        poles[from].pop();

        cout << "\nMove disc from P" << from << " to P" << to << ":" << endl;
        if (vertical) printVertical();
        else printHorizontal();
    }

    void solve(int n, int from, int to, int aux, bool vertical = false) {
        if (n == 0) return;
        solve(n-1, from, aux, to, vertical);
        move(from, to, vertical);
        solve(n-1, aux, to, from, vertical);
    }
};

int main() {
    int n = 3;
    TowerOfHanoi toh(n);
    cout << "Initial state:" << endl;
    toh.printHorizontal();  // 已修复：现在可以访问public函数

    cout << "\nSolving Tower of Hanoi (horizontal view):" << endl;
    toh.solve(n, 0, 2, 1);

    TowerOfHanoi tohVertical(n);
    cout << "\nSolving Tower of Hanoi (vertical view):" << endl;
    tohVertical.solve(n, 0, 2, 1, true);

    return 0;
}