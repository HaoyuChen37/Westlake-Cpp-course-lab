#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

class SolutionGroupAnagrams {
public:
    std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs) {
        std::vector<std::vector<std::string>> result;
        std::unordered_map<std::string, std::vector<std::string>> anagramMap;
        for (const auto& str : strs) {
            std::string sortedStr = str;
            std::sort(sortedStr.begin(), sortedStr.end());
            anagramMap[sortedStr].push_back(str);
        }
        for (const auto& pair : anagramMap) {
            result.push_back(pair.second);
        }
        


        return result;
    }
};

// Example Usage (optional, for testing)
int main() {
    SolutionGroupAnagrams sol;
    std::vector<std::string> strs1 = {"eat", "tea", "tan", "ate", "nat", "bat"};
    std::vector<std::vector<std::string>> result1 = sol.groupAnagrams(strs1);
    std::cout << "Example 1:" << std::endl;
    for (const auto& group : result1) {
        std::cout << "[";
        for (size_t i = 0; i < group.size(); ++i) {
            std::cout << "\"" << group[i] << "\"";
            if (i < group.size() - 1) std::cout << ", ";
        }
        std::cout << "]" << std::endl;
    }

    std::vector<std::string> strs2 = {""};
    std::vector<std::vector<std::string>> result2 = sol.groupAnagrams(strs2);
    std::cout << "\nExample 2:" << std::endl;
    for (const auto& group : result2) {
        std::cout << "[";
        for (size_t i = 0; i < group.size(); ++i) {
            std::cout << "\"" << group[i] << "\"";
            if (i < group.size() - 1) std::cout << ", ";
        }
        std::cout << "]" << std::endl;
    }

    std::vector<std::string> strs3 = {"a"};
    std::vector<std::vector<std::string>> result3 = sol.groupAnagrams(strs3);
    std::cout << "\nExample 3:" << std::endl;
    for (const auto& group : result3) {
        std::cout << "[";
        for (size_t i = 0; i < group.size(); ++i) {
            std::cout << "\"" << group[i] << "\"";
            if (i < group.size() - 1) std::cout << ", ";
        }
        std::cout << "]" << std::endl;
    }

    return 0;
}