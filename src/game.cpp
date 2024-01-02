
#include <random>
#include "game.h"
#include "controller.h"
#include <iostream>
#include <chrono>
#include <memory>
#include <mutex>
#include <thread>
#include <future>
#include "SDL.h"

std::mutex Game::_mtx;

Game::Game(std::size_t grid_width, std::size_t grid_height)
    : snake(grid_width, grid_height),
      engine(dev()),
      random_w(0, static_cast<int>(grid_width - 1)),
      random_h(0, static_cast<int>(grid_height - 1)) {
  PlaceFood();
}

void Game::Run(Controller const &controller, Renderer &renderer,
               std::size_t target_frame_duration) {
  Uint32 title_timestamp = SDL_GetTicks();
  Uint32 frame_start;
  Uint32 frame_end;
  Uint32 frame_duration;
  int frame_count = 0;
  bool running = true;

  while (running) {
    frame_start = SDL_GetTicks();

    // Input, Update, Render - the main game loop.
    controller.HandleInput(running, snake, *this);
    Update();
    renderer.Render(snake, food, this->_poisoned);

    frame_end = SDL_GetTicks();

    // Keep track of how long each loop through the input/update/render cycle
    // takes.
    frame_count++;
    frame_duration = frame_end - frame_start;

    // After every second, update the window title.
    if (frame_end - title_timestamp >= 1000) {
      renderer.UpdateWindowTitle(score, frame_count);
      frame_count = 0;
      title_timestamp = frame_end;
    }

    // If the time for this frame is too small (i.e. frame_duration is
    // smaller than the target ms_per_frame), delay the loop to
    // achieve the correct frame rate.
    if (frame_duration < target_frame_duration && snake.alive) {
      SDL_Delay(target_frame_duration - frame_duration);
    }

    if (!snake.alive){
      std::cout << "You lost, game will stop..." << std::endl;
      SDL_Delay(3000);
      running = false;
    }
  }
}

void Game::PlaceFood() {
  int x, y;
  while (true) {
    x = random_w(engine);
    y = random_h(engine);
    // Check that the location is not occupied by a snake item before placing
    // food.
    if (!snake.SnakeCell(x, y)) {
      food.x = x;
      food.y = y;
      return;
    }
  }
}

// After snake eats poisoned fruit this thread will switch the state of the snake back
void Game::PoisonTimer(bool *poisoned){
  std::unique_lock<std::mutex> lck(_mtx);
  std::cout << "Poison activated" << std::endl;
  lck.unlock();
  std::this_thread::sleep_for(std::chrono::seconds(10));
  lck.lock();
  std::cout << "Poison deactivted" << std::endl;
  *poisoned = false;
}

void Game::Update() {
  if (!snake.alive || !this->_isRunning) return;

  snake.Update();

  int new_x = static_cast<int>(snake.head_x);
  int new_y = static_cast<int>(snake.head_y);

  // generate random bumber for poisoned food
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_real_distribution<> dis(0.0, 1.0);

  // Check if there's food over here
  if (food.x == new_x && food.y == new_y) {
    score++;
    PlaceFood();
    // Grow snake and increase speed.
    snake.GrowBody();

    if (dis(gen) <= 0.1){
      // reverse arrow <-> movement relationship of snake
      _poisoned = true;
      // resolve 10 seconds later
      std::thread poisionThread([this](){
        this->PoisonTimer(&_poisoned);
      });
      // prevent thread to go out of scope by detatching it
      poisionThread.detach();
    } 
    snake.speed += 0.02;
  }
}

void Game::TogglePause(){
  this->_isRunning = !this->_isRunning;
  if (this->_isRunning){
    std::cout << "Game is resumed." << std::endl;
  }else{
    std::cout << "Game is paused." <<  std::endl;
  }

}

int Game::GetScore() const { return score; }
int Game::GetSize() const { return snake.size; }
int Game::poisoned() const {return _poisoned;}