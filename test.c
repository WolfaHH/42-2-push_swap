

#include <stdio.h>
#include <limits.h>

# include "push_swap.h"

int find_element_and_move_to_top(int* stackB, int size, int element, int operation);
int find_element_position(int* stackB, int size, int element);
int move_to_top(int* stackB, int size, int position, int operation);


int *best_combination(int k1, int k2, int k3, int* stackB, int size) {

    

}



/*
int main() {
    int stackB[] = {79, 81, 82, 60, 68, 101, 76, 59, 53, 65, 75, 52, 64, 74, 72, 58, 55, 63, 57, 67, 61, 69, 70, 66, 56, 62, 73, 71,
     54, 36, 51, 41, 48, 46, 27, 38, 28, 42, 31, 44, 45, 50, 34, 29, 47, 33, 30, 35, 40, 43, 37, 39, 49, 32, 16, 20, 12, 10, 2, 1, 13, 
     3, 8, 9, 7, 26, 21, 15, 11, 25, 18, 6, 22, 5, 17, 19, 4, 24, 23, 14, 78, 77, 80};
    int size = sizeof(stackB) / sizeof(stackB[0]);
    int k1 = 82, k2 = 81, k3 = 80;
    int *result = best_combination(k1, k2, k3, stackB, size);
    printf("So you return %d, %d and %d\n", result[0], result[1], result[2]);
    
    return 0;
}*/
