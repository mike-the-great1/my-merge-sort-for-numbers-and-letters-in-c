//c implementation of merge sort for both numbers and letters
#include <stdio.h>
#include <stdlib.h>

// Merge two subarrays of arr[].
// First subarray is arr[left..mid]
// Second subarray is arr[mid+1..right]
void merge(int arr[], int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Create temporary arrays
    int leftArr[n1], rightArr[n2];

    // Copy data to temporary arrays
    for (i = 0; i < n1; i++)
        leftArr[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        rightArr[j] = arr[mid + 1 + j];

    // Merge the temporary arrays back into arr[left..right]
    i = 0;
    j = 0;
    k = left;
    while (i < n1 && j < n2) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k] = leftArr[i];
            i++;
        } else {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of leftArr[], if any
    while (i < n1) {
        arr[k] = leftArr[i];
        i++;
        k++;
    }

    // Copy the remaining elements of rightArr[], if any
    while (j < n2) {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
}

// The subarray to be sorted is in the index range [left..right]
void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        // Calculate the midpoint
        int mid = left + (right - left) / 2;

        // Sort first and second halves
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        // Merge the sorted halves
        merge(arr, left, mid, right);
    }
}

int main() {
    char choose;
    printf("Do you want numbers or letters sorted?\nReply with 'n' for numbers or 'l' for letters: ");
    scanf(" %c", &choose); // Added space before %c to consume any leftover whitespace

    if (choose == 'n') {
        int i, d;
        printf("Enter the number of elements to be sorted: ");
        scanf("%d", &d);

        int arr[d]; // Corrected the array declaration
        for (i = 0; i < d; i++) {
            printf("Enter element[%d]: ", i);
            scanf("%d", &arr[i]);
        }

        int n = sizeof(arr) / sizeof(arr[0]);
        for (i = 0; i < n; i++)
            printf("%d ", arr[i]);
        printf("\n");

        // Sort arr using merge sort
        mergeSort(arr, 0, n - 1);

        printf("Your sorted numbers are: ");
        for (i = 0; i < n; i++)
            printf("%d ", arr[i]);
        printf("\n");

    } else if (choose == 'l') {
        int i, o;
        printf("Enter the number of letters you want sorted:\n");
        scanf("%d", &o);

        char arr[o];
        int arr2[o];

        printf("Enter the letters you want sorted:\n");
        for (i = 0; i < o; i++) {
            // Use a space before %c to skip any whitespace characters
            scanf(" %c", &arr[i]);
        }

        printf("Your characters in the array are: \n");
        for (i = 0; i < o; i++) {
            printf("%c\n", arr[i]);
        }
        printf("\n");

        // Convert characters to ASCII values
        for (i = 0; i < o; i++) {
            arr2[i] = (int) arr[i];
        }

        printf("Stored ASCII values in arr2: \n");
        for (i = 0; i < o; i++) {
            printf("%d\n", arr2[i]);
        }
        printf("\n");

        int n = sizeof(arr2) / sizeof(arr2[0]);

        // Sort arr2 using mergeSort
        mergeSort(arr2, 0, n - 1);

        printf("Your sorted numbers are: \n");
        for (i = 0; i < n; i++) {
            printf("%d\n", arr2[i]); 
        }
        printf("\n");

        // Convert sorted ASCII values back to characters
        for (i = 0; i < o; i++) {
            arr[i] = (char) arr2[i];
        }

        printf("Corresponding letters are: \n");
        for (i = 0; i < o; i++) {
            printf("%c\n", arr[i]);
        }

    }
    return 0;
}
