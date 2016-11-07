//
// demo to check what order a 2d matrix actually stores memory on

#include <stdio.h>

int main(){
	char matrix[3][3];

	// a d g
	// b e h
	// c f i


	matrix[0][0] = 'a';
	matrix[1][0] = 'b';
	matrix[2][0] = 'c';
	matrix[0][1] = 'd';
	matrix[1][1] = 'e';
	matrix[2][1] = 'f';
	matrix[0][2] = 'g';
	matrix[1][2] = 'h';
	matrix[2][2] = 'i';

	for (int i = 0; i < 9; i++){
		printf("matrix 1d memory %i = %c\n",
		i, *(&matrix[0][0] + sizeof(char) * i)); 
	}
}
