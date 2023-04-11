# include "push_swap.h"

int main(int argc, char *argv[]) {
	int *stackA, *stackB, sizeA[1], sizeB[1];
	char *result_to_display;
	
	//Check if arguments are valid
	if (argc < 2) {
		printf("Error\n");
		return 0;
	}
	
	//Check if all arguments are int
	for (int i = 1; i < argc; i++) {
		if (atoi(argv[i]) == 0 && argv[i][0] != '0') {
			printf("Error : not int %c\n", argv[i][0]);
			return 0;
		}
	}
	
	//Check if there are duplicates
	for (int i = 1; i < argc; i++) {
		for (int j = i + 1; j < argc; j++) {
			if (atoi(argv[i]) == atoi(argv[j])) {
				printf("Error\n");
				return 0;
			}
		}
	}
	
	//Initialize stackA and stackB
	*sizeA = argc - 1;
	*sizeB = 0;
	stackA = (int *)malloc(*sizeA * sizeof(int) * *sizeA);
	stackB = (int *)malloc(*sizeA * sizeof(int) * *sizeA);
	
	
	//Fill stackA
	for (int i = 0; i < *sizeA; i++) {
		stackA[i] = atoi(argv[i + 1]);
	}
	
	//Sort stackA
	int *sorted_list = (int *)malloc(*sizeA * sizeof(int));
	for (int i = 0; i < *sizeA; i++) {
		sorted_list[i] = stackA[i];
	}
	merge_sort(sorted_list, 0, *sizeA - 1);
	
	//Initialize result_to_display
	result_to_display = (char *)malloc(999999);
	strcpy(result_to_display, "");

	pushSwap.stackA = stackA;
    pushSwap.stackB = stackB;
    pushSwap.sizeA = *sizeA;
    pushSwap.sizeB = *sizeB;
    pushSwap.result_to_display = result_to_display;
    pushSwap.sorted_list = sorted_list;

	//Run push_swap
	push_swap();
	printf("%s", pushSwap.result_to_display);
	/*
	//Display result
    printf("\n");
    printf("stackA: ");
    for (int i = 0; i < pushSwap.sizeA; i++) {
        printf("%d ", pushSwap.stackA[i]);
    }
    printf("\n");

    printf("stackB: ");
    for (int i = 0; i < pushSwap.sizeB; i++) {
        printf("%d ", pushSwap.stackB[i]);
    }
    printf("\n");

    printf("sizeA: %d\n", pushSwap.sizeA);
    printf("sizeB: %d\n", pushSwap.sizeB);
    //printf("result_to_display: %s\n", pushSwap.result_to_display);

    printf("sorted_list: ");
    for (int i = 0; i < pushSwap.sizeA + pushSwap.sizeB; i++) {
        printf("%d ", pushSwap.sorted_list[i]);
    }
    printf("\n");*/
	
	//Free memory
	free(stackA);
	free(stackB);
	free(sorted_list);
	free(result_to_display);
	
	return 0;
}