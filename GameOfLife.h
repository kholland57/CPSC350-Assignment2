

/*
Kelsey Holland
002298547
kholland@chapman.edu
CPSC-350-02
Assignment 2
*/


//Base Class for Game of Life Modes, also is Classic Mode.

//Libraries
#include <iostream>
#include <string>

using namespace std;

#ifndef  GAMEOFLIFE_H
#define  GAMEOFLIFE_H
class GameOfLife {
  public:
    //Constructors
    GameOfLife();
    GameOfLife(int numRows, int numColumns, char **newArray);
    ~GameOfLife();

    //Other Methods
    void copyArray(char **newArray);
    void createGenerationArrays();

    void runGame();
    int countNeighbors(int i, int j);
    int countNeighborsEdges(int i, int j);
    int countNeighborsCorners(int i, int j);

    void updateNextGeneration(int i, int j, int neighborCount);

    void print();
    string printString();

    bool checkLife();
    bool checkStabilization();

    //Mutators
    void setCurrGeneration(char ** newArray);
    void setNextGeneration(char ** newArray);

    //Accessors
    char ** getCurrGeneration();
    char ** getNextGeneration();
    bool getStabilization();

//Protected Variables that can only be used by this class and
//inherited classes.

  protected:

    char **currGeneration;
    char **nextGeneration;
    char **prevGeneration;

    int numStabilize;
    int numStabilize2;
    bool isStabilized;


    int numGeneration;
    int numRows;
    int numColumns;
};
#endif
