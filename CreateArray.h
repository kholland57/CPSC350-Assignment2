
/*
Kelsey Holland
002298547
kholland@chapman.edu
CPSC-350-02
Assignment 2
*/



#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;


#ifndef  CREATEARRAY_H
#define  CREATEARRAY_H
class CreateArray{
  public:
    //Constructors
    CreateArray();
    CreateArray(int numRows, int numColumns, float percentage, bool userOption, string userString);
    ~CreateArray();

    //Other methods
    void promptUser();
    void setArraySize(int numRows, int numColumns);

    void createArrayFromFile(string userString);

    void fill();
    void randomizeArray();
    void print();

    //Accessors and Mutators
    void setUserArray();
    char **getUserArray();

    //Private Variables
  private:
    char **userArray;

    int numRows;
    int numColumns;
    float percentage;
    bool option;
    string userText;

};
#endif
