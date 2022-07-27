#include<stdio.h>

void printArray(int* A, int n){
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}

void insertionSort(int *A, int n){
    int key, j;
    // Loop for passes
    for (int i = 1; i <= n-1; i++)
    {
        key = A[i];
        j = i-1;
        // Loop for each pass
        while(j>=0 && A[j] > key){
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = key;
    }
}

void selection_sort(int *A,int n){
    int index,temp;
    printf("Running selection sort..\n");
    for(int i=0;i<n-1;i++){
        index=i;
        for(int j=i+1;j<n;j++){
            if(A[j]<A[index]){
                index=j;
        }
    }
    temp=A[i];
    A[i]=A[index];
    A[index]=temp;
}
}

void bubbleSort(int *A, int n){
    int temp;
    int isSorted = 0;
    for (int i = 0; i < n-1; i++) // For number of pass
    {
        printf("Working on pass number %d\n", i+1); 
        for (int j = 0; j <n-1-i ; j++) // For comparison in each pass
        {
            if(A[j]>A[j+1]){
                temp = A[j];
                A[j] = A[j+1];
                A[j+1] = temp; 
            }
        }  
    } 
}
void merge(int A[], int mid, int low, int high)
{
    int i, j, k, B[100];
    i = low;
    j = mid + 1;
    k = low;

    while (i <= mid && j <= high)
    {
        if (A[i] < A[j])
        {
            B[k] = A[i];
            i++;
            k++;
        }
        else
        {
            B[k] = A[j];
            j++;
            k++;
        }
    }
    while (i <= mid)
    {
        B[k] = A[i];
        k++;
        i++;
    }
    while (j <= high)
    {
        B[k] = A[j];
        k++;
        j++;
    }
    for (int i = low; i <= high; i++)
    {
        A[i] = B[i];
    }
    
}

void mergeSort(int A[], int low, int high){
    int mid; 
    if(low<high){
        mid = (low + high) /2;
        mergeSort(A, low, mid);
        mergeSort(A, mid+1, high);
        merge(A, mid, low, high);
    }
}
int partition(int A[], int low, int high)
{
    int pivot = A[low];
    int i = low + 1;
    int j = high;
    int temp;

    do
    {
        while (A[i] <= pivot)
        {
            i++;
        }

        while (A[j] > pivot)
        {
            j--;
        }

        if (i < j)
        {
            temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }
    } while (i < j);

    // Swap A[low] and A[j]
    temp = A[low];
    A[low] = A[j];
    A[j] = temp;
    return j;
}

void quickSort(int A[], int low, int high)
{
    int partitionIndex; // Index of pivot after partition

    if (low < high)
    {
        partitionIndex = partition(A, low, high); 
        quickSort(A, low, partitionIndex - 1);  // sort left subarray 
        quickSort(A, partitionIndex + 1, high); // sort right subarray
    }
}


int main()
{
   
    int n,ch;
    printf("Enter the size of the array:\n");
    scanf("%d", &n);
    int A[n];
    printf("Enter the elements of the array:\n");
    for(int i = 0; i < n; i++){
        scanf("%d", &A[i]);
    }
     printf("Before sorting:\n");
    printArray(A, n);
    printf("Choose sorting type(1,2,3,4,5):\n  1.Insertion sort \n 2. Selection sort \n 3. Bubble sort \n 4. Merge sort \n 5. Quick sort  \n");
    scanf("%d",&ch);
    printf("After sorting:\n");
    switch(ch){
        case 1:
            insertionSort(A, n);
            printArray(A, n);
            break;
        case 2:
             selection_sort(A,n);
             printArray(A, n);
             break;
        case 3:
             bubbleSort(A,n);
             printArray(A, n);
             break;
         case 4:
            mergeSort(A,0,n-1);
             printArray(A, n);
             break;
        case 5:
            quickSort(A,0,n-1);
             printArray(A, n);
             break;
        default:
            printf("Invalid operation");
            break;
    };
    
    return 0;
}