# include "push_swap.h"

//Swap top two numbers in stack A
void swap_A() {
	int temp = pushSwap.stackA[0];
	pushSwap.stackA[0] = pushSwap.stackA[1]; 
	pushSwap.stackA[1] = temp;
	strcat(pushSwap.result_to_display, "sa\n");
}

//Swap top two numbers in stack B
void swap_B() {
	int temp = pushSwap.stackB[0];
	pushSwap.stackB[0] = pushSwap.stackB[1];
	pushSwap.stackB[1] = temp;
	strcat(pushSwap.result_to_display, "sb\n");
}

//Run SA and SB at the same time
void swap_both() {
	swap_A();
	swap_B();
	strcat(pushSwap.result_to_display, "ss\n");
}

//Top number goes to bottom of Stack A
void rotate_A() {
    int temp = pushSwap.stackA[0];
    int i = 0;
    while (i < pushSwap.sizeA - 1) {
        pushSwap.stackA[i] = pushSwap.stackA[i + 1];
        i++;
    }
    pushSwap.stackA[pushSwap.sizeA - 1] = temp;
    strcat(pushSwap.result_to_display, "ra\n");
}

//Top number goes to bottom of Stack B
void rotate_B() {
    int temp = pushSwap.stackB[0];
    int i = 0;
    while (i < pushSwap.sizeB - 1) {
        pushSwap.stackB[i] = pushSwap.stackB[i + 1];
        i++;
    }
    pushSwap.stackB[pushSwap.sizeB - 1] = temp;
    strcat(pushSwap.result_to_display, "rb\n");
}

//Run RA and RB at the same time
void rotate_both() {
	rotate_A();
	rotate_B();
	strcat(pushSwap.result_to_display, "rr\n");
}

//bottom number goes to top of Stack A
void reverse_rotate_A() {
    int temp = pushSwap.stackA[pushSwap.sizeA - 1];
    int i = pushSwap.sizeA - 1;
    while (i > 0) {
        pushSwap.stackA[i] = pushSwap.stackA[i - 1];
        i--;
    }
    pushSwap.stackA[0] = temp;
    strcat(pushSwap.result_to_display, "rra\n");
}

//bottom number goes to top of Stack B
void reverse_rotate_B() {
    int temp = pushSwap.stackB[pushSwap.sizeB - 1];
    int i = pushSwap.sizeB - 1;
    while (i > 0) {
        pushSwap.stackB[i] = pushSwap.stackB[i - 1];
        i--;
    }
    pushSwap.stackB[0] = temp;
    strcat(pushSwap.result_to_display, "rrb\n");
}

//Run RRA and RRB at the same time
void reverse_rotate_both() {
	reverse_rotate_A();
	reverse_rotate_B();
	strcat(pushSwap.result_to_display, "rrr\n");
}

//Send top of B to top of A
void push_A() {
    if (pushSwap.sizeB > 0)
    {
        int i = 0;
        while (i < pushSwap.sizeA) {
            pushSwap.stackA[pushSwap.sizeA - i] = pushSwap.stackA[pushSwap.sizeA - 1 - i];
            i++;
        }
        pushSwap.stackA[0] = pushSwap.stackB[0];
        pushSwap.sizeB -= 1;
        pushSwap.sizeA += 1;
        i = 0;
        while (i < pushSwap.sizeB) {
            pushSwap.stackB[i] = pushSwap.stackB[i + 1];
            i++;
        }
        strcat(pushSwap.result_to_display, "pa\n");
    }
}

//Send top of A to top of B
void push_B() {
    if (pushSwap.sizeA > 0)
    {
        int i = 0;
        while (i < pushSwap.sizeB) {
            pushSwap.stackB[pushSwap.sizeB - i] = pushSwap.stackB[pushSwap.sizeB - 1 - i];
            i++;
        }
        pushSwap.stackB[0] = pushSwap.stackA[0];
        pushSwap.sizeA -= 1;
        pushSwap.sizeB += 1;
        i = 0;
        while (i < pushSwap.sizeA) {
            pushSwap.stackA[i] = pushSwap.stackA[i + 1];
            i++;
        }
        strcat(pushSwap.result_to_display, "pb\n");
    }
}

// Calculate K
int k_k(int n, int i, int e)
{
	int k = 0;
	while (k >= 0 && k < 200)
	{
		if (pushSwap.sorted_list[n - e - i] == pushSwap.stackB[k])
		{
			//printf("\n%d", k);
			if (k <= (n - i)/2)
				k = -1; //rotate
			else
				k = -2; //reverse rotate
			//printf(" %d", k);
			break ;
		}
		k++;
	}
	if (k != -1 && k != -2)
		{
			//printf(" -- %d \n", sorted_list[n - e - i]);
			return -3;
		}
		
	return k;
}