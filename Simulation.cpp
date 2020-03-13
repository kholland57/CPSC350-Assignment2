
/*
Kelsey Holland
002298547
kholland@chapman.edu
CPSC-350-02
Assignment 2
*/



#include "Simulation.h"
#include <chrono>
#include <thread>
#include <stdio.h>

//Default Constructor
Simulation::Simulation()
{
  genNum = 0;
  mode = 1;
  fileLength = 0;
}

//Overloaded Constructor
Simulation::Simulation(int genNum, int mode, int fileLength)
{
    this->genNum = genNum;
    this->mode = mode;
    this->fileLength = fileLength;
}

//Destructor
Simulation::~Simulation()
{
  cout << "Deleting Simulation Class" <<endl;
  delete promptData;
  delete arrayCreate;
}
//-----------------------------------------------------------------------------

//This is the method that runs the simulation. It asks the user for
//parameters to make an array. After making the array, it asks for the
//game mode and runs the entered simulation mode.
void Simulation::runSimulation()
{
  promptData = new UserIO();
  promptData->promptUser();
  arrayCreate = new CreateArray(promptData->getRows(),promptData->getColumns(), promptData->getPercentage(), promptData->getRandomizeOption(), promptData->getFileText());
  arrayCreate->print();

  int gameMode = promptData->promptMode();
  mode = promptData->promptOutput();
  if (mode == 1)
  {
    fileLength = promptData->promptFileLength();
  }
  cout << '\n' << endl;


  if (gameMode == 1)
  {
    runClassic();
  }
  else if (gameMode  == 2 )
  {
    runMirror();
  }
  else
  {
    runDoughnut();
  }

//If not a text file, user has to press enter to exit.
  if (mode != 1 )
  {
      exitSimulation();
  }
}
//------------


/*
This runs the classic mode of the game.
It will run infinitley until everything dies,
stabilizes, or reaches the limit if its a file output.


*/


void Simulation::runClassic()
{
  GameOfLife *newGame = new GameOfLife(promptData->getRows(),promptData->getColumns(), arrayCreate->getUserArray());

  while (true){

    if (genNum != 0){
      newGame->runGame();
    }
    string newString = newGame->printString();

    //This writes to outfile.
    if (mode == 1 ){
      if (genNum <= fileLength){
        promptData->writeOutFile(newString, genNum);
      }
      else
      {
        cout <<"End of writing to file. System will now exit." << endl;
        break;
      }
    }
    //This pauses for a few seconds if mode is 2
    else if (mode == 2)
    {
      std::this_thread::sleep_for(chrono::seconds(2));
      cout << genNum << endl;
      cout << newString;
    }
    //Normally prints
    else if (mode == 3)
    {
      cout << genNum << endl;
      cout << newString;
    }

    //This checks if the board is empty and breaks if it is.
    if (newGame->checkLife() == false)
    {
      if (mode != 1 )
      {
        cout << "The Board is Empty." << endl;
      }
      break;
    }
    //This checks if the board is stabilized and breaks if it is.
    if (newGame->getStabilization() == true)
    {
      if (mode != 1 )
      {
        cout << "The Board has stabilized." << endl;
      }
      break;
    }

    //The generation number increases
    genNum ++;
    //The simulation is paused for a few seconds if it is the third option.
    if (mode == 3)
    {
      pause();
    }
  }
  delete newGame;

}

//runMirror is identical to runClassic() except for initializing mirror class.

void Simulation::runMirror()
{
  int m = 0;

  Mirror *newGame = new Mirror(promptData->getRows(),promptData->getColumns(), arrayCreate->getUserArray());
  while (true){

    if (genNum != 0){
      newGame->runGame();
    }


    string newString = newGame->printString();

    if (mode == 1 ){
      if (genNum <= fileLength){
        promptData->writeOutFile(newString, genNum);
      }
      else
      {
        cout <<"End of writing to file. System will now exit." << endl;
        break;
      }
    }
    else if (mode == 2)
    {
      std::this_thread::sleep_for(chrono::seconds(2));
      cout << genNum << endl;
      cout << newString;
    }
    else if (mode == 3)
    {
      cout << genNum << endl;
      cout << newString;
    }


    if (newGame->checkLife() == false)
    {
      if (mode != 1 )
      {
        cout << "The Board is Empty." << endl;
      }
      break;
    }

    if (newGame->getStabilization() == true)
    {
      if (mode != 1 )
      {
        cout << "The Board has stabilized." << endl;
      }
      break;
    }

    genNum ++;

    if (mode == 3)
    {
      pause();
    }
  }

  delete newGame;
}
//------------



//runDoughnut() is identical to runClassic() except for initializing mirror class.
void Simulation::runDoughnut()
{
  int m = 0;

  Doughnut *newGame = new Doughnut(promptData->getRows(),promptData->getColumns(), arrayCreate->getUserArray());

  while (true){

    if (genNum != 0){
      newGame->runGame();
    }
    string newString = newGame->printString();

    if (mode == 1 ){
      if (genNum <= fileLength){
        promptData->writeOutFile(newString, genNum);
      }
      else
      {
        cout <<"End of writing to file. System will now exit." << endl;
        break;
      }
    }
    else if (mode == 2)
    {
      std::this_thread::sleep_for(chrono::seconds(2));
      cout << genNum << endl;
      cout << newString;
    }
    else if (mode == 3)
    {
      cout << genNum << endl;
      cout << newString;
    }


    if (newGame->checkLife() == false)
    {
      if (mode != 1 )
      {
        cout << "The Board is Empty." << endl;
      }
      break;
    }

    if (newGame->getStabilization() == true)
    {
      if (mode != 1 )
      {
        cout << "The Board has stabilized." << endl;
      }
      break;
    }

    genNum ++;

    if (mode == 3)
    {
      pause();
    }
  }
  delete newGame;


}
//------------

