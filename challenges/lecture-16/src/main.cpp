
#include "../include/CLI11.hpp"
#include<iostream>
#include<string>
#include<fstream>
#include<map>
#include<sstream>
#include<vector>
#include<atomic>
#include "../include/barkeep.h"


// This function reads the retail data from the xlsl file
std::vector<std::string> parse_retail_line(const std::string& line) {
    std::stringstream ss(line);
    std::vector<std::string> tokens;
    std::string token;

    while (std::getline(ss, token, ',')) {
        tokens.push_back(token);
    }
    return tokens;
}


int main(int argc, char** argv) {
    CLI::App app{"Retail Data Analytics"};

    std::string file_path;
    std::string country;
    bool only_uk = false;

    // Here I define CLI arguments
    app.add_option("-f, --file", file_path, "Path to the retail data file")->required();
    app.add_option("-c, --country", country, "Filter by country for transaction count");
    app.add_flag("--only-uk", only_uk, "Only UK transactions")->default_val(false);

    CLI11_PARSE(app, argc, argv);

    // Count the total lines to implement the progress bar
    std::ifstream count_file(file_path);
    std::string tmp;
    int total_lines = -1; // Start at -1 to not count the header
    while (std::getline(count_file, tmp)) total_lines++;
    count_file.close();


    std::ifstream file(file_path);
    if (!file.is_open()) {
        std::cerr << "Error opening file: " << file_path << std::endl;
        return 1;
    }

    std::map<std::string, int> transaction_counts;
    double total_transactions = 0.0;

    std::string line;
    std::getline(file, line); // Skip header line

    // Initialize the progress bar
    std::atomic<int> progress = 0;

    barkeep::ProgressBarConfig<int> config;
    config.total = total_lines;
    config.message = "Processing retail data";
    config.style = barkeep::ProgressBarStyle::Block;

    auto bar = barkeep::ProgressBar(&progress, config);


    while (std::getline(file, line)) {
        // Update the progress bar
        progress++;

        auto tokens = parse_retail_line(line);
        // There must be 8 tokens in the line according to the repo
        if (tokens.size() < 8) continue;

        std::string country = tokens[7]; // In the repo, the country is in the 8th column
        std::string quantity_str = tokens[3]; // In the repo, the quantity is in the 4th column
        std::string price = tokens[4]; // In the repo, the price is in the 5th column


        try {
            int quantity = std::stoi(quantity_str);
            double price_value = std::stod(price);
            double total_value = quantity * price_value;

            // Transaction count for the country - Analysis 1
            transaction_counts[country]++;

            // Total transactions amount - Analysis 2
            if (!only_uk || country == "United Kingdom") {
                total_transactions += total_value;
            }

        } catch (...) {
            continue; // Skip lines with invalid data
        }

        }

        // Finalize the progress bar
        bar->done();

        // Output Analysis 1
        if (!country.empty()) {
            std::cout << "Transactions in " << country << ": " 
            << transaction_counts[country] << std::endl;
        } else {
            std::cout << "Transactions per country: \n";
            for (const auto& [country, count] : transaction_counts) {
                std::cout << country << ": " << count << std::endl;
            }
        }

        // Output Analysis 2
        std::cout << "\nTotal transactions amount ";
        if (only_uk) std::cout << "for UK: ";
        else std::cout << "for all countries: ";
        std::cout << total_transactions << std::endl;

        return 0;
    }

