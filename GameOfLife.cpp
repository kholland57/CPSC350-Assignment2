

/*
Kelsey Holland
002298547
kholland@chapman.edu
CPSC-350-02
Assignment 2
*/


#include "GameOfLife.h"

//Defualt Constructor
GameOfLife::GameOfLife()
{
  numRows = 0;
  numColumns = 0;
  numStabilize = 0;
  numStabilize2 = 0;
  isStabilized = false;
}

//Overloaded Constructor
GameOfLife::GameOfLife(int numRows, int numColumns, char **newArray)
{
  this->numRows = numRows;
  this->numColumns = numColumns;
  numStabilize = 0;
  numStabilize2 = 0;
  createGenerationArrays();
  copyArray(newArray);
  isStabilized = false;
}


//Destructor that loops through the generation arrays and deletes the arrays
//or pointers
GameOfLife::~GameOfLife()
{
  cout << "Deleting GameOfLife" << endl;
  if (currGeneration != NULL){
    for (int i = 0; i < numRows; ++i)
    {
        delete [] currGeneration[i];
    }
    delete []  currGeneration;
  }

  if (nextGeneration != NULL){
    for (int i = 0; i < numRows; ++i)
    {
      delete [] nextGeneration[i];
    }
    delete [] nextGeneration;
  }
  else
  {
    cout <<"Array is null." << endl;
  }
}

//-------------------------------------------------------------------------------
//Other Methods

//This initializes each array and sets each row as an array of pointers
//Each dynamic 2D array is initialized, and filled with empty spots.

void GameOfLife::createGenerationArrays()
{
  currGeneration  = new char*[numRows];
  nextGeneration = new char*[numRows];
  prevGeneration = new char*[numRows];
  for (int i = 0 ; i < numRows; ++i)
  {
    currGeneration[i] = new char [numColumns];
    nextGeneration[i] = new char [numColumns];
    prevGeneration[i] = new char [numColumns];
  }
  for (int i = 0 ; i < numRows; ++i)
  {
    for (int j = 0; j < numColumns; ++j)
    {
      currGeneration[i][j] = '-';
      nextGeneration[i][j] = '-';
      prevGeneration[i][j] = '-';
    }
  }
}

//----------

//This method takes the prevGeneration arrays and copies
//each value over from currGeneration.
//currGeneration is then copied over to the newArray just made
void GameOfLife::copyArray(char **newArray)
{
  for (int i = 0 ; i < numRows; ++i)
  {
    for (int j = 0; j < numColumns; ++j)
    {
      prevGeneration[i][j] = currGeneration[i][j];
    }
  }
  for (int i = 0 ; i < numRows; ++i)
  {
    for (int j = 0; j < numColumns; ++j)
    {
      currGeneration[i][j] = newArray[i][j];
    }
  }
}


//---------------------------------------
//This runs each simulation cycle and updates the next generation array
//depending on the number of each neighbors by each spot .
void GameOfLife::runGame(){

  int neighbors = 0;
  for (int i = 0 ; i < numRows; ++i)
  {
    for (int j = 0; j < numColumns; ++j)
    {

      if ((i > 0) && (j > 0) && (i < numRows - 1) && (j < numColumns - 1))
      {
        neighbors = countNeighbors(i,j);
      }
      else if (((i == 0) || (i == (numRows - 1))) && ((j == 0) || (j == (numColumns - 1))))
      {
        neighbors = countNeighborsCorners(i,j);
      }

      else if (((i == 0) || (i == (numRows - 1))) || ((j == 0) || (j == (numColumns - 1))))
      {
        neighbors = countNeighborsEdges(i,j);
      }
      updateNextGeneration(i,j,neighbors);
    }
  }
  isStabilized = checkStabilization();
  copyArray(nextGeneration);
}
//----------


//This counts the number of neighbors for a basic position in the middle.
//An int is returned.
int GameOfLife::countNeighbors(int i, int j)
{
  int neighborCount = 0;
  if ((i > 0) && (j > 0))
  {
    if (currGeneration[i-1][j-1] == 'X')
      ++ neighborCount;
    if (currGeneration[i-1][j] == 'X')
      ++ neighborCount;
    if (currGeneration[i-1][j+1] == 'X')
      ++ neighborCount;
    if (currGeneration[i][j-1] == 'X')
      ++ neighborCount;
    if (currGeneration[i][j+1] == 'X')
      ++ neighborCount;
    if (currGeneration[i+1][j-1] == 'X')
      ++ neighborCount;
    if (currGeneration[i+1][j] == 'X')
      ++ neighborCount;
    if (currGeneration[i+1][j+1] == 'X')
      ++ neighborCount;
  }
  return neighborCount;
}
//----------

