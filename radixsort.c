    // C implementation of Radix Sort
    #include<stdio.h>
    #include<stdlib.h>
    // This  function gives maximum value in array[]
    int getMax(int A[], int n)
    {
        int i;
        int max = A[0];
        for (i = 1; i < n; i++){
            if (A[i] > max)
                max = A[i];
        }
        return max;
    }
    // Main Radix Sort sort function
    void radixSort(int A[], int n)
    {
        int i,digitPlace = 1;
        int result[n]; // resulting array
        // Find the largest number to know number of digits
        int largestNum = getMax(A, n);
        //we run loop until we reach the largest digit place
        while(largestNum/digitPlace >0){
            int count[10] = {0};
             //Store the count of "keys" or digits in count[]
            for (i = 0; i < n; i++)
                count[ (A[i]/digitPlace)%10 ]++;
            // Change count[i] so that count[i] now contains actual
            //  position of this digit in result[]
            //  Working similar to the counting sort algorithm
            for (i = 1; i < 10; i++)
                count[i] += count[i - 1];
            // Build the resulting array
            for (i = n - 1; i >= 0; i--)
            {
                result[count[ (A[i]/digitPlace)%10 ] - 1] = A[i];
                count[ (A[i]/digitPlace)%10 ]--;
            }
            // Now main array A[] contains sorted
            // numbers according to current digit place
            for (i = 0; i < n; i++)
                A[i] = result[i];
                // Move to next digit place
                digitPlace *= 10;
        }
    }
    // Function to print an array
    void printArray(int A[], int n)
    {
        int i;
        for (i = 0; i < n; i++)
        printf("%d ", A[i]);
        printf("\n");
    }
    // Driver program to test above functions
    int main()
    {
        int a[] = {209,3,48,91,66,101,30,795};
        int n = sizeof(a)/sizeof(a[0]);
        printf("Unsorted Array: ");
        printArray(a, n);
        radixSort(a, n);
        printf("Sorted Array: ");
        printArray(a, n);
        return 0;
    }
