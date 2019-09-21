#include <fstream>
#include <iostream>
#include "Maze1.h"

using namespace std;

int main(int argc, char * argv[])
{
  int maze_size;
      
  cout << "Welcome to the Rat in a Maze Program\n\n";
  cout << "You will prompted for the maze size, the start position,\n";
  cout << "the exit position, and the open positions of the maze.";
  cout << "If there is a path from the start to the exit, the sequence\n";
  cout << "of positions on that path will be printed; if no such path\n";
  cout << "exits, the message \"no way out\" will be printed\n\n";
  cout << "Input the size of the maze (not including the hedge): ";

  cin >> maze_size;

  Maze1 RatHaus1(maze_size);

  RatHaus1.initialize();

  RatHaus1.display();
  cout << "\n\n";
  RatHaus1.printExitPath();
  cout << "\n\n";

  return 0;
}

