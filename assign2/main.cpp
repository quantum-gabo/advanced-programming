/*
 * CS106L Assignment 2: Marriage Pact
 * Created by Haven Whitney with modifications by Fabio Ibanez & Jacob Roberts-Baca.
 *
 * Welcome to Assignment 2 of CS106L! Please complete each STUDENT TODO
 * in this file. You do not need to modify any other files.
 *
 */

#include <fstream>
#include <iostream>
#include <queue>
#include <set>
#include <string>
#include <unordered_set>

std::string kYourName = "GABRIEL BALAREZO"; // Don't forget to change this!

/**
 * Takes in a file name and returns a set containing all of the applicant names as a set.
 *
 * @param filename  The name of the file to read.
 *                  Each line of the file will be a single applicant's name.
 * @returns         A set of all applicant names read from the file.
 *
 * @remark Feel free to change the return type of this function (and the function
 * below it) to use a `std::unordered_set` instead. If you do so, make sure
 * to also change the corresponding functions in `utils.h`.
 */
std::unordered_set<std::string> get_applicants(std::string filename) {
  // STUDENT TODO: Implement this function.
    std::ifstream students_file(filename);  
    std::unordered_set<std::string> students; 

    if (!students_file.is_open()) {
        std::cerr << "Could not open file: " << filename << std::endl;
        return students;
    }

    std::string name;
    while (std::getline(students_file, name)) {
        students.insert(name);
    }

    students_file.close();

    return students;
}

/**
 * Takes in a set of student names by reference and returns a queue of names
 * that match the given student name.
 *
 * @param name      The returned queue of names should have the same initials as this name.
 * @param students  The set of student names.
 * @return          A queue containing pointers to each matching name.
 */
std::queue<const std::string*> find_matches(std::string name, std::unordered_set<std::string>& students) {
  // STUDENT TODO: Implement this function.
    std::queue<const std::string*> matches;
    std::string student_name;
    char first_initial = name[0];
    char last_initial = name[name.find(' ') + 1];
    

    for (auto a = students.begin(); a != students.end(); ++a) {
        student_name = *a;
        if (student_name[0] == first_initial && student_name[student_name.find(' ') + 1] == last_initial) {
            matches.push(&student_name);
        }
    }
    return matches;
}

/**
 * Takes in a queue of pointers to possible matches and determines the one true match!
 *
 * You can implement this function however you'd like, but try to do something a bit
 * more complicated than a simple `pop()`.
 *
 * @param matches The queue of possible matches.
 * @return        Your magical one true love.
 *                Will return "NO MATCHES FOUND." if `matches` is empty.
 */
std::string get_match(std::queue<const std::string*>& matches) {
  // STUDENT TODO: Implement this function.
    if (matches.empty()) {
        return "NO MATCHES FOUND.";
    }

    // Create a copy of the queue to avoid modifying the original
    std::queue<const std::string*> matches_copy = matches;

    // Use something more complicated than a simple pop
    while (!matches_copy.empty()) {
        std::string student_name = *matches_copy.front();
        if (student_name == kYourName) {
            return student_name;
        }
        matches_copy.pop();
}
    return "NO MATCHES FOUND.";
}
/* #### Please don't remove this line! #### */
#include "autograder/utils.hpp"
