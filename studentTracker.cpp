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

char getLetterGrade(double avg) {
    if (avg >= 90.0) return 'A';
    else if (avg >= 80.0) return 'B';
    else if (avg >= 70.0) return 'C';
    else if (avg >= 60.0) return 'D';
    else return 'F';
}

void printStudentInfo(const Student& s) {
    std::cout << "Name: " << s.name << "\nGrades: ";
    for (double g : s.grades) {
        std::cout << g << " ";
    }
    std::cout << "\nAverage: " << std::fixed << std::setprecision(2) << s.average << "\n";
    std::cout << "Letter Grade: " << getLetterGrade(s.average) << "\n\n";
}

int main() {
    Student s;

    std::cout << "Enter your name: ";
    std::cin >> s.name;

    int numGrades;
    std::cout << "How many grades do you want to enter? ";
    std::cin >> numGrades;

    s.grades.resize(numGrades);
    std::cout << "Enter " << numGrades << " grades:\n";
    for (int j = 0; j < numGrades; ++j) {
        std::cin >> s.grades[j];
    }

    s.average = calculateAverage(s.grades);

    std::cout << "\n--- Your Report ---\n";
    printStudentInfo(s);

    return 0;
}