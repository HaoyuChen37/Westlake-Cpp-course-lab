#include <iostream>
#include <stdio.h>
#include <math.h>
#include <string>
#include <sstream>
#include <vector>
#include <cstring>


// 1.1
// class Student {
//     private:
//         char __name[20]; 
//         char __affiliation[50];
//         int __age;
//         char __gender;
//         double __weight;
//     public:
//         void set_name(char name[]) {
//             strncpy(__name, name, 19);
//             __name[19] = '\0';
//         }
//         void set_affiliation(char affiliation[]) {
//             strncpy(__affiliation, affiliation, 19);
//             __affiliation[19] = '\0';
//         }
//         void set_age(int age) {
//             __age = age;
//         }
//         void set_gender(char gender) {
//             __gender = gender;
//         }
//         void set_weight(double weight) {
//             __weight = weight;
//         }
//         void displayData() const {
//             std::cout << "Name: " << __name << std::endl;
//             std::cout << "Affiliation: " << __affiliation << std::endl;
//             std::cout << "Age: " << __age << std::endl;
//             std::cout << "Gender: " << __gender << std::endl;
//             std::cout << "Weight: " << __weight << std::endl;
//         }
// }; 

// int main(int argc, char **argv) {
//     Student student;
//     char name[20];
//     char affil[50];
//     int age;
//     char gender;
//     double weight;

//     printf("Please input the name of the student: ");
//     scanf("%19s", name);
//     printf("Please input the affiliation of the student: ");
//     scanf("%49s", affil);
//     printf("Please input the age of the student: ");
//     scanf("%d", &age);
//     printf("Please input the gender of the student: ");
//     scanf(" %c", &gender);
//     printf("Please input the weight of the student: ");
//     scanf("%lf", &weight);

//     student.set_name(name);
//     student.set_affiliation(affil);
//     student.set_age(age);
//     student.set_gender(gender);
//     student.set_weight(weight);

//     student.displayData();
//     return 0;
// }
// // Bug: can't read spacein the input string
// // For example: Affiliation: westlake university
// // The input will be: westlake
// // The output will be: Affiliation: westlake
// // The correct output should be: Affiliation: westlake university


// // 1.2
// class Student {
//     private:
//         char __name[20]; 
//         char __affiliation[50];
//         int __age;
//         char __gender;
//         double __weight;
//     public:
//         Student(char name[], char affiliation[], int age, char gender, double weight) {
//             strncpy(__name, name, 19);
//             __name[19] = '\0'; 
            
//             strncpy(__affiliation, affiliation, 19);
//             __affiliation[19] = '\0';
            
//             __age = age;
//             __gender = gender;
//             __weight = weight;
//         }
//         void displayData() const {
//             std::cout << "Name: " << __name << std::endl;
//             std::cout << "Affiliation: " << __affiliation << std::endl;
//             std::cout << "Age: " << __age << std::endl;
//             std::cout << "Gender: " << __gender << std::endl;
//             std::cout << "Weight: " << __weight << std::endl;
//         }
//     }; 
    
//     int main(int argc, char **argv) {
//         // 示例用法
//         char name[] = "XHDX";
//         char affil[] = "Westlake University";
//         Student student(name, affil, 18, 'M', 75.9);
//         student.displayData();
//         return 0;
//     }


// 1.3
// class Student {
//     private:
//         char __name[20]; 
//         char __affiliation[50];
//         int __age;
//         char __gender;
//         double __weight;
//     public:
//         Student(char name[], char affiliation[], int age, char gender, double weight) {
//             strncpy(__name, name, 19);
//             __name[19] = '\0'; 
            
//             strncpy(__affiliation, affiliation, 19);
//             __affiliation[19] = '\0';
            
//             __age = age;
//             __gender = gender;
//             __weight = weight;
//         }
//         ~Student() {
//             std::cout << "Destructor called" << std::endl;
//         }
//         void displayData() const {
//             std::cout << "Name: " << __name << std::endl;
//             std::cout << "Affiliation: " << __affiliation << std::endl;
//             std::cout << "Age: " << __age << std::endl;
//             std::cout << "Gender: " << __gender << std::endl;
//             std::cout << "Weight: " << __weight << std::endl;
//         }
//     }; 
    
// int main(int argc, char **argv) {
//     char name[] = "XHDX";
//     char affil[] = "Westlake University";
//     Student student(name, affil, 18, 'M', 75.9);
//     student.displayData();

//     Student *student2 = new Student(name, affil, 18, 'M', 75.9);
//     student2->displayData();
//     delete student2;
//     return 0;
// }

// // 1.4
// #include <iostream>
// #include <cstdio>
// #include <cstring>

// class Student {
// private:
//     char __name[20];
//     char __affiliation[50];
//     int __age;
//     char __gender;
//     double __weight;

