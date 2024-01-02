#ifndef USERDATA_H
#define USERDATA_H

#include <string>
#include <vector>

class UserData{
  public: 
    UserData(std::string name, int score, int size);

    // getters and setters
    std::string name() const {return _name;}
    int score() const {return _score;}
    int size() const {return _size;}

    void name(std::string name){ _name = name;}
    void score(int score){_score = score;}
    void size(int size){_size = size;}



    int getCurrrentRank(std::vector<UserData> leaderboard);
    void writeDataToFile(const std::string fileName);
    std::vector<UserData> loadDataFromFile(const std::string& filePath);
    static bool compareRankings(const UserData& first, const UserData& second);



private :
  std::string _name;
  int _score;
  int _size;
};

# endif