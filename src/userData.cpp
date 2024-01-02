#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <sstream>
#include <string>

#include "userData.h"

UserData::UserData(std::string name, int score, int size) : _name(name), _score(score), _size(size) {}

bool UserData::compareRankings(const UserData& first, const UserData& second){
    return first.score() > second.score();
}

// Function to load previous runs
std::vector<UserData> UserData::loadDataFromFile(const std::string& filePath) {
    // crete new rankings.txt file if none exists yet
    std::ifstream fileCheck(filePath);
    if (!fileCheck){
        std::ofstream fileCreate(filePath);
        std::cout << "Could not find previous runs, creating new leaderboard..." << std::endl;    
    }
    // read data from file
    std::ifstream file(filePath);
    std::vector<UserData> leaderboard;
    if (file) {
        std::string line;
        while (std::getline(file, line)) {
            std::istringstream iss(line);
            std::string usrName;
            int score;
            int size;
            if (iss >> usrName >> score >> size) {
                UserData usrData(usrName, size, score); 
                leaderboard.push_back(usrData);
            } else {
                std::cerr << "Error reading line: " << line << std::endl;
            }
        }
        file.close();
    }else{
        std::cerr << "Error opening file: " << filePath << std::endl;
    }
    // sort vector accordingly
    std::sort(leaderboard.begin(), leaderboard.end(), this->compareRankings);
    return leaderboard;
}


void UserData::writeDataToFile(const std::string fileName) {
    std::ofstream file(fileName, std::ios::app); // Open in append mode
    if (file) {
        // write data from game to file
        file << this->_name << " " << this->_score << " " << this->_size << "\n";
        file.close();
    } else {
        std::cerr << "Error opening file for writing: " << fileName << std::endl;
    }
}

int UserData::getCurrrentRank(std::vector<UserData> leaderboard){
    if (leaderboard.empty()){
        return 1;
    }
    std::vector<UserData>::iterator iter = leaderboard.begin();
    for (iter; iter<leaderboard.end(); iter++){
        if (iter->score() <= this->_score){return std::distance(leaderboard.begin(), iter) + 1;}
    }
    return leaderboard.size() + 1;
}