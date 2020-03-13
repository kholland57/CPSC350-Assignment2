


/*
Kelsey Holland
002298547
kholland@chapman.edu
CPSC-350-02
Assignment 2
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class UserIO{
  public:
    //Constructors
    UserIO();
    UserIO(int newNumRows, int newNumColumns, float newPercentage, bool newOption);
    //Destructor
    ~UserIO();

    //Public Methods
    void promptUser();
    void readInFile();
    void writeOutFile(string newString, int genNum);
    int promptMode();
    int promptOutput();
    int promptFileLength();

    //Accessors
    int getRows();
    int getColumns();
    float getPercentage();
    bool getRandomizeOption();
    string getFileText();

  //Private Variables
  private:
    int numRows;
    int numColumns;

    float percentage;
    string fileText;

    bool randomizeOption;
};