//This counts the number of neighbors for spots on the edge, since in classic
//mode they have less neighbors.
int GameOfLife::countNeighborsEdges(int i, int j)
{
  int neighborCount = 0;
  if (i == 0)
  {
    if (currGeneration[i][j-1] == 'X')
      ++ neighborCount;
    if (currGeneration[i][j+1] == 'X')
      ++ neighborCount;
    if (currGeneration[i+1][j-1] == 'X')
      ++ neighborCount;
    if (currGeneration[i+1][j] == 'X')
      ++ neighborCount;
    if (currGeneration[i+1][j+1] == 'X')
      ++ neighborCount;
  }
  else if (i == numRows - 1)
  {
    if (currGeneration[i-1][j-1] == 'X')
      ++ neighborCount;
    if (currGeneration[i-1][j] == 'X')
      ++ neighborCount;
    if (currGeneration[i-1][j+1] == 'X')
      ++ neighborCount;
    if (currGeneration[i][j-1] == 'X')
      ++ neighborCount;
    if (currGeneration[i][j+1] == 'X')
      ++ neighborCount;
  }

  if (j == 0)
  {
    if (currGeneration[i-1][j] == 'X')
      ++ neighborCount;
    if (currGeneration[i-1][j+1] == 'X')
      ++ neighborCount;
    if (currGeneration[i][j+1] == 'X')
      ++ neighborCount;
    if (currGeneration[i+1][j] == 'X')
      ++ neighborCount;
    if (currGeneration[i+1][j+1] == 'X')
      ++ neighborCount;
  }
  else if ( j == numColumns -1 )
  {
    if (currGeneration[i-1][j-1] == 'X')
      ++ neighborCount;
    if (currGeneration[i-1][j] == 'X')
      ++ neighborCount;
    if (currGeneration[i][j-1] == 'X')
      ++ neighborCount;
    if (currGeneration[i+1][j-1] == 'X')
      ++ neighborCount;
    if (currGeneration[i+1][j] == 'X')
      ++ neighborCount;
  }
  return neighborCount;
}
//----------


//This counts the number of neighbors for spots on the corners, since in classic
//mode they have less neighbors.
int GameOfLife::countNeighborsCorners(int i, int j)
{
  int neighborCount = 0;
  if ((i == 0) && (j == 0))
  {
    if (currGeneration[i][j+1] == 'X')
      ++ neighborCount;
    if (currGeneration[i+1][j] == 'X')
      ++ neighborCount;
    if (currGeneration[i+1][j+1] == 'X')
      ++ neighborCount;
  }
  else if ((i == 0) && (j == numColumns - 1))
  {
    if (currGeneration[i][j-1] == 'X')
      ++ neighborCount;
    if (currGeneration[i+1][j-1] == 'X')
      ++ neighborCount;
    if (currGeneration[i+1][j] == 'X')
      ++ neighborCount;
  }
  else if ((j == 0) && (i == numRows - 1))
  {
    if (currGeneration[i-1][j] == 'X')
      ++ neighborCount;
    if (currGeneration[i][j+1] == 'X')
      ++ neighborCount;
    if (currGeneration[i-1][j+1] == 'X')
      ++ neighborCount;
  }
  else if ((i == numRows - 1) && (j == numColumns -1 ))
  {
    if (currGeneration[i-1][j-1] == 'X')
      ++ neighborCount;
    if (currGeneration[i-1][j] == 'X')
      ++ neighborCount;
    if (currGeneration[i][j-1] == 'X')
      ++ neighborCount;
  }
  return neighborCount;
}
//----------


//This updates each spot depending on how many neighbors they have.
void GameOfLife::updateNextGeneration(int i, int j, int neighborCount)
{
  if (neighborCount <= 1)
  {
    nextGeneration[i][j] = '-';
  }
  if (neighborCount == 2)
  {
    nextGeneration[i][j] = currGeneration[i][j];
  }
  if (neighborCount == 3)
  {
    nextGeneration[i][j] = 'X';
  }
  if (neighborCount >= 4)
  {
    nextGeneration[i][j] = '-';
  }
}
//----------



//This checks if there are any bacteria left alive by looping
//through the board.
bool GameOfLife::checkLife()
{
  for (int i = 0 ; i < numRows; ++i)
  {
    for (int j = 0; j < numColumns; ++j)
    {
      if (currGeneration[i][j] == 'X')
      {
        return true;
      }
    }
  }
  return false;

}
//----------


//This checks for stabilization in the simulation by comparing
//the current generation array to the next generation,
//and the previous generation to the next generation.
//If the arrays are identical for more than 5 generations,
//true is returned showing it is stabilized.

bool GameOfLife::checkStabilization()
{
  bool a = true;
  bool b = true;
  for (int i = 0 ; i < numRows; ++i)
  {
    for (int j = 0; j < numColumns; ++j)
    {
      if (currGeneration[i][j] != nextGeneration[i][j])
      {
        a = false;
      }

      if (prevGeneration[i][j] != nextGeneration[i][j]){
        b = false;
      }
    }
  }

  if ( a == true)
  {
    //numStabilize counts the number of times the arrays are the same
    numStabilize ++;
  }
  if (b == true)
  {
    numStabilize2 ++;
  }

  if ((numStabilize >= 5) || (numStabilize2 >= 5))
  {
    cout <<"Stabilization" << endl;
    return true;
  }
  else
  {
    return false;
  }
}

//This takes the currGeneration array and turns it into a string and returns it
string GameOfLife::printString()
{
  string board = "";
  for (int i = 0; i < numRows; i++)
  {
    for (int j =0; j < numColumns; j++)
    {
      board += currGeneration[i][j];
    }
    board += "\n";
  }
  return board;
}



//This is the same as the other print method but prints it out one
//element at a time and does not return a string.

void GameOfLife::print()
{
  for (int i = 0; i < numRows; i++)
  {
    for (int j =0; j < numColumns; j++)
    {
      cout << nextGeneration[i][j];
    }
    cout << endl;
  }
}

//---------------------------------------
//Mutators
void GameOfLife::setCurrGeneration(char ** newArray)
{
  currGeneration = newArray;

}
void GameOfLife::setNextGeneration(char ** newArray)
{
  nextGeneration = newArray;
}

//Accessors
char ** GameOfLife::getCurrGeneration()
{
  return currGeneration;
}

char ** GameOfLife::getNextGeneration(){
  return nextGeneration;
}


bool GameOfLife::getStabilization(){
  return isStabilized;
}
