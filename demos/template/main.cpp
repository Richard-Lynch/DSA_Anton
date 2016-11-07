#include <stdio.h>

template <class T>
void swap(T &first, T &second) {
    T temp = first;
    first = second;
    second = temp;
}

int main(){
    int a = 10, b = 11;
    printf("a=%i b=%i\n", a, b);
    swap(a, b);
    printf("a=%i b=%i\n", a, b);
    return 0;
}

/*
template <class T>
T min(T x, T y){
    if (x<y){
        return x;
    }
    return y;
}
*/