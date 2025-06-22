
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

// Define the Course structure
struct Course {
    string courseNumber;
    string courseTitle;
    vector<string> prerequisites;
};

// Global hash table to store courses
unordered_map<string, Course> courseMap;

// Function to split a string by delimiter
vector<string> split(const string& s, char delimiter) {
    vector<string> tokens;
    string token;
    istringstream tokenStream(s);
    while (getline(tokenStream, token, delimiter)) {
        tokens.push_back(token);
    }
    return tokens;
}

// Function to load courses from file
void loadCourses(const string& fileName) {
    ifstream file(fileName);
    if (!file.is_open()) {
        cout << "Error opening file." << endl;
        return;
    }

    string line;
    while (getline(file, line)) {
        if (line.empty()) continue;

        vector<string> tokens = split(line, ',');
        if (tokens.size() < 2) {
            cout << "Invalid line format: missing required fields." << endl;
            continue;
        }

        Course course;
        course.courseNumber = tokens[0];
        course.courseTitle = tokens[1];
        for (size_t i = 2; i < tokens.size(); ++i) {
            course.prerequisites.push_back(tokens[i]);
        }

        courseMap[course.courseNumber] = course;
    }

    file.close();
    cout << "Courses loaded successfully." << endl;
}

// Function to print course information
void printCourseInfo(const string& courseNumber) {
    if (courseMap.find(courseNumber) != courseMap.end()) {
        Course course = courseMap[courseNumber];
        cout << course.courseNumber << ": " << course.courseTitle << endl;
        cout << "Prerequisites: ";
        if (course.prerequisites.empty()) {
            cout << "None";
        } else {
            for (const string& prereq : course.prerequisites) {
                cout << prereq << " ";
            }
        }
        cout << endl;
    } else {
        cout << "Course not found." << endl;
    }
}

// Function to print all courses in alphanumeric order
void printAllCourses() {
    vector<string> courseNumbers;
    for (const auto& pair : courseMap) {
        courseNumbers.push_back(pair.first);
    }
    sort(courseNumbers.begin(), courseNumbers.end());

    for (const string& number : courseNumbers) {
        cout << number << ": " << courseMap[number].courseTitle << endl;
    }
}

int main() {
    int choice;
    string fileName, input;

    do {
        cout << "\nMenu Options:" << endl;
        cout << "1. Load Data Structure" << endl;
        cout << "2. Print Course List" << endl;
        cout << "3. Print Course" << endl;
        cout << "9. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); // Ignore leftover newline character

        switch (choice) {
            case 1:
                cout << "Enter file name to load: ";
                getline(cin, fileName);
                loadCourses(fileName);
                break;
            case 2:
                printAllCourses();
                break;
            case 3:
                cout << "Enter course number: ";
                getline(cin, input);
                printCourseInfo(input);
                break;
            case 9:
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid option. Please try again." << endl;
        }
    } while (choice != 9);

    return 0;
}
