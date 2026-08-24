// ProjectTwo.cpp
// Author: Louis Richards
// CS 300 Project Two
// Advising Assistance Program

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

// Structure to store course information
struct Course {
    string courseNumber;
    string courseTitle;
    vector<string> prerequisites;
};

// Hash table to store courses
unordered_map<string, Course> courseTable;

// Loads course data from the CSV file
bool loadCourses(string fileName) {
    ifstream file(fileName);

    if (!file.is_open()) {
        cout << "Error: Could not open file." << endl;
        return false;
    }

    // Clear old data before loading a new file
    courseTable.clear();

    string line;

    while (getline(file, line)) {
        stringstream ss(line);
        string item;

        Course course;

        // Get course number
        getline(ss, course.courseNumber, ',');

        // Get course title
        getline(ss, course.courseTitle, ',');

        // Get any prerequisites
        while (getline(ss, item, ',')) {
            if (!item.empty()) {
                course.prerequisites.push_back(item);
            }
        }

        // Store course in the hash table
        courseTable[course.courseNumber] = course;
    }

    file.close();
    return true;
}

// Prints all courses in alphanumeric order
void printCourseList() {
    vector<string> courseNumbers;

    // Store all course numbers in a vector
    for (const auto& pair : courseTable) {
        courseNumbers.push_back(pair.first);
    }

    // Sort course numbers
    sort(courseNumbers.begin(), courseNumbers.end());

    cout << "Here is a sample schedule:" << endl;

    // Print courses in sorted order
    for (const string& courseNumber : courseNumbers) {
        Course course = courseTable[courseNumber];

        cout << course.courseNumber << ", "
            << course.courseTitle << endl;
    }
}

// Prints information for one course
void printCourse() {
    string courseNumber;

    cout << "What course do you want to know about? ";
    cin >> courseNumber;

    // Convert input to uppercase
    transform(courseNumber.begin(), courseNumber.end(),
        courseNumber.begin(), ::toupper);

    auto it = courseTable.find(courseNumber);

    if (it == courseTable.end()) {
        cout << "Course not found." << endl;
        return;
    }

    Course course = it->second;

    cout << course.courseNumber << ", "
        << course.courseTitle << endl;

    if (course.prerequisites.empty()) {
        cout << "Prerequisites: None" << endl;
    }
    else {
        cout << "Prerequisites:" << endl;

        for (const string& prereq : course.prerequisites) {
            Course prerequisiteCourse = courseTable[prereq];

            cout << prerequisiteCourse.courseNumber << ", "
                << prerequisiteCourse.courseTitle << endl;
        }
    }
}

int main() {
    int choice = 0;
    string fileName;

    cout << "Welcome to the course planner." << endl;

    while (choice != 9) {
        cout << endl;
        cout << "1. Load Data Structure." << endl;
        cout << "2. Print Course List." << endl;
        cout << "3. Print Course." << endl;
        cout << "9. Exit" << endl;
        cout << "What would you like to do? ";

        // Check for invalid menu input
        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Invalid input. Please enter a number." << endl;
            continue;
        }

        if (choice == 1) {
            cout << "Enter the file name: ";
            getline(cin >> ws, fileName);

            if (loadCourses(fileName)) {
                cout << "Course data loaded successfully." << endl;
            }
        }
        else if (choice == 2) {
            if (courseTable.empty()) {
                cout << "Please load the course data first." << endl;
            }
            else {
                printCourseList();
            }
        }
        else if (choice == 3) {
            if (courseTable.empty()) {
                cout << "Please load the course data first." << endl;
            }
            else {
                printCourse();
            }
        }
        else if (choice == 9) {
            cout << "Thank you for using the course planner!" << endl;
        }
        else {
            cout << choice << " is not a valid option." << endl;
        }
    }

    return 0;
}