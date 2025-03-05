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
#include <algorithm>
#include <cmath>
#include <map>

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
std::queue<const std::string*> find_matches(std::string name, std::set<std::string>& students) {
  // STUDENT TODO: Implement this function.
    std::queue<const std::string*> matches;
    std::string initials = name.substr(0, 2);

    for (auto a = students.begin(); a != students.end(); ++a) {
        if (a->substr(0, 2) == initials) {
            matches.push(&(*a));
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
        return "No matches found.";
    }

    // Create a copy of the queue to avoid modifying the original
    std::queue<const std::string*> matches_copy = matches;
    
    // Map to store match scores
    std::map<const std::string*, double> match_scores;
    
    // Helper function to count vowels in a string
    auto count_vowels = [](const std::string& str) {
        int count = 0;
        for (char c : str) {
            char lower_c = std::tolower(c);
            if (lower_c == 'a' || lower_c == 'e' || lower_c == 'i' || 
                lower_c == 'o' || lower_c == 'u') {
                count++;
            }
        }
        return count;
    };
    
    // Helper function to calculate shared characters between two strings
    auto shared_chars = [](const std::string& str1, const std::string& str2) {
        std::map<char, int> char_count;
        for (char c : str1) {
            char_count[std::tolower(c)]++;
        }
        
        int shared = 0;
        for (char c : str2) {
            char lower_c = std::tolower(c);
            if (char_count[lower_c] > 0) {
                shared++;
                char_count[lower_c]--;
            }
        }
        return shared;
    };
    
    // Calculate match scores for each potential match
    while (!matches_copy.empty()) {
        const std::string* match_ptr = matches_copy.front();
        const std::string& match_name = *match_ptr;
        matches_copy.pop();
        
        // Calculate different metrics for matching
        double name_length_score = 10.0 / (1.0 + std::abs(match_name.length() - kYourName.length()));
        double shared_chars_score = shared_chars(match_name, kYourName) / static_cast<double>(kYourName.length());
        
        int match_vowels = count_vowels(match_name);
        int user_vowels = count_vowels(kYourName);
        double vowel_ratio_match = static_cast<double>(match_vowels) / match_name.length();
        double vowel_ratio_user = static_cast<double>(user_vowels) / kYourName.length();
        double vowel_compatibility = 1.0 / (1.0 + std::abs(vowel_ratio_match - vowel_ratio_user));
        
        // Calculate final score (weighted sum of all metrics)
        double final_score = (0.4 * name_length_score) + 
                             (0.4 * shared_chars_score) + 
                             (0.2 * vowel_compatibility);
        
        match_scores[match_ptr] = final_score;
    }
    
    // Find the match with the highest score
    const std::string* best_match = nullptr;
    double highest_score = -1.0;
    
    for (const auto& pair : match_scores) {
        if (pair.second > highest_score) {
            highest_score = pair.second;
            best_match = pair.first;
        }
    }
    
    // Return the best match
    return *best_match;
}

/* #### Please don't remove this line! #### */
#include "autograder/utils.hpp"

