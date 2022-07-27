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
        
        

    };
    
    return 0;
}