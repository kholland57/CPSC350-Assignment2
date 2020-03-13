
/*
Kelsey Holland
002298547
kholland@chapman.edu
CPSC-350-02
Assignment 2
*/

//Main Method for Game of Life Simulation.

//Libraries included here.
#include "Simulation.h"

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main(int argc, char **argv)
{
  //Random is called.
  srand(time(0));

//Simulation class is created to run the game.
  Simulation *arrayGame = new Simulation();
  arrayGame->runSimulation();
  delete arrayGame;



  return 0;
}
