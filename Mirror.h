
/*
Kelsey Holland
002298547
kholland@chapman.edu
CPSC-350-02
Assignment 2
*/



//Libraries
#include <iostream>
#include <string>


#ifndef  MIRROR_H
#define  MIRROR_H

#include "GameOfLife.h"

using namespace std;

//Mirror inherits from GameOfLife.
class Mirror : public GameOfLife {

  public:
    //Constructors
    Mirror();
    Mirror(int numRows, int numColumns, char **newArray);
    ~Mirror();

    //Other methods not in or different from GameOfLife Base Class.
    void runGame();

    int countNeighborsEdges(int i, int j);
    int countNeighborsCorners(int i, int j);

  private:


};
#endif
