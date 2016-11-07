#include <stdio.h>
#include <vector>

int main(){

    // create new vector
    std::vector<int> my_vector;

    // add some values on to end of vector
    my_vector.push_back(0);
    my_vector.push_back(1);
    my_vector.push_back(2);

    int sz = my_vector.size();

    // loop over vector using C style loop
    // and access vector like an array
    for(int i = 0; i < sz; i++) {
        printf("vector element[%i]=%i\n", i, my_vector[i]);
    }

    return 0;
}