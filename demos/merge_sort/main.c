//
// Merge Sort implementation
// First v. 25 Oct 2016 Dr Anton Gerdelan <gerdela@scss.tcd.ie>
// C99 but should compile as other C or C++
//
// NOTE:
// I am using increments a lot
// list_a[a_index++];
// "use elemet at a_index and then increment a_index afterwards"
// normally i find this confusing to read so i do the full
// list_a[a_index];
// a_index++;
// as you like
//
// Mistakes I made:
// * mixing up counters (maybe use clearer names than a and b)
// * using || instead of && in my loop condition
// * forgetting to actually print the output
// * severao of my <= were <. i had to step through with the debugger and
// watch lists to find that these were mistakes

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

// first and last are the range of the output list, inclusive
// we know that the left half will be first to mid
// and the right half will be mid+1 to last
void merge( int first, int last, int *array ) {
    // make a temporary working array so we don't overwrite our data
    // as we are reading it
    // alloca is dynamic _stack_ memory - freed at function close
    // you could do this with another sort of array or memory
    int* result = alloca(sizeof(int) * (last - first));

	int mid_index = ( first + last ) / 2;
	int left_index = first, right_index = mid_index + 1, output_index = first;
	// compare the lists until one list runs out of list
	while ( left_index <= mid_index && right_index <= last ) { 
		if ( array[left_index] < array[right_index] ) {
			result[output_index++] = array[left_index++];
		} else {
			result[output_index++] = array[right_index++];
		}
	}
	// copy any leftovers from either list into output
	// you can probably simplify these into the other loop
	// if you're smarter than me
	while ( left_index <= mid_index ) {
		result[output_index++] = array[left_index++];
	}
	while ( right_index <= last ) {
		result[output_index++] = array[right_index++];
	}
    // copy into original array
    for (int i = first; i <= last; i++) {
        array[i] = result[i];
    }
}

// declare here so i can recursively call self
void merge_sort( int first_index, int last_index, int* data );

void merge_sort( int first_index, int last_index, int* data ) {
	// break recursion when counters meet in the middle
	if ( first_index >= last_index ) {
		return;
	}
	int mid_index = ( first_index + last_index ) / 2;
	// NB: replacing recursion with loops is usually more efficient
	merge_sort( first_index, mid_index, data );
	merge_sort( mid_index + 1, last_index, data );
	merge( first_index, last_index, data );
}

int main() {
	// create 2 input lists and space for one output list
	int data[] = { 3, 4, 12, 1, 10, 23 }; // initialiser list for array giving
																				// constant values

    // sort with bisections, recursively, from indices 0 to 5, inclusive
	merge_sort( 0, 5, data );

	for ( int i = 0; i < 6; i++ ) {
		printf( "%i ", data[i] );
	}
	printf( "\n" );

	return 0;
}