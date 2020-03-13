

/*
Kelsey Holland
002298547
kholland@chapman.edu
CPSC-350-02
Assignment 2
*/


#include "Doughnut.h"


//Default Constructor
Doughnut::Doughnut()
{
  numRows = 0;
  numColumns = 0;
}

//Overloaded Constructor
Doughnut::Doughnut(int numRows, int numColumns, char **newArray)
{
  this->numRows = numRows;
  this->numColumns = numColumns;
  createGenerationArrays();
  copyArray(newArray);
}

//Destructor
Doughnut::~Doughnut()
{
  cout <<"Deleting Donut" << endl;

}
//----------------------------------------------------------------------------
//This creates the next generation given the position of each spot and its
//neighbors. The corners and edges are counted differently for Doughnut

void Doughnut::runGame(){

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



//This method counts the neighbors if the location is a corner.
//In Doughnut mode, the corners and edges are wrapped around themselves.
//An integer is returned.

int Doughnut::countNeighborsCorners(int i, int j)
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

    if (currGeneration[i][numColumns - 1] == 'X')
      ++ neighborCount;
    if (currGeneration[i+1][numColumns - 1] == 'X')
      ++ neighborCount;
    if (currGeneration[numRows - 1][numColumns - 1] == 'X')
      ++ neighborCount;

    if (currGeneration[numRows - 1][j] == 'X')
      ++ neighborCount;
    if (currGeneration[numRows - 1][j+1] == 'X')
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

    if (currGeneration[i][0] == 'X')
      ++ neighborCount;
    if (currGeneration[i+1][0] == 'X')
      ++ neighborCount;
    if (currGeneration[numRows - 1][0] == 'X')
      ++ neighborCount;

    if (currGeneration[numRows - 1][j - 1] == 'X')
      ++ neighborCount;
    if (currGeneration[numRows - 1][j] == 'X')
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


    if (currGeneration[0][j] == 'X')
      ++ neighborCount;
    if (currGeneration[0][j+1] == 'X')
      ++ neighborCount;
    if (currGeneration[0][numColumns - 1] == 'X')
      ++ neighborCount;

    if (currGeneration[i-1][numColumns -1] == 'X')
      ++ neighborCount;
    if (currGeneration[i][numColumns - 1] == 'X')
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


    if (currGeneration[0][0] == 'X')
      ++ neighborCount;
    if (currGeneration[0][j-1] == 'X')
      ++ neighborCount;
    if (currGeneration[0][numColumns - 1] == 'X')
      ++ neighborCount;

    if (currGeneration[i-1][0] == 'X')
        ++ neighborCount;
    if (currGeneration[i][0] == 'X')
        ++ neighborCount;

  }
  return neighborCount;

}


//This method counts the neighbors if the location is an edge.

//An integer for neighborcount is returned.

int Doughnut::countNeighborsEdges(int i, int j)
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
      if (currGeneration[numRows-1][j-1] == 'X')
        ++ neighborCount;
      if (currGeneration[numRows-1][j] == 'X')
        ++ neighborCount;
      if (currGeneration[numRows-1][j+1] == 'X')
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
      if (currGeneration[0][j+1] == 'X')
        ++ neighborCount;
      if (currGeneration[0][j-1] == 'X')
        ++ neighborCount;
      if (currGeneration[0][j] == 'X')
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
      if (currGeneration[i-1][numColumns-1] == 'X')
        ++ neighborCount;
      if (currGeneration[i][numColumns-1] == 'X')
        ++ neighborCount;
      if (currGeneration[i+1][numColumns-1] == 'X')
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
      if (currGeneration[i-1][0] == 'X')
        ++ neighborCount;
      if (currGeneration[i][0] == 'X')
        ++ neighborCount;
      if (currGeneration[i+1][0] == 'X')
        ++ neighborCount;
    }

    return neighborCount;
}
