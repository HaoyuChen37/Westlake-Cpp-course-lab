// 1.2
// #include <iostream>
// #include <iomanip>
// using namespace std;

// int main() {
//     double a = 2.333;
//     bool b = true;

//     cout << setprecision(3) << a << " " << a << endl;
//     cout << b << boolalpha << endl;
// }

// 1.3
// #include <iostream>
// using namespace std;

// int main() {
//     cout << "What year was your house built? \n";
//     int year;
//     cin >> year;
//     cout << "What is its street address? \n";
//     char address[80];
//     cin.getline(address, 80);
//     cout << "Year built: " << year << endl;
//     cout << "Address: " << address << endl;
//     cout << "Done!\n";
//     return 0;
// }

// #include <iostream>
// using namespace std;

// int main() {
//     cout << "What year was your house built? \n";
//     int year;
//     cin >> year;
//     cin.ignore(); // ignore \n
//     cout << "What is its street address? \n";
//     char address[80];
//     cin.getline(address, 80);
//     cout << "Year built: " << year << endl;
//     cout << "Address: " << address << endl;
//     cout << "Done!\n";
//     return 0;
// }


// 1.4
// #include <fstream>
// #include <string>
// #include <iostream>

// using namespace std;

// void trans_words(const string& input_path, const string& output_path) {
//     ifstream fin(input_path);
//     if (!fin.is_open()) {
//         cout << "Error: Unable to open input file: " << input_path << endl;
//         return;
//     }

//     ofstream fout(output_path);
//     if (!fout.is_open()) {
//         cout << "Error: Unable to open output file: " << output_path << endl;
//         fin.close();
//         return;
//     }

//     string word;
//     while (fin >> word) {  
//         fout << word << '\n';  
//     }

//     fin.close();
//     fout.close();
// }

// int main() {
//     trans_words("D:\\workspace\\Westlake-Cpp-course-lab\\HW5\\src\\input.txt", "D:\\workspace\\Westlake-Cpp-course-lab\\HW5\\src\\output.txt");
//     return 0;
// }


// // 1.5
// #include <string>
// #include <iostream>
// using namespace std;

// int main() {
//     std::string str1 = "abc";
//     std::string str2 = "efg";
//     std::string str3; 

//     str3 = str1 + str2;
//     cout << str3 << endl;
//     return 0;
// }

// #include <cstring>
// #include <iostream>
// using namespace std;

// int main() {
//     const char* str1 = "abc";
//     const char* str2 = "efg";
//     char* str3 = nullptr;

//     size_t len1 = strlen(str1);
//     size_t len2 = strlen(str2);
//     size_t total_len = len1 + len2 + 1;  // +1 for null-terminator

//     str3 = new char[total_len];  

//     strcpy(str3, str1);        // copy str1 to str3
//     strcat(str3, str2);        // add str2

//     cout << str3 << endl;      // print str3
// }

// 1.6
// #include <string>
// #include <iostream>

// class Student {
// private:
//     std::string name;
//     int age;
//     std::string gender;

// public:
//     Student(const std::string& name, int age, const std::string& gender)
//         : name(name), age(age), gender(gender) {}
// };

// int main() {
//     Student student("XHDX", 18, "Male");
//     return 0;
// }


// // 1.7
// #include <fstream>
// #include <vector>
// #include <sstream>
// #include <string>
// #include <iostream>

// using namespace std;

// class Student {
// private:
//     string name;
//     int age;
//     string gender;

// public:
//     Student(const string& name, int age, const string& gender)
//         : name(name), age(age), gender(gender) {}
//     string getName() const { return name; }
//     int getAge() const { return age; }
//     string getGender() const {return gender; }
// };

// int main() {
//     vector<Student> students;
//     ifstream inputFile("D:\\workspace\\Westlake-Cpp-course-lab\\HW5\\src\\info.txt");

//     if (!inputFile.is_open()) {
//         cout << "Error: Cannot open info.txt!" << endl;
//         return 1;
//     }

//     string line;
//     while (getline(inputFile, line)) {      // 逐行读取文件
//         istringstream iss(line);
//         string name, ageStr, gender;
        
//         // 按Tab分割字段
//         if (getline(iss, name, '\t') && 
//             getline(iss, ageStr, '\t') && 
//             getline(iss, gender, '\t')) {
            
//             // 转换年龄为整数
//             int age = stoi(ageStr);
//             students.emplace_back(name, age, gender);  // 添加学生对象到vector
//         } else {
//             cout << "Warning: Invalid format in line: " << line << endl;
//         }
//     }

//     // 确保 vector 非空
//     if (students.size() > 0) {
//         // 方式1: front()
//         cout << "First student name (front()): " << students.front().getName() << endl;
        
//         // 方式2: begin()
//         cout << "First student name (begin()): " << students.begin()->getName() << endl;
//     }

//     inputFile.close();
//     return 0;
// }


// 1.9
#include <fstream>
#include <vector>
#include <sstream>
#include <stdexcept>
#include <string>
#include <iostream>
using namespace std;

class Student {
private:
    string name;
    int age;
    string gender;

public:
    Student(const string& name, int age, const string& gender)
        : name(name), age(age), gender(gender) {}
    string getName() const { return name; }
    int getAge() const { return age; }
    string getGender() const { return gender; }
};

Student processStudentLine(const string& line) {
    istringstream iss(line);
    string name, ageStr, gender;

    if (!(iss >> name >> ageStr >> gender)) {
        throw invalid_argument("Invalid line format: " + line);
    }

    string temp;
    if (iss >> temp) {
        throw invalid_argument("Extra data in line: " + line);
    }

    int age;
    try {
        age = stoi(ageStr);
    } catch (const invalid_argument&) {
        throw invalid_argument("Non-numeric age in line: " + line);
    }

    if (gender != "male" && gender != "female") {
        throw runtime_error("Invalid gender '" + gender + "' in line: " + line);
    }

    return Student(name, age, gender);
}

int main() {
    vector<Student> students;
    ifstream inputFile("D:\\workspace\\Westlake-Cpp-course-lab\\HW5\\src\\info.txt");

    // 关键修复：添加文件打开状态检查
    if (!inputFile.is_open()) {
        cerr << "Error: Failed to open info.txt!" << endl;
        return 1;  // 提前退出
    }

    string line;
    while (getline(inputFile, line)) {
        try {
            Student stu = processStudentLine(line);
            students.push_back(stu);
        } 
        catch (const runtime_error& e) { 
            cout << "[Gender error] " << e.what() << endl;
        }
        catch (const invalid_argument& e) { 
            cout << "[Format Error] " << e.what() << endl;
        }
    }

    inputFile.close();
    return 0;
}