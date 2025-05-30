#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

class SolutionSubstringConcat {
public:
    std::vector<int> findSubstring(std::string s, std::vector<std::string>& words) {
        std::vector<int> result;
        if (s.empty() || words.empty()) return result;
        int wordLength = words[0].size();
        int totalWords = words.size();
        int totalLength = wordLength * totalWords;
        if (s.size() < totalLength) return result;
        std::unordered_map<std::string, int> wordCount;
        for (const auto& word : words) {
            wordCount[word]++;
        }
        for (int i = 0; i <= s.size() - totalLength; ++i) {
            std::unordered_map<std::string, int> seenWords;
            int j = 0;
            while (j < totalWords) {
                std::string word = s.substr(i + j * wordLength, wordLength);
                if (wordCount.find(word) == wordCount.end()) break;
                seenWords[word]++;
                if (seenWords[word] > wordCount[word]) break;
                j++;
            }
            if (j == totalWords) {
                result.push_back(i);
            }
        }
        
        if (result.empty()) {
            return result; // Return empty if no valid indices found
        }
        
        return result;
    }
};

// Example Usage (optional, for testing)
int main() {
    SolutionSubstringConcat sol;

    std::string s1 = "barfoothefoobarman";
    std::vector<std::string> words1 = {"foo", "bar"};
    std::vector<int> result1 = sol.findSubstring(s1, words1);
    std::cout << "Example 1: [";
    for (size_t i = 0; i < result1.size(); ++i) {
        std::cout << result1[i] << (i == result1.size() - 1 ? "" : ",");
    }
    std::cout << "]" << std::endl; // Expected: [0,9] or [9,0]

    std::string s2 = "wordgoodgoodgoodbestword";
    std::vector<std::string> words2 = {"word", "good", "best", "word"};
    std::vector<int> result2 = sol.findSubstring(s2, words2);
    std::cout << "Example 2: [";
    for (size_t i = 0; i < result2.size(); ++i) {
        std::cout << result2[i] << (i == result2.size() - 1 ? "" : ",");
    }
    std::cout << "]" << std::endl; // Expected: []

    std::string s3 = "barfoofoobarthefoobarman";
    std::vector<std::string> words3 = {"bar", "foo", "the"};
    std::vector<int> result3 = sol.findSubstring(s3, words3);
    std::cout << "Example 3: [";
    for (size_t i = 0; i < result3.size(); ++i) {
        std::cout << result3[i] << (i == result3.size() - 1 ? "" : ",");
    }
    std::cout << "]" << std::endl; // Expected: [6,9,12] (order may vary)

    std::string s4 = "wordgoodgoodgoodbestword";
    std::vector<std::string> words4 = {"word","good","best","good"};
     std::vector<int> result4 = sol.findSubstring(s4, words4);
    std::cout << "Example 4: [";
    for (size_t i = 0; i < result4.size(); ++i) {
        std::cout << result4[i] << (i == result4.size() - 1 ? "" : ",");
    }
    std::cout << "]" << std::endl; // Expected: [8]


    std::string s5 = "lingmindraboofooowingdingbarrwingmonkeypoundcake";
    std::vector<std::string> words5 = {"fooo","barr","wing","ding","wing"};
    std::vector<int> result5 = sol.findSubstring(s5, words5);
    std::cout << "Example 5: [";
    for (size_t i = 0; i < result5.size(); ++i) {
        std::cout << result5[i] << (i == result5.size() - 1 ? "" : ",");
    }
    std::cout << "]" << std::endl; // Expected: [13]

    return 0;
}