#include <stdio.h>
#include <limits.h>

# include "push_swap.h"

int find_element_and_move_to_top(int* stackB, int size, int element, int operation);
int find_element_position(int* stackB, int size, int element);
int move_to_top(int* stackB, int size, int position, int operation);


int *best_combination(int k1, int k2, int k3, int* stackB, int size) {
    int i, j, k;
    int best_moves = INT_MAX;
    int current_moves;
    static int best_order[3] = {-1, -1, -1};

    // Try all possible combinations of searching for k1, k2, k3
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            for (k = 0; k < 3; k++) {
                if (i != j && j != k && k != i) {
                    current_moves = find_element_and_move_to_top(stackB, size, k1, i) +
                                    find_element_and_move_to_top(stackB, size, k2, j) +
                                    find_element_and_move_to_top(stackB, size, k3, k);
                    if (current_moves < best_moves) {
                        best_moves = current_moves;
                        best_order[0] = i;
                        best_order[1] = j;
                        best_order[2] = k;
                    }
                }
            }
        }
    }
    //printf("The best order is: %d %d %d\n", best_order[0], best_order[1], best_order[2]);
    return best_order;
}

int find_element_and_move_to_top(int* stackB, int size, int element, int operation) {
    int position = find_element_position(stackB, size, element);
    if (position == -1) {
        return 0;
    }
    return move_to_top(stackB, size, position, operation);
}

int find_element_position(int* stackB, int size, int element) {
    // Find the position of the element in the stack
    // Return -1 if not found
    for (int i = 0; i < size; i++) {
        if (stackB[i] == element) {
            return i;
        }
    }
    return -1;
}

int move_to_top(int* stackB, int size, int position, int operation) {
    int moves = 0;
    int temp;
    // Move the element at the given position to the top
    // using rotate or reverse rotate operation
    if (operation == 0) {
        // Rotate operation
        while (position != size - 1) {
            temp = stackB[size - 1];
            for (int i = size - 1; i > 0; i--) {
                stackB[i] = stackB[i - 1];
            }
            stackB[0] = temp;
            position++;
            moves++;
        }
    } else {
        // Reverse rotate operation
        while (position != 0) {
            temp = stackB[0];
            for (int i = 0; i < size - 1; i++) {
                    stackB[i]   = stackB[i + 1];
            }
            stackB[size - 1] = temp;
            position--;
            moves++;
        }
    }
    return moves;
}



/*
int main() {
    int k1 = 5, k2 = 3, k3 = 9;
    int stackB[] = {1, 2, 5, 8, 3, 6, 4, 7, 9};
    int size = sizeof(stackB) / sizeof(stackB[0]);

    int best_moves = best_combination(k1, k2, k3, stackB, size);
    printf("The best combination requires %d moves\n", best_moves);

    return 0;
}
*/