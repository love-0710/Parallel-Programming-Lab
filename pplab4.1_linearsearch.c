#include<stdio.h>
#include<stdlib.h>
#include<omp.h>

// Serial version of linear search
void serial_linearsearch(int *arr, int l, int key) {
    int i;
    for (i = 0; i < l; i++) {
        if (arr[i] == key) {
            printf("ELEMENT FOUND AT INDEX %d (Serial)\n", i);
            return; // Return if found
        }
    }
    printf("element not found (Serial)\n");
}

// Parallel version of linear search
void parallel_linearsearch(int *arr, int l, int key) {
    int found = 0; // Flag to indicate if the element is found

    #pragma omp parallel for
    for (int i = 0; i < l; i++) {
        if (found) continue; // If element is already found, skip further iterations
        if (arr[i] == key) {
            #pragma omp critical // Ensure only one thread modifies 'found'
            {
                if (!found) {
                    printf("ELEMENT FOUND AT INDEX %d (Parallel)\n", i);
                    found = 1; // Set the flag to indicate element found
                }
            }
        }
    }

    if (!found) {
        printf("element not found (Parallel)\n");
    }
}


int main() {
    double start, end;
    int l = 10000, key;
    char x[10];
    int *arr = (int*)malloc(l * sizeof(int));
    FILE *f = fopen("numbers.txt", "r");

    if (f == NULL) {
        printf("File not found or unable to open.\n");
        return 1;
    }

    int i = 0;
    while (fscanf(f, "%s", x) != EOF && i < l) {
        arr[i] = atoi(x);
        i++;
    }
    fclose(f);

    printf("enter element to be searched\n");
    scanf("%d", &key);

    // Serial version
    start = omp_get_wtime();
    serial_linearsearch(arr, l, key);
    end = omp_get_wtime();
    printf("Serial execution time = %f\n", end - start);

    // Parallel version
    start = omp_get_wtime();
    parallel_linearsearch(arr, l, key);
    end = omp_get_wtime();
    printf("Parallel execution time = %f\n", end - start);

    free(arr); // Free dynamically allocated memory
    return 0;
}
