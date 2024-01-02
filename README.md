# CPPND: Capstone Snake Game Example

This is my implementation of the [Udacity C++ Nanodegree Program](https://www.udacity.com/course/c-plus-plus-nanodegree--nd213) snake capstone project. The code for this repo was inspired by [this](https://codereview.stackexchange.com/questions/212296/snake-game-in-c-with-sdl) excellent StackOverflow post and set of responses.

<img src="snake_game.gif"/>

The Capstone Project gives you a chance to integrate what you've learned throughout this program. This project will become an important part of your portfolio to share with current and future colleagues and employers.

In this project, you can build your own C++ application or extend this Snake game, following the principles you have learned throughout this Nanodegree Program. This project will demonstrate that you can independently create applications using a wide range of C++ features.

## Dependencies for Running Locally
* cmake >= 3.7
  * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1 (Linux, Mac), 3.81 (Windows)
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* SDL2 >= 2.0
  * All installation instructions can be found [here](https://wiki.libsdl.org/Installation)
  >Note that for Linux, an `apt` or `apt-get` installation is preferred to building from source. 
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools](https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)

## Basic Build Instructions

1. Clone this repo.
2. Make a build directory in the top level directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./SnakeGame`.


## CC Attribution-ShareAlike 4.0 International


Shield: [![CC BY-SA 4.0][cc-by-sa-shield]][cc-by-sa]

This work is licensed under a
[Creative Commons Attribution-ShareAlike 4.0 International License][cc-by-sa].

[![CC BY-SA 4.0][cc-by-sa-image]][cc-by-sa]

[cc-by-sa]: http://creativecommons.org/licenses/by-sa/4.0/
[cc-by-sa-image]: https://licensebuttons.net/l/by-sa/4.0/88x31.png
[cc-by-sa-shield]: https://img.shields.io/badge/License-CC%20BY--SA%204.0-lightgrey.svg

## Poject Rubic 
### Loops / Functions / IO
Success Criteria | Example
--- | ---
The project reads data from file and process the data, or the program write data to file | [UserData](https://github.com/ptr-br/CppND-Capstone-Snake-Game/blob/master/src/userData.h#L7) class [reads](https://github.com/ptr-br/CppND-Capstone-Snake-Game/blob/d45726c99845ae2b09db8970da6cdb9223a8e9b7/src/userData.cpp#L17) previous runs from a file and [stores](https://github.com/ptr-br/CppND-Capstone-Snake-Game/blob/master/src/userData.cpp#L51) statistics from current run.
The project accepts user input and processes the input. | In [main.cpp](https://github.com/ptr-br/CppND-Capstone-Snake-Game/blob/master/src/main.cpp#L23) the user is requested to give a user name before playing.

### Object Oriented Programming
Success Criteria | Example
 --- | ---
 One or more classes are added to the project with appropriate access specifiers for class members. | [UserData](https://github.com/ptr-br/CppND-Capstone-Snake-Game/blob/master/src/userData.h#L7) class is added to the snake game.
 Class constructors utilize member initialization lists. | Constructor of [UserData](https://github.com/ptr-br/CppND-Capstone-Snake-Game/blob/d45726c99845ae2b09db8970da6cdb9223a8e9b7/src/userData.cpp#L10C22-L10C22) is using an initialization list.
 Classes abstract implementation details from their interfaces.| Function names are self-describing or comments are added.

 ### Memory Mangement 
 Success Criteria | Example
 --- | ---
 The project makes use of references in function declarations. | Examples of pass-by-reference [here](https://github.com/ptr-br/CppND-Capstone-Snake-Game/blob/d45726c99845ae2b09db8970da6cdb9223a8e9b7/src/userData.cpp#L12) and [here](https://github.com/ptr-br/CppND-Capstone-Snake-Game/blob/d45726c99845ae2b09db8970da6cdb9223a8e9b7/src/userData.cpp#L17C63-L17C77)
 The project uses destructors appropriately. | [Destructor](https://github.com/ptr-br/CppND-Capstone-Snake-Game/blob/d45726c99845ae2b09db8970da6cdb9223a8e9b7/src/renderer.cpp#L37) of Renderer class is modified and [Run member function](https://github.com/ptr-br/CppND-Capstone-Snake-Game/blob/d45726c99845ae2b09db8970da6cdb9223a8e9b7/src/game.cpp#L61) is adapted to properly close game after losing.
 The project uses smart pointers instead of raw pointers. | [Renderer](https://github.com/ptr-br/CppND-Capstone-Snake-Game/blob/d45726c99845ae2b09db8970da6cdb9223a8e9b7/src/main.cpp#L28) and [Controller](https://github.com/ptr-br/CppND-Capstone-Snake-Game/blob/d45726c99845ae2b09db8970da6cdb9223a8e9b7/src/main.cpp#L29) use smart pointers.

### Concurrency 
 Success Criteria | Example
 --- | ---
 The project uses multithreading. | There is a 10% chance that the fruit is poisoned. If so, a new [thread](https://github.com/ptr-br/CppND-Capstone-Snake-Game/blob/d45726c99845ae2b09db8970da6cdb9223a8e9b7/src/game.cpp#L119) is started and will switch the arrow directions.
 A mutex or lock is used in the project. | A [unique lock](https://github.com/ptr-br/CppND-Capstone-Snake-Game/blob/d45726c99845ae2b09db8970da6cdb9223a8e9b7/src/game.cpp#L86) is used to protect console output of the thread.
