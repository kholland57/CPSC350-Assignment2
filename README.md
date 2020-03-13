# CPSC350-Assignment2

# Assignment2

Name : Kelsey Holland
StudentID : 002298547
Email : kholland@chapman.edu
CPSC-350-02
Assignment 2

List of Source Files:
  1) CreateArray.cpp
  2) CreateArray.h
  3) Doughnut.cpp
  4) Doughnut.h
  5) GameOfLife.cpp
  6) GameOfLife.h
  7) main.cpp
  8) Mirror.cpp
  9) Mirror.h
  10) Simulation.cpp
  11) Simulation.h
  12) UserIO.cpp
  13) UserIO.h
  14) Makefile
  15) README.md

References:
- Zybooks
- https://stackoverflow.com/questions/13006250/proper-way-to-pass-dynamic-arrays-to-other-functions
- https://stackoverflow.com/questions/11747954/c-inheritance-in-separate-files-using-include-and-inclusion-guards
- For 2D arrays : https://www.youtube.com/watch?v=b2NPj64QuRk
- For sleep : https://stackoverflow.com/questions/4184468/sleep-for-milliseconds
- For pressing enter: https://stackoverflow.com/questions/16381198/c-breaking-out-of-loop-by-key-press-at-any-time
- https://stackoverflow.com/questions/18626136/c-press-enter-to-terminate-program
- Error checking for cin.fail() :  https://stackoverflow.com/questions/18728754/checking-cin-input-stream-produces-an-integer

Comments/Errors:
- To exit the simulation from the pause and the enter modes, you have to
input 'enter' twice.

- For the 'enter to continue' option, it prints the 0 and 1st generation
together for some reason, but every generation prints one at a time after that.

- If the user enters an invalid file input the program will exit.

- If the user enters incorrect cin entries, then it is replaced by a
default value so the program can continue without crashing.


To run:
1 - make All
2 - ./assignment2.exe
