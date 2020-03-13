
/*
Kelsey Holland
002298547
kholland@chapman.edu
CPSC-350-02
Assignment 2
*/



//Libraries Included Here
#include <iostream>
#include <string>

#include "CreateArray.h"
#include "UserIO.h"
#include "Doughnut.h"
#include "Mirror.h"

using namespace std;


#ifndef  SIMULATION_H
#define  SIMULATION_H
class Simulation{
  public:
    //Constructors
     Simulation();
     Simulation(int genNum , int mode, int fileLength);
     ~Simulation();

     //Methods
     void runClassic();
     void runMirror();
     void runDoughnut();
     void pause();

     void runSimulation();
     void exitSimulation();

//Private variables
  private:
    int genNum;
    int mode;
    int fileLength;


    UserIO *promptData;
    CreateArray *arrayCreate;
    GameOfLife *newGame;

};
#endif
