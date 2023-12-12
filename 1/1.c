#include<stdio.h>
#include<omp.h>
#include<time.h>
#include<stdlib.h>


int Partition(int* data, int start, int end)   // Partition data
{
    int temp = data[(start+end)/2];   // Use the middle element as the pivot
    while (start < end) {
        while (start < end && data[end] >= temp) end--;   // Find the first element smaller than the pivot
        data[start] = data[end];
        while (start < end && data[start] <= temp) start++;    // Find the first element greater than the pivot
        data[end] = data[start];
    }
    data[start] = temp;   // Use the pivot as the partition line
    return start;
}

void quickSort(int* data, int start, int end)  // Parallel quicksort
{
    if (start < end) {
        int pos = Partition(data, start, end);
        #pragma omp parallel sections    // Set parallel region
        {
            #pragma omp section          // This section sorts the front part of the data
            quickSort(data, start, pos - 1);
            #pragma omp section          // This section sorts the rear part of the data
            quickSort(data, pos + 1, end);
        }
    }
}


void quickSort_single(int* data, int start, int end)  // Parallel quicksort
{
    if (start < end) {
		int pos = Partition(data, start, end);
		quickSort(data, start, pos - 1);
        quickSort(data, pos + 1, end);
    }
}


int main() {
    int n_values[] = {2, 4, 8}; // Different thread counts
    int size_values[] = {1000, 5000, 10000, 100000}; // Different data sizes

    
	for (int size_index = 0; size_index < sizeof(size_values) / sizeof(size_values[0]); ++size_index) {
		
		int size = size_values[size_index]; // Data size
        int* num = (int*)malloc(sizeof(int) * size);
        srand(time(NULL) + rand());
        for (int i = 0; i < size; i++)
            num[i] = rand();
            
        // Copy the original unsorted array for parallel sorting
        int* num_copy = (int*)malloc(sizeof(int) * size);
        for (int i = 0; i < size; i++)
            num_copy[i] = num[i];
            
        // Measure time for serial execution
        double serial_start = omp_get_wtime();
		quickSort_single(num, 0, size - 1);
        double serial_end = omp_get_wtime();
            
		for (int n_index = 0; n_index < sizeof(n_values) / sizeof(n_values[0]); ++n_index) {
            int n = n_values[n_index]; // Thread count
			
			// Copy the original unsorted array for parallel sorting
        	int* num_parallel = (int*)malloc(sizeof(int) * size);
        	for (int i = 0; i < size; i++)
            num_parallel[i] = num_copy[i];
			
            // Measure time for parallel execution
            omp_set_num_threads(n);
            double parallel_start = omp_get_wtime();
			quickSort(num_parallel, 0, size - 1);
            double parallel_end = omp_get_wtime();

            // Calculate speedup
            double serial_time = serial_end - serial_start;
            double parallel_time = parallel_end - parallel_start;
            double speedup = serial_time / parallel_time;

            // Output a summary of the test
            printf("Thread Count: %d, Data Size: %d, Running Time (Serial): %lfs, Running Time (Parallel): %lfs, Speedup: %lf\n", n, size, serial_time, parallel_time, speedup);

            // Free allocated memory
            free(num_parallel);
        }
        free(num);
        free(num_copy);
    }

    return 0;
}
