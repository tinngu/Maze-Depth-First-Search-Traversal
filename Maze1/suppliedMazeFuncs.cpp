#include "Maze1.h"
#include <iostream>
#include <cstdlib>

using namespace std;

Maze1::Maze1(int n): size(n) 
{
  // start and exit will be set by the initialize method
  M = new(nothrow) state *[size+2];
  assert(M);

  for(int i = 0; i < size+2; ++i) {
    M[i] = new (nothrow) state[size+2];
    assert(M[i]);
    for(int j = 0 ; j < size+2; ++j)
      M[i][j] = WALL;
  }
}

void Maze1::display() const
{
  state s;
  for(int i = 0; i < size+2; ++i) {
    for(int j = 0; j < size+2; ++j) {
      s = M[i][j];
      assert(s == OPEN || s == WALL);
      if (s == WALL)
	cout << "*";
      else {
	Position P(i,j);
	if(P == start && P == exitpos)
	  cout << "b";
	else if(P == start)
	  cout << "s";
	else if(P == exitpos)
	  cout << "e";
	else
	  cout << "-";
      }
    }
    cout << endl;
  }
}

bool Maze1::validPosition(Position P)
{
  bool b = (1 <= P.row && P.row <= size && 1 <= P.col && P.col <= size);
  return b || P == NULLPOS;
}

void Maze1::initialize()
{
  
  cout << "The coordinates of positions in the maze must be in the range\n";
  cout << "from 1 to " << size << ", inclusive\n" << endl;
  cout << "Enter the row and column coordinates of the start position: ";
  cin >> start;
  while(!validPosition(start) || start == NULLPOS) {
    cout << "Invalid position; try again\n";
    cin >> start;
  }
  cout << endl;
  M[start.row][start.col] = OPEN;
    
  cout << "Enter the row and column coordinates of the exit position: ";
  cin >> exitpos;
  while(!validPosition(exitpos) || exitpos == NULLPOS) {
    cout << "Invalid position; try again\n";
    cin >> exitpos;
  }
  cout << endl;
  M[exitpos.row][exitpos.col] = OPEN;

  Position P;
  cout << "Enter the row and column coordinates of the other OPEN positions\n"
       << "terminating input with \"-1 -1\"\n";
  int count = 0;
  do {
    cin >> P;
    if(P == start || P == exitpos)
      continue;
    while(!validPosition(P)) {
      cout << "Invalid position; try again\n";
      cin >> P;
    }
    if(!(P == NULLPOS)) {
      if (M[P.row][P.col] == OPEN) {
	cout << "Duplicate in open position list: " << P << endl;
	exit(1);
      }
      M[P.row][P.col] = OPEN;
      count += 1;
    }
  } while(!(P == NULLPOS) && count < size*size);
  cout << endl;
}


void Maze1::reverseStackPrint()
// Print the contents of the path stack from bottom to top recursively
{
  if(path.empty())
    return;
  Position last = path.top();
  path.pop();
  reverseStackPrint();
  cout << last;
}

void Maze1::printExitPath()
// If the path stack is empty, output "No way out\; otherwise, output
// "Exit path:" then call reverseStackPrint to print the exit path
// In any case, at the last, insert endl into the output stream.
{
  // Supply the code for this function
  find_exit();
  if(path.empty())
    cout << "No way out" << endl;
  else {
    cout << "Path to exit:\n\n";
    reverseStackPrint();
    cout << endl;
  }  
}

