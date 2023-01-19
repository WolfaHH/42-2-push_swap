

# include <stdio.h>
# include <limits.h>

# include "push_swap.h"

int *best_combination(int k1, int k2, int k3, int* stackB, int size, int *sorted_list, int n){


    int *stackK = malloc(900000000);
    int sizeK[1];  
    *sizeK = size;
    static int order[3] = {0, 0, 0};
    int distance = 900000000;
    int t;

    for (int i = 0; i < *sizeK; i++) {
        stackK[i] = stackB[i];
    }


    if ((t = pepe(stackK, k1, k2, k3, sizeK, sorted_list, n, 0, 1, 2)) < distance){distance = t;order[0] =0;order[1] =1;order[2] =2;}
    if ((t = pepe(stackK, k1, k3, k2, sizeK, sorted_list, n, 0, 2, 1)) < distance){distance = t;order[0] =0;order[1] =2;order[2] =1;}
    if ((t = pepe(stackK, k2, k1, k3, sizeK, sorted_list, n, 1, 0, 2)) < distance){distance = t;order[0] =1;order[1] =0;order[2] =2;}
    if ((t = pepe(stackK, k2, k3, k1, sizeK, sorted_list, n, 1, 2, 0)) < distance){distance = t;order[0] =1;order[1] =2;order[2] =0;}
    if ((t = pepe(stackK, k3, k1, k2, sizeK, sorted_list, n, 2, 0, 1)) < distance){distance = t;order[0] =2;order[1] =0;order[2] =1;}
    if ((t = pepe(stackK, k3, k2, k1, sizeK, sorted_list, n, 2, 1, 0)) < distance){distance = t;order[0] =2;order[1] =1;order[2] =0;}

    return order;

}

int pepe(int *stackK, int k1, int k2, int k3, int *sizeK, int *sorted_list, int n, int e1, int e2, int e3)
{
    int p = 0;
    int d = 0;
    int k = k_k(stackK, sorted_list, n, e1, 1, sizeK); 
    while(p < 3)
    {
        if (stackK[0] == k1 && p++ == 0)
            k = k_k(stackK, sorted_list, n, e1, 1, sizeK);
        else if (stackK[0] == k2 && p++ == 1)
            k = k_k(stackK, sorted_list, n, e1, 1, sizeK);
        else if (stackK[0] == k3 && p == 2)
            p++;
        else if (k == -2)
        {
            reverse_rotate_K(stackK, sizeK);
        }
        else if (k == -1)
        {
            rotate_K(stackK, sizeK);
        }
        d++;
    }
    return d;
}

//Top number goes to bottom of Stack K
void rotate_K(int *stackB, int *sizeB) {
	int temp = stackB[0];
	for (int i = 0; i < *sizeB - 1; i++) {
		stackB[i] = stackB[i + 1];
	}
	stackB[*sizeB - 1] = temp;
}
//bottom number goes to top of Stack K
void reverse_rotate_K(int *stackB, int *sizeB) {
	int temp = stackB[*sizeB - 1];
	for (int i = *sizeB - 1; i > 0; i--) {
		stackB[i] = stackB[i - 1];
	}
	stackB[0] = temp;
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