// public:
//     void set_name(char name[]) {
//         strncpy(__name, name, 19);
//         __name[19] = '\0';
//     }

//     void set_affiliation(char affiliation[]) {
//         strncpy(__affiliation, affiliation, 49);
//         __affiliation[49] = '\0';
//     }

//     void set_age(int age) {
//         __age = age;
//     }

//     void set_gender(char gender) {
//         __gender = gender;
//     }

//     void set_weight(double weight) {
//         __weight = weight;
//     }

//     int get_age() const {
//         return __age;
//     }

//     void displayData() const {
//         std::cout << "Name: " << __name << std::endl;
//         std::cout << "Affiliation: " << __affiliation << std::endl;
//         std::cout << "Age: " << __age << std::endl;
//         std::cout << "Gender: " << __gender << std::endl;
//         std::cout << "Weight: " << __weight << std::endl;
//     }
// };

// class StudentNew : public Student {
// private:
//     float __grade;

// public:
//     void set_grade(float grade) {
//         __grade = grade;
//     }

//     float get_grade() const {
//         return __grade;
//     }

//     bool is_adult() const {
//         return get_age() >= 18;
//     }

//     void displayData() const {
//         Student::displayData();
//         std::cout << "Grade: " << __grade << std::endl;
//     }
// };

// int main(int argc, char **argv) {
//     StudentNew student;
//     char name[20];
//     char affil[50];
//     int age;
//     char gender;
//     double weight;
//     float grade;

//     printf("Please input the name of the student: ");
//     scanf("%19s", name);
//     printf("Please input the affiliation of the student: ");
//     scanf("%49s", affil);
//     printf("Please input the age of the student: ");
//     scanf("%d", &age);
//     printf("Please input the gender of the student: ");
//     scanf(" %c", &gender);
//     printf("Please input the weight of the student: ");
//     scanf("%lf", &weight);
//     printf("Please input the grade of the student: ");
//     scanf("%f", &grade);

//     student.set_name(name);
//     student.set_affiliation(affil);
//     student.set_age(age);
//     student.set_gender(gender);
//     student.set_weight(weight);
//     student.set_grade(grade);

//     student.displayData();

//     if (student.is_adult()) {
//         printf("%s is an adult.\n", name);
//     } else {
//         printf("%s is not an adult.\n", name);
//     }

//     return 0;
// }


// 1.5
#include <iostream>
#include <cstdio>
#include <cstring>

class Student {
private:
    char __name[20];
    char __affiliation[50];
    int __age;
    char __gender;
    double __weight;

public:
    void set_name(char name[]) {
        strncpy(__name, name, 19);
        __name[19] = '\0';
    }

    void set_affiliation(char affiliation[]) {
        strncpy(__affiliation, affiliation, 49);
        __affiliation[49] = '\0';
    }

    void set_age(int age) {
        __age = age;
    }

    void set_gender(char gender) {
        __gender = gender;
    }

    void set_weight(double weight) {
        __weight = weight;
    }

    int get_age() const {
        return __age;
    }

    const char* get_name() const {
        return __name;
    }

    void displayData() const {
        std::cout << "Name: " << __name << std::endl;
        std::cout << "Affiliation: " << __affiliation << std::endl;
        std::cout << "Age: " << __age << std::endl;
        std::cout << "Gender: " << __gender << std::endl;
        std::cout << "Weight: " << __weight << std::endl;
    }
};

class StudentNew : public Student {
private:
    float __grade;

public:
    StudentNew() {
        // Initialize name and affiliation using temporary buffers
        char name_buffer[] = "XHDX";
        char affil_buffer[] = "Westlake University";
        set_name(name_buffer);
        set_affiliation(affil_buffer);
        set_age(18);
        set_gender('M');
        set_weight(75.9);
        set_grade(2.0f);
    }

    void set_grade(float grade) {
        __grade = grade;
    }

    float get_grade() const {
        return __grade;
    }

    bool is_adult() const {
        return get_age() >= 18;
    }

    void displayData() const {
        Student::displayData();
        std::cout << "Grade: " << __grade << std::endl;
    }
};

int main() {
    StudentNew student;
    student.displayData();
    
    if (student.is_adult()) {
        std::cout << "This student is an adult." << std::endl;
    } else {
        std::cout << "This student is not an adult." << std::endl;
    }

    return 0;
}


// // 1.6
// #include <iostream>

// int main() {
//     int ia[5] = {1, 2, 3, 4, 5};
//     int *p = ia;
//     int *q, *r;

//     q = p + 4;
//     r = q - 1;

//     std::cout << *p << std::endl;
//     std::cout << *q << std::endl;
//     std::cout << *r << std::endl;
//     std::cout << *p + 1 << std::endl;
//     std::cout << *(r - 1) << std::endl;

//     return 0;
// }