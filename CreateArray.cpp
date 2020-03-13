
/*
Kelsey Holland
002298547
kholland@chapman.edu
CPSC-350-02
Assignment 2
*/

#include "CreateArray.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>

//Default Constructor
CreateArray::CreateArray()
{
  numRows = 0;
  numColumns = 0;
  percentage = 0;
  option = true;
}


//Overloaded Constructor
CreateArray::CreateArray(int userNumRows, int userNumColumnns, float userPercentage, bool userOption, string userString)
{
  this->numRows = userNumRows;
  this->numColumns = userNumColumnns;
  this->percentage = userPercentage;
  this->option = userOption;
  this->userText = userString;
  setArraySize(numRows,numColumns);
  fill();
}

//Destructor
CreateArray::~CreateArray()
{
  for (int i = 0; i < numRows; ++i)
  {
    delete [] userArray[i];
  }
  delete [] userArray;
  cout << "Deleting CreateArray" << endl;
}


//-----------------------------------------------------------------------------
//Other Methods



//This method creates an array from the string read in from UserIO.
//If the file is invalid with chars other than 'X' or '-', the invalid
//chars are replaced with -. The size is also checked in the file, and if
//its invalid and does not match with the board then a random file
//will be made instead.

void CreateArray::createArrayFromFile(string userString)
{
  int a = 0;
  int i = 0;
  int j = 0;

  int sizeCheck = 0;


  for (i = 0; i < numRows; ++i){
    for (j = 0; j <= numColumns; ++j)
    {
      if (userString[a] != '\n')
      {
        if ((userString[a] == 'X' ) || (userString[a] == '-' ) )
        {
          userArray[i][j] = userString[a];
          sizeCheck += 1;
          a += 1;
        }
        else
        {
          cout << "Invalid text file, char is not 'X' or '-' . " << endl;
          cout << "Invalid char will be replaced with : '-' " << endl;
          userArray[i][j] = '-';
          sizeCheck += 1;
          a += 1;
        }
      }
      else
      {
        a +=1;
      }
    }
  }
  if (sizeCheck != (numRows * numColumns))
  {
    cout << "ERROR, invalid size board entered for number of rows and columns. " << endl;
    cout << "A randomized board will be made instead." << endl;
    randomizeArray();
  }
  else
  {
    cout << "Array creation was successful." << endl;
  }
}
//-----------

//This method initilizes the array and sets the integer size of the rows
//and columns
//Each array is essentially an array of pointers to arrays.

void CreateArray::setArraySize(int numRows, int numColumns)
{

    userArray  = new char*[numRows];
    for (int i = 0 ; i < numRows; ++i)
    {
      userArray[i] = new char [numColumns];
    }
}
//-----------

//This randomizes the array by taking the population density and changing
//it to a probability. It uses the rand function to create a random
//number and checks if it is larger or smaller than the density.
void CreateArray::randomizeArray()
{
  for (int i = 0 ; i < numRows; ++i)
  {
    for (int j = 0; j < numColumns; ++j)
    {
      float num = ((float)rand()/(RAND_MAX));
      if (num <= percentage)
      {
        userArray[i][j] = 'X';
      }
      else
      {
        userArray[i][j] = '-';
      }
    }
  }
}
//-----------------------

//This method fills the array with default '-' as elements
//Then the option to randomize or create from file is chosen.
void CreateArray::fill()
{
  for (int i = 0 ; i < numRows; ++i)
  {
    for (int j = 0; j < numColumns; ++j)
    {
      userArray[i][j] = '-';
    }
  }
  if (option == false)
  {
    createArrayFromFile(userText);
  }
  else
  {
    randomizeArray();
  }
}
//---------------


//This prints each element in the array.
void CreateArray::print()
{
  for (int i = 0; i < numRows; i++)
  {
    for (int j =0; j < numColumns; j++)
    {
      cout << userArray[i][j] << " ";
    }
    cout << endl;
  }
}
//---------------
//Accessors

char **CreateArray::getUserArray()
{
  return userArray;
}
//Mutators.
