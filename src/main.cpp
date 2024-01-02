#include <iostream>
#include <string>
#include <memory>

#include "controller.h"
#include "game.h"
#include "renderer.h"
#include "userData.h"

int main() {
  constexpr std::size_t kFramesPerSecond{60};
  constexpr std::size_t kMsPerFrame{1000 / kFramesPerSecond};
  constexpr std::size_t kScreenWidth{640};
  constexpr std::size_t kScreenHeight{640};
  constexpr std::size_t kGridWidth{32};
  constexpr std::size_t kGridHeight{32};

  const std::string rankingsFilePath = "./rankings.txt";
  std::string userName;
  

  std::cout << "Enter Name of Player: " << std::endl;
  std::cin >>  userName;
  std::cout << "Hello " << userName << " let's start playing by Pressing P." << std::endl;


  std::unique_ptr<Renderer> renderer = std::make_unique<Renderer>(kScreenWidth, kScreenHeight, kGridWidth, kGridHeight);
  std::unique_ptr<Controller> controller = std::make_unique<Controller>();
  Game game(kGridWidth, kGridHeight);
  game.Run(*controller, *renderer, kMsPerFrame);

  // init new user to display and safe records mad
  UserData currentUserData(userName, game.GetScore(), game.GetSize());

  std::cout << "Score: " << currentUserData.score() << "\n";
  std::cout << "Size: " << currentUserData.size() << "\n";

  // Get data from previous games
  std::vector<UserData> leaderboard = currentUserData.loadDataFromFile(rankingsFilePath);
  int rank = currentUserData.getCurrrentRank(leaderboard);

  // Tell user his place in the rank
  if (rank == 1){
    std::cout << "Congratulations, you just created a new record! There are "  << leaderboard.size() << " tracked runs you just beat!" << std::endl;
  }else{
    std::cout <<"You run was ranked on place " << rank << " of the leaderboard. Currently " << leaderboard[0].name() << " is leading with a score of " << leaderboard[0].score() << "." <<std::endl;
  }

  // write current score to database for comparison in future
  currentUserData.writeDataToFile(rankingsFilePath);

  return 0;
}