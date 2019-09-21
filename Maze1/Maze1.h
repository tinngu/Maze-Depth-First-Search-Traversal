#ifndef __MAZE1
#define __MAZE1

#include <iostream>
#include <cstdlib>      // for the exit function
#include <cassert>      // for the assert function
#include "Position.h"
#include <stack>

using namespace std;

typedef enum{OPEN,WALL,VISITED} state;

class Maze1
{
  public:
   // Constructor - sets size to n, allocates the nxn state array 
   // and sets the state of every array element to WALL
   Maze1(int n);

   // Destructor - deallocates the state array
   ~Maze1();

   // Copy constructor and assignment disabled
   Maze1(const Maze1 & other);
   Maze1 & operator=(const Maze1 & origMaze);

   void initialize();
   // inputs the start and exit positions and sets their state to OPEN; 
   // then inputs the other OPEN positions; prompts will be printed to
   // cout only if in == cin

   void display() const;
   // Print the contents of the maze, one row per line
   // For each Position P, print 'b' if P is both the start and exit position;
   // print 's' if P is the start, print 'e' is P is the exit; 
   // print '*' if the P's state is WALL and print a space
   // if P's state is OPEN

   void printExitPath();
   // If the path stack is empty, output "No way out\; otherwise, output
   // "Exit path:" then call reverseStackPrint to print the exit path
   // In any case, at the last, insert endl into the output stream.

  private:
   int size;
   Position start;
   Position exitpos;
   stack<Position> path;
   state **M; // two-dimensional array of state values

   void find_exit();
   // Use the DFS method to fill the path stack with the exit path Positions

   void reverseStackPrint();
   // Print the contents of the path stack from bottom to top recursively

   bool validPosition(Position P);
};


#endif
