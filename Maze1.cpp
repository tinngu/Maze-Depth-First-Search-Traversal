#include "Maze1.h"
#include <iostream>
#include <cassert>

using namespace std;

Maze1::~Maze1()
{
	for (int i = 0; i < size; ++i) {
		delete[] M[i];
	}
	delete[] M;

}

void Maze1::find_exit()
// Use the DFS method to fill the path stack with the exit path Positions
// If there is no path to the exit, then after execution of this function
// the stack path should be empty
// This function does no input and no output
{
  // FILL IN THE CODE FOR THIS METHOD
  Position nbr, current;
  direction d;

  //First mark the start position as visited and make it to the current position
  M[start.row][start.col] = VISITED;
  current = start;
  path.push(current);

  //The path is empty once all open positions have been visited and the stack pops each one out
  while (!path.empty()) {
	  //Current is set to the path at the top of the stack, after an open neighbor is found or Not
	  current = path.top();
	  nbr = current;

	  //Check to see if the current position is the Exit position
	  //If the exit position is found the search ends
	  if (current == exitpos)
		  return;
	  
	  //Go through each direction for the next position from DOWN, LEFT, UP, RIGHT, NONE
	  for (d = DOWN; d != NONE; d = next_direction(d)) {
		  if (M[current.Neighbor(d).row][current.Neighbor(d).col] == OPEN) {
			  nbr = current.Neighbor(d);
			  //Once visited break out and start from the DOWN direction on next loop
			  break;
		  }
	  }

	  //There is no neighbor. If all four directions are either wall or visited 
	  //If the direction is NONE and the neighbor did not move from the current
	  if (d == NONE && nbr == current) {
		  //pop the position and it will loop through to the previous position to where it started
		  path.pop();
	  }

	  //Set the neighbor position to visited and push it to the path stack
	  else {
		  M[nbr.row][nbr.col] = VISITED;
		  path.push(nbr);
	  }
  }
}




