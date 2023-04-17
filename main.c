# include "push_swap.h"


bool is_valid_int(const char *str) {
    if (str == NULL) {
        return false;
    }

    char *endptr;
    strtol(str, &endptr, 10);

    return *endptr == '\0';
}

bool has_duplicates(int *array, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            if (array[i] == array[j]) {
                return true;
            }
        }
    }
    return false;
}




int main(int argc, char *argv[]) {
    int *stackA, *stackB, sizeA[1], sizeB[1];
    int *stackCouille;
    // Check if arguments are valid
    if (argc < 2) {
        printf("Error\n");
        return 0;
    }

    // Tokenize the input if it's given as a single string
    if (argc == 2) {
        char *token = strtok(argv[1], " ");
        int count = 0;
        char *temp_argv[argc + 666]; // Assuming a maximum of 255 extra arguments

        while (token != NULL) {
            temp_argv[argc] = token;
            token = strtok(NULL, " ");
            count++;
            argc++;
        }

        // Copy the new arguments to the original argv
        for (int i = 2; i < argc ; i++) {
            argv[i] = temp_argv[i];
        }
    }

    // Check for valid integers and store them in an array
    int args_as_int[argc - 1];

    for (int i = 2; i < argc; i++) {
        if (is_valid_int(argv[i])) {
            args_as_int[i - 1] = atoi(argv[i]);
        } else {
            printf("Error: Invalid integer: %s\n", argv[i]);
            return 0;
        }
    }

    // Check for duplicates
    if (has_duplicates(args_as_int, argc - 1)) {
        printf("Error: Duplicate integers are not allowed\n");
        return 0;
    }




    //Initialize stackA and stackB
    *sizeA = argc - 1;
    *sizeB = 0;
    stackA = (int *)malloc(*sizeA * sizeof(int) * *sizeA + 2);
    stackB = (int *)malloc(*sizeA * sizeof(int) * *sizeA + 2);
    stackCouille = (int *)malloc(*sizeA * sizeof(int) * *sizeA + 2);

    //Fill stackA
    for (int i = 0; i < *sizeA; i++) {
        stackA[i] = atoi(argv[i + 1]);
        stackCouille[i] = atoi(argv[i + 1]);
    }
	
	//Sort stackA
	int *sorted_list = (int *)malloc(*sizeA * sizeof(int));
	for (int i = 0; i < *sizeA; i++) {
		sorted_list[i] = stackA[i];
	}
	merge_sort(sorted_list, 0, *sizeA - 1);

	pushSwap.stackA = stackA;
    pushSwap.stackB = stackB;
    pushSwap.sizeA = *sizeA;
    pushSwap.sizeB = *sizeB;
    pushSwap.result_to_display = (char *)malloc(99999999);
    pushSwap.sorted_list = sorted_list;
	strcpy(pushSwap.result_to_display, "");
	//Run push_swap
	push_swap(stackCouille, *sizeA);
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

    printf("\n");
	printf("number of instructions %f\n", strlen(pushSwap.result_to_display) / 3.1);
	*/
	//Free memory
	free(stackA);
	free(stackB);
	free(sorted_list);
	free(pushSwap.result_to_display);
	
	return 0;
}