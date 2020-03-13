

/*
Kelsey Holland
002298547
kholland@chapman.edu
CPSC-350-02
Assignment 2
*/


#include "UserIO.h"

//Default Constructor
UserIO::UserIO(){
    numRows = 0;
    numColumns = 0;
    percentage = 0;
    randomizeOption = true;
}

//Overloaded Constructor
UserIO::UserIO(int newNumRows, int newNumColumns, float newPercentage, bool newOption){

  numRows = newNumRows;
  numColumns = newNumColumns;
  percentage = newPercentage;
  randomizeOption = newOption;
}

//Destructor

UserIO::~UserIO()
{
  cout <<"Deleting UserIO" << endl;
}

//----------------------------------------------------------
//Methods :


//This method prompts the user if they want to make a randomized board or
//read in a file. If random, it asks for the parameters.
//This has a lot of error checking for invalid cin parameters.
void UserIO::promptUser(){

  string userResponse = "";
  cout << "Enter '1' to read in a file or '2' to make a randomized configuration." << endl;
  cin >> userResponse;

  if (userResponse == "1")
  {
    readInFile();
  }
  else if (userResponse == "2")
  {
    cout << "\nCreating a Randomized File:" << endl;
    int numUserRows = 0;
    int numUserColumns = 0;
    float userPercentage = 0;

    cout << "Enter in the number of rows in the board: " << endl;
    cin >> numUserRows;
    if (cin.fail())
    {
      cin.clear();
      cin.ignore(256, '\n');
      cout << "Invalid input. Default row number will be set to 5 instead." << endl;
      numUserRows = 5;
    }
    if (numUserRows < 2 )
    {
      cout << "Invalid input. Default row number will be set to 5 instead." << endl;
      numUserRows = 5;
    }
    cout << "Enter in the number of columns in the board " << endl;
    cin >> numUserColumns;
    if (cin.fail())
    {
      cin.clear();
      cin.ignore(256, '\n');
      cout << "Invalid input. Default row number will be set to 5 instead." << endl;
      numUserColumns = 5;
    }
    if (numUserColumns < 2 )
    {
      cout << "Invalid input. Default column number will be set to 5 instead." << endl;
      numUserColumns = 5;
    }

    cout << "Enter in the population density (decimal)" << endl;
    cin >> userPercentage;
    if (cin.fail())
    {
      cin.clear();
      cin.ignore(256, '\n');
      cout << "Invalid input. Default percentage will be set to .5" << endl;
      userPercentage = .5;
    }
    if ((userPercentage > 1 ) || (userPercentage < 0 ))
    {
      cout << "Invalid input. Default percentage will be set to .5 instead." << endl;
      userPercentage = .5;
    }
    this->numRows = numUserRows;
    this->numColumns = numUserColumns;
    this->percentage = userPercentage;
    this->randomizeOption = true;

  }
  else {
    cout << "Invalid parameter number entered." << endl;
    cout << "Please try again." << endl;
    promptUser();

  }
}
//------------

//This reads in the file when the user enters in the text name.
void UserIO::readInFile(){

  ifstream inFS;
  string fileName = "";
  cout << "Enter the pathname of the new file you want to read in : "  << endl;
  cout << "(Do not add quotation marks around the file name)" << endl;

  cin >> fileName;
  cout << "Opening " << fileName << endl;
  inFS.open(fileName);

  if (!inFS.is_open())
  {
    cout << "ERROR, could not open file " << fileName  << endl;
    cout << "Exiting Program." << endl;
    exit(1);
  }

  inFS >> numRows;
  inFS >> numColumns;

  if (!inFS.fail()) {
    this->randomizeOption = false;
    cout << "Reading of Variables Successful." << endl;
  }
  else
  {
    cout << "Invalid file format. Exiting program." << endl;
    exit(1);
  }
  string userString;
  string userTotalString;
  while (!inFS.eof()) {
    inFS >> userString;
    if (!inFS.fail()) {
      userTotalString = userTotalString + userString + "\n";
    }
  }
  inFS.close();
  cout << userTotalString << endl;
  this->fileText = userTotalString;
}
//------------

//This writes to a file each time it is called.
void UserIO::writeOutFile(string newString, int genNum)
{
  ofstream outFS;
  outFS.open("holland.txt", ios::app);

  outFS << genNum << endl;
  outFS << newString;

  outFS.close();
}
//------------

//This asks the user which mode they want to run in. If input is incorrect,
//classic mode will be used instead.
int UserIO::promptMode()
{
  int mode = 0;
  cout << "\nWould you like to play in Classic, Mirror, or Doughnut Mode? " << endl;
  cout << "Enter the number for the mode you want to play in." << endl;
  cout << "1 : Classic" << endl;
  cout << "2 : Mirror" << endl;
  cout << "3 : Doughnut" << endl;

  cin>>mode;

  if (cin.fail())
  {
    cin.clear();
    cin.ignore(256, '\n');
    cout << "Invalid input. Mode will be set to Classic Instead." << endl;
    mode = 1;
  }

  if ((mode == 1 )|| (mode == 2) || (mode == 3))
  {
    return mode;
  }
  else
  {
    cout <<"Invalid input. The mode will be set to default Classic instead." << endl;
    int newMode = 1;
    return newMode;
  }
}

//------------

//This asks the number of generations the user wants to output.
//Default number 15 is set instead if input is incorrect.
int UserIO::promptFileLength()
{
  int length = 0;
  cout << "\nEnter an integer for the number of generations you want outputed to the file:  " << endl;

  cin>>length;

  if (cin.fail())
  {
    cin.clear();
    cin.ignore(256, '\n');
    cout << "Invalid input. Length will be set to 15 Generations instead." << endl;
    return 16;
  }

  if (length < 0 )
  {
    cout << "Invalid input." << endl;
    cout <<"Number will be set to 15 instead." << endl;
    return 16;
  }
  else
  {
    return length;
  }
}
//------------

//This asks the user how they want each generation to be printed out.
//If the input is invalid, option 3 will be the default.
int UserIO::promptOutput()
{
  int mode = 0;
  cout << "\nEnter the option number for how the output will be printed out." << endl;

  cout << "1 : Output to a TextFile" << endl;
  cout << "2 : Brief Pause between each Generation" << endl;
  cout << "3 : Pressing the 'Enter' key to continue after each generation." << endl;

  cin >> mode;

  if (cin.fail())
  {
    cin.clear();
    cin.ignore(256, '\n');
    cout << "Invalid input. The mode will be set to Option 3 instead." << endl;
    return 3;
  }



  if ((mode == 1 )|| (mode == 2) || (mode == 3))
  {
    return mode;
  }
  else
  {
    cout <<"Invalid input. The mode will be set to Option 3 instead." << endl;
    return 3;
  }
}

//---------------------------------------------------------------------------
//Accessors

int UserIO::getRows(){
  return numRows;
}

int UserIO::getColumns(){
  return numColumns;
}

float UserIO::getPercentage(){
  return percentage;
}

bool UserIO::getRandomizeOption(){
  return randomizeOption;
}

string UserIO::getFileText(){
  return fileText;
}
