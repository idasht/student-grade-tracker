#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

struct Student {
    std::string name;
    std::vector<double> grades;
    double average;
};

double calculateAverage(const std::vector<double>& grades) {
    if (grades.empty()) return 0.0;
    double sum = 0.0;
    for (double g : grades) sum += g;
    return sum / grades.size();
}

void printStudentInfo(const Student& s) {
    std::cout << "Name: " << s.name << "\nGrades: ";
    for (double g : s.grades) {
        std::cout << g << " ";
    }
    std::cout << "\nAverage: " << std::fixed << std::setprecision(2) << s.average << "\n\n";
}

int main() {
    std::vector<Student> students;
    int numStudents;

    std::cout << "How many students? ";
    std::cin >> numStudents;

    for (int i = 0; i < numStudents; ++i) {
        Student s;
        std::cout << "Enter name for student " << i + 1 << ": ";
        std::cin >> s.name;

        int numGrades;
        std::cout << "How many grades for " << s.name << "? ";
        std::cin >> numGrades;

        s.grades.resize(numGrades);
        std::cout << "Enter " << numGrades << " grades:\n";
        for (int j = 0; j < numGrades; ++j) {
            std::cin >> s.grades[j];
        }

        s.average = calculateAverage(s.grades);
        students.push_back(s);
    }

    std::cout << "\n--- Student Report ---\n";
    for (const Student& s : students) {
        printStudentInfo(s);
    }

    return 0;
}