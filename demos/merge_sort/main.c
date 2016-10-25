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
// * 

#include <stdio.h>

int main() {
    // create 2 input lists and space for one output list
    int list_a[] = { 3, 4, 12 }; // initialiser list for array giving constant values
    int list_b[] = { 1, 10, 23 }; // array will make itself size 3 at compile time

    // all working should produce 1,3,4,10,12,23
    int output_list[6] = { 0 }; // this is a trick to zero the whole array at compile time
    
    // counters all start at 0
    int a_index = 0, b_index = 0, output_index = 0;

    // compare the lists until one list runs out of list
    while (a_index < 3 && b_index < 3) {
        if (list_a[a_index] <= list_b[b_index]) {
            output_list[output_index++] = list_a[a_index++];
        } else {
            output_list[output_index++] = list_b[b_index++];
        }
    }

    // copy any leftovers from either list into output
    // you can probably simplify these into the other loop
    // if you're smarter than me
    while (a_index < 3){
        output_list[output_index++] = list_a[a_index++];
    }
    while (b_index < 3){
        output_list[output_index++] = list_b[b_index++];
    }

    // output
    // note that you may not want to actually have an array for
    // the output list - you could just print directly out instead of
    // copying into an array and redirect stdout to a file as required
    // ./demo > myfile.txt
    for (int i = 0; i < 6; i++) {
        printf("%i ", output_list[i]);
    }
    printf("\n");

    return 0;
}