//This stops the IO stream so that when the user presses enter,
//the system is able to detect it so it can exit the program.
void Simulation::exitSimulation()
{
    cout <<"Simulation complete." << endl;
    ios_base::sync_with_stdio(false);

    cin.ignore(std::cin.rdbuf()->in_avail());

    cout <<"Press 'Enter' to exit.";
    cin.ignore();
    if (cin.get() == '\n')
    {
      cout  << "Exiting Program" << endl;
    }
}
//------------

//This method pauses the simulation until the user hits enter.
void Simulation::pause()
{
  bool pause = true;
  while (pause == true)
  {
    if (cin.get() == '\n')
    {
      pause = false;
    }
  }
}
//------------
//accessors






//------------
//mutators






//Graveyard




//
// void Simulation::runMirror()
// {
//   int m = 0;
//   //cout << "MIRROR :: \n " << endl;
// //  Mirror *newGame = new Mirror(promptData->getRows(),promptData->getColumns(), arrayCreate->getUserArray());
//
//
//   while (true){
//
//     if (genNum != 0){
//       newGame->runGame();
//     }
//     string newString = newGame->printString();
//
//     if (mode == 1 ){
//       if (genNum < fileLength){
//         promptData->writeOutFile(newString, genNum);
//       }
//       else
//       {
//         cout <<"End of writing to file. System will now exit." << endl;
//       }
//     }
//     else if (mode == 2)
//     {
//       std::this_thread::sleep_for(chrono::seconds(2));
//       cout << genNum << endl;
//       cout << newString;
//     }
//     else if (mode == 3)
//     {
//       cout << genNum << endl;
//       cout << newString;
//     }
//
//
//     if (newGame->checkLife() == false)
//     {
//       cout <<"Simulation complete." << endl;
//       if (mode != 1 )
//       {
//         cout << "The Board is Empty." << endl;
//         cout << "Press 'Enter' to exit.";
//         pause();
//       }
//       break;
//     }
//
//     if (newGame->getStabilization() == true)
//     {
//       cout <<"Simulation complete." << endl;
//       if (mode != 1 )
//       {
//         cout << "The Board has stabilized." << endl;
//         cout << "Press 'Enter' to exit.";
//         if (cin.get() == '\n')
//         pause();
//       }
//       break;
//     }
//
//     genNum ++;
//
//     if (mode == 3)
//     {
//       pause();
//     }
//   }
//
//   delete newGame;
//   // while (m  < 300){
//   //   cout << "\nGENERATION: " << genNum << endl;
//   //   newGame->runGame();
//   //   newGame->print();
//   //
//   //   if (newGame->checkLife() == false)
//   //   {
//   //     cout << "EVERYONE IS DEAD" << endl;
//   //     break;
//   //   }
//   //   if (newGame->getStabilization() == true)
//   //   {
//   //     cout << "SIMULATION HAS STABILIZED." << endl;
//   //     break;
//   //   }
//   //
//   //   genNum ++;
//   //   m++;
//   // }
//   //
//   // delete newGame;
//
// }
//
// void Simulation::runDoughnut()
// {
//   int m = 0;
//
//   Doughnut *newGame = new Doughnut(promptData->getRows(),promptData->getColumns(), arrayCreate->getUserArray());
//   while (true){
//
//     if (genNum != 0){
//       newGame->runGame();
//     }
//     string newString = newGame->printString();
//
//     if (mode == 1 ){
//       if (genNum < fileLength){
//         promptData->writeOutFile(newString, genNum);
//       }
//       else
//       {
//         cout <<"End of writing to file. System will now exit." << endl;
//       }
//     }
//     else if (mode == 2)
//     {
//       std::this_thread::sleep_for(chrono::seconds(2));
//       cout << genNum << endl;
//       cout << newString;
//     }
//     else if (mode == 3)
//     {
//       cout << genNum << endl;
//       cout << newString;
//     }
//
//
//     if (newGame->checkLife() == false)
//     {
//       if (mode != 1 )
//       {
//         cout << "The Board is Empty." << endl;
//         cout << "Press 'Enter' to exit.";
//         pause();
//       }
//       break;
//     }
//
//     if (newGame->getStabilization() == true)
//     {
//       if (mode != 1 )
//       {
//         cout << "The Board has stabilized." << endl;
//         cout << "Press 'Enter' to exit.";
//         if (cin.get() == '\n')
//         pause();
//       }
//       break;
//     }
//
//     genNum ++;
//
//     if (mode == 3)
//     {
//       pause();
//     }
//   }
//
//   delete newGame;
//   // while (m  < 300){
//   //   cout << "\nGENERATION: " << genNum << endl;
//   //   newGame->runGame();
//   //   newGame->print();
//   //
//   //   if (newGame->checkLife() == false)
//   //   {
//   //     cout << "EVERYONE IS DEAD" << endl;
//   //     break;
//   //   }
//   //   if (newGame->getStabilization() == true)
//   //   {
//   //     cout << "SIMULATION HAS STABILIZED." << endl;
//   //     break;
//   //   }
//   //   genNum ++;
//   //   m++;
//   // }
//   //
//   // delete newGame;
//
// }
