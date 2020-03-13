
/*
Kelsey Holland
002298547
kholland@chapman.edu
CPSC-350-02
Assignment 2
*/

#include "Mirror.h"


//Default Constructor
Mirror::Mirror()
{
  numRows = 0;
  numColumns = 0;
}

//Overloaded Constructor
Mirror::Mirror(int numRows, int numColumns, char **newArray)
{
  this->numRows = numRows;
  this->numColumns = numColumns;
  createGenerationArrays();
  copyArray(newArray);
}

//Destructor
Mirror::~Mirror()
{
  cout <<"Deleting Mirror Class" << endl;
}

//------------------------------------------------------------------
//This creates the next generation given the position of each spot and its
//neighbors. The corners and edges are counted differently for Mirror
void Mirror::runGame(){

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
  //Stabilization is checked and the array is copied.
  isStabilized = checkStabilization();
  copyArray(nextGeneration);
}
//--------------

//This method counts the neighbors if the location is a corner.
//The board is reflected back on itself in Mirror Mode.
//An integer is returned.
int Mirror::countNeighborsCorners(int i, int j)
{
  int neighborCount = 0;
  if ((i == 0) && (j == 0))
  {
    if (currGeneration[i][j+1] == 'X')
      neighborCount += 2;
    if (currGeneration[i+1][j] == 'X')
      neighborCount += 2;
    if (currGeneration[i+1][j+1] == 'X')
      ++ neighborCount;
    if (currGeneration[i][j] == 'X')
      neighborCount += 3;
  }
  else if ((i == 0) && (j == numColumns - 1))
  {
    if (currGeneration[i][j-1] == 'X')
      neighborCount += 2;
    if (currGeneration[i+1][j-1] == 'X')
      ++ neighborCount;
    if (currGeneration[i+1][j] == 'X')
      neighborCount += 1;
    if (currGeneration[i][j] == 'X')
      neighborCount += 3;

  }
  else if ((j == 0) && (i == numRows - 1))
  {
    if (currGeneration[i-1][j] == 'X')
      neighborCount += 2;
    if (currGeneration[i][j+1] == 'X')
      neighborCount += 2;
    if (currGeneration[i-1][j+1] == 'X')
      ++ neighborCount;
    if (currGeneration[i][j] == 'X')
      neighborCount += 3;
  }
  else if ((i == numRows - 1) && (j == numColumns -1 ))
  {
    if (currGeneration[i-1][j-1] == 'X')
      neighborCount += 1;
    if (currGeneration[i-1][j] == 'X')
      neighborCount += 2;
    if (currGeneration[i][j-1] == 'X')
      neighborCount += 2;
    if (currGeneration[i][j] == 'X')
      neighborCount += 3;
  }
  return neighborCount;

}
//--------------
//This method counts the neighbors if the location is an edge.
//The board is reflected back on itself in Mirror Mode.
//An integer for neighborcount is returned.


int Mirror::countNeighborsEdges(int i, int j)
{

    int neighborCount = 0;
    if (i == 0)
    {
      if (currGeneration[i][j-1] == 'X')
        neighborCount += 2;
      if (currGeneration[i][j+1] == 'X')
        neighborCount += 2;
      if (currGeneration[i+1][j-1] == 'X')
        ++ neighborCount;
      if (currGeneration[i+1][j] == 'X')
        ++ neighborCount;
      if (currGeneration[i+1][j+1] == 'X')
        ++ neighborCount;
      if (currGeneration[i][j] == 'X')
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
        neighborCount += 2;
      if (currGeneration[i][j+1] == 'X')
        neighborCount += 2;
      if (currGeneration[i][j] == 'X')
        ++ neighborCount;
    }

    if (j == 0)
    {
      if (currGeneration[i-1][j] == 'X')
        neighborCount += 2;
      if (currGeneration[i-1][j+1] == 'X')
        ++ neighborCount;
      if (currGeneration[i][j+1] == 'X')
        ++ neighborCount;
      if (currGeneration[i+1][j] == 'X')
        neighborCount += 2;
      if (currGeneration[i+1][j+1] == 'X')
        ++ neighborCount;
      if (currGeneration[i][j] == 'X')
        neighborCount += 1;
    }
    else if ( j == numColumns -1 )
    {
      if (currGeneration[i-1][j-1] == 'X')
        ++ neighborCount;
      if (currGeneration[i-1][j] == 'X')
        neighborCount += 2;
      if (currGeneration[i][j-1] == 'X')
        ++ neighborCount;
      if (currGeneration[i+1][j-1] == 'X')
        ++ neighborCount;
      if (currGeneration[i+1][j] == 'X')
        neighborCount += 2;
      if (currGeneration[i][j] == 'X')
        neighborCount += 1;
    }
    return neighborCount;
}
