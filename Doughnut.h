

/*
Kelsey Holland
002298547
kholland@chapman.edu
CPSC-350-02
Assignment 2
*/


#include <iostream>
#include <string>


#include "GameOfLife.h"



#ifndef  DOUGHNUT_H
#define  DOUGHNUT_H
using namespace std;

//Doughnut mode is inherited from the base class GameOfLife.
class Doughnut : public GameOfLife {


  public:
    //Constructors
    Doughnut();
    Doughnut(int numRows, int numColumns, char **newArray);
    ~Doughnut();

    //Methods that are different from GameOfLife
    void runGame();

    int countNeighborsEdges(int i, int j);
    int countNeighborsCorners(int i, int j);

  private:


};
#endif
