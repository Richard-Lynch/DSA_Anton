//
// A-Star Demo for class
// Anton Gerdelan - 1 Dec 2016

// plan:
// make a 2d grid for the graph domain
// use manhattan distance for the heuristic
// use the image loader we wrote to write numbered images out at fatter size than 1px
// show grey gradient to indicate cost
// start cell green
// end cell red
// path blue
// random obstacles in black (C-shaped walls)

#include <stdio.h>
#include <assert.h>

#define WORLD_SIZE 128

// world contains costs of obstacles
int world[WORLD_SIZE][WORLD_SIZE];
int goal_x = WORLD_SIZE - 1;
int goal_y = WORLD_SIZE - 1;

// returns Manhattan distance
int heuristic(int x, int y){
  assert(x >= 0 && x < WORLD_SIZE);
  assert(y >= 0 && y < WORLD_SIZE);
  
  int x_dist = goal_x - x;
  int y_dist = goal_y - y;
  return x_dist + y_dist + world[x][y];
}

int main(){
  
  
  return 0; 
}
