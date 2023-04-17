

# include <stdio.h>
# include <limits.h>

# include "push_swap.h"

int *best_combination(int k1, int k2, int k3, int n, int size){


    int *stackK = malloc(9000000);
    int sizeK[1];  
    *sizeK = size;
    static int order[3] = {0, 1, 3};
    int distance = 90000;
    int t;

    for (int i = 0; i < *sizeK; i++) {
        stackK[i] = pushSwap.stackB[i];
    }
    if ((t = pepe(stackK, k1, k2, k3, sizeK, n, 0, 1, 2)) < distance){distance = t;order[0] =0;order[1] =1;order[2] =2;}
    if ((t = pepe(stackK, k1, k3, k2, sizeK, n, 0, 2, 1)) < distance){distance = t;order[0] =0;order[1] =2;order[2] =1;}
    if ((t = pepe(stackK, k2, k1, k3, sizeK, n, 1, 0, 2)) < distance){distance = t;order[0] =1;order[1] =0;order[2] =2;}
    if ((t = pepe(stackK, k2, k3, k1, sizeK, n, 1, 2, 0)) < distance){distance = t;order[0] =1;order[1] =2;order[2] =0;}
    if ((t = pepe(stackK, k3, k1, k2, sizeK, n, 2, 0, 1)) < distance){distance = t;order[0] =2;order[1] =0;order[2] =1;}
    if ((t = pepe(stackK, k3, k2, k1, sizeK, n, 2, 1, 0)) < distance){distance = t;order[0] =2;order[1] =1;order[2] =0;}
    free(stackK);
    return order;

}

int pepe(int *stackK, int k1, int k2, int k3, int *sizeK, int n, int e1, int e2, int e3)
{
    int p = 0;
    int d = 0;
    int k = k_k_k(stackK, pushSwap.sorted_list, n,1,e1, sizeK); 
    int b = 0;


    while(p < 3)
    {
        // print k1, k2, k3
        if (stackK[0] == k1 && p == 0)
        {
            k = k_k_k(stackK, pushSwap.sorted_list, n, 1, e2, sizeK);
            //printf("k: %d ", k);
            p++;
        }         
        if (stackK[0] == k2 && p == 1)
        {
            k = k_k_k(stackK, pushSwap.sorted_list, n, 1, e3, sizeK);
            //printf("k: %d ", k);
            p++;
        }
        if (stackK[0] == k3 && p == 2)
        {
            p++;
        }
        if (k == -2)
        {
            reverse_rotate_K(stackK, sizeK);
            b--;
        }
        if (k == -1)
        {
            rotate_K(stackK, sizeK);
            b++;
        }
        if (k == -3)
        {
            break ;
        }
        d++;

    }
    
    while (b < 0)
    {
        rotate_K(stackK, sizeK);
        b++;
    }
        
    while (b > 0)
    {
        reverse_rotate_K(stackK, sizeK);
        b--;
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

int k_k_k(int *stackK, int *sorted_list, int n, int i, int e, int *sizeB)
{
    int k = 0;
    int target_index = -1;
    
    // Find the index of the target number in the stack
    for (k = 0; k < n; k++)
    {
        if (sorted_list[n - e - i] == stackK[k])
        {
            target_index = k;
            break;
        }
    }
    
    // If the target number is not found in the stack, return -3
    if (target_index == -1)
    {
        return -3;
    }
    
    // Determine whether to rotate or reverse rotate based on the target index
    if (target_index <= (n - i) / 2)
    {
        return -1; // rotate
    }
    else
    {
        return -2; // reverse rotate
    }
}