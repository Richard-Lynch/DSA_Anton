//
// A-Star Demo for class
// Anton Gerdelan - 1 Dec 2016
// compile: clang -std=c99 -Wall -g -o demo main.c
// plan:
// * make a 2d grid for the graph domain
// * use manhattan distance for the heuristic
// * use the image loader we wrote to write numbered images out at fatter size than
// 1px
// show grey gradient to indicate cost
// * start cell green
// * end cell red
// * path blue
// * random obstacles in black (C-shaped walls)

#include <stdio.h>
#include <assert.h>
#include <stdbool.h>
#include <stdlib.h> // abs

#define NO_PARENT -1
#define WORLD_SIZE 4
#define ADJACENT_MOVE_COST 1
#define MAX_FRONTIER ( WORLD_SIZE * WORLD_SIZE )

// a 2d coordinate
typedef struct Coord { int x, y; } Coord;

// a vertex in the graph
typedef struct Node {
	// the previous node in the path to here
	Coord parent;
	// accumulated cost of the path to here - may be updated
	int cost;
	bool was_visited;
} Node;

Node graph[WORLD_SIZE][WORLD_SIZE];

// returns Manhattan distance from any square to the goal
int heuristic( Coord current, Coord goal ) {
	assert( current.x >= 0 && current.x < WORLD_SIZE );
	assert( current.y >= 0 && current.y < WORLD_SIZE );

	int x_dist = abs( goal.x - current.x );
	int y_dist = abs( goal.y - current.y );
	int h = x_dist + y_dist;
	return h;
}

void reset_graph() {
	for ( int row = 0; row < WORLD_SIZE; row++ ) {
		for ( int col = 0; col < WORLD_SIZE; col++ ) {
			graph[row][col].parent = ( Coord ){.x = NO_PARENT, .y = NO_PARENT };
			graph[row][col].cost = 0;
			graph[row][col].was_visited = false;
		}
	}
}

void astar( Coord start, Coord goal ) {
	Coord frontier[MAX_FRONTIER];
	int frontier_score[MAX_FRONTIER];
	frontier[0] = start;
	frontier_score[0] = 0;
	int frontier_len = 1;

  graph[start.y][start.x].was_visited = true;

	int probe_count = 0;

	while ( frontier_len > 0 ) {
		// get smallest item in frontier
		Coord current = frontier[0];

		if ( current.x == goal.x && current.y == goal.y ) {
			printf( "path found -- HALT\n" );
			break;
		}

		{ // shuffle down priority queue O(n)
			for ( int i = 0; i < frontier_len - 1; i++ ) {
				frontier[i] = frontier[i + 1];
				frontier_score[i] = frontier_score[i + 1];
			}
			frontier_len--;
		} // endblock

		{ // check all neighbours to current for frontier adding
			Coord adj[4] = {
				{.x = -1, .y = 0 }, {.x = 1, .y = 0 }, {.x = 0, .y = -1 }, {.x = 0, .y = 1 }
			};
			for ( int i = 0; i < 4; i++ ) {
				Coord next = current;
				next.x += adj[i].x;
				next.y += adj[i].y;

				// validate that adjacent node would be in grid space or off side
				if ( next.x < 0 || next.x >= WORLD_SIZE ) {
					continue;
				}
				if ( next.y < 0 || next.y >= WORLD_SIZE ) {
					continue;
				}

				// work out actual cost of going to neighbour - if cheap than last calc for
				// this node...
				int g = graph[current.y][current.x].cost + ADJACENT_MOVE_COST;
				if ( !graph[next.y][next.x].was_visited || ( g < graph[next.y][next.x].cost ) ) {
          graph[next.y][next.x].was_visited = true;
					graph[next.y][next.x].cost = g;
          graph[next.y][next.x].parent = current;
          // f(n) = g(n) + h(n)
          int h = heuristic( next, goal );
					frontier_score[frontier_len] = g + h; 
					frontier[frontier_len] = next;
					frontier_len++;
				}
			}
			probe_count++;
		}

		{ // sort - more crappy priority queue O(n^2)
			bool sorted = false;
			while ( !sorted ) {
				sorted = true;
				for ( int i = 0; i < frontier_len - 1; i++ ) {
					if ( frontier_score[i + 1] < frontier_score[i] ) {
						sorted = false;
						Coord tmp = frontier[i + 1];
						frontier[i + 1] = frontier[i];
						frontier[i] = tmp;
						int tmpcost = frontier_score[i + 1];
						frontier_score[i + 1] = frontier_score[i];
						frontier_score[i] = tmpcost;
					}
				} // endfor
			}		// endwhile
		}			// endblock

	} // endwhile
	printf( "v = %i, visits = %i\n", WORLD_SIZE * WORLD_SIZE, probe_count );
}

void print_path( Coord goal ) {
	Coord parent = graph[goal.y][goal.x].parent;
	printf( "%i,%i\n", goal.x, goal.y );
	while ( parent.x != NO_PARENT && parent.y != NO_PARENT ) {
		printf( "%i,%i\n", parent.x, parent.y );
		parent = graph[parent.y][parent.x].parent;
	}
}

int main() {
	reset_graph();
	// the start square and end square (top-left and bottom-right nodes)
	Coord start = ( Coord ){.x = 0, .y = 0 };
	Coord goal = ( Coord ){.x = WORLD_SIZE - 1, .y = WORLD_SIZE - 1 };

	astar( start, goal );
	print_path( goal );

	// f = g + h

	return 0;
}
