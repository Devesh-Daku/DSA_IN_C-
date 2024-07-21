// Insertion sort is based on the technique in which insertion of a key in a sorted array or linked list 
// assume that the array given to you is a array of element to be inserted in a empty array in sorted way
// 8 | 5 7 3 2 0th pass 
// 8 5 | 7 3 2 first pass 
// 5 8 | 7 3 2 
// 5 8 7 | 3 2 second pass
// 5 7 8 | 3 2 
// 5 7 8 3 | 2 third pass 
// 5 7 3 8 | 2
// 5 3 7 8 | 2 
// 3 5 7 8 | 2
// 3 5 7 8 2 | fourth pass
// 3 5 7 2 8
// 3 5 2 7 8
// 3 2 5 7 8 
// 2 3 5 7 8 
// total number of pass n-1 
// total comparison n*(n-1)/2 
// total max swap   n*(n-1)/2

void InsertionSort(int A[] , int n){

    for(int i=1 ; i< n; i++ ) {
        int j = i-1;
        int x = A[i];
        while(j> -1 && A[j] > x){
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = x;
    }
}

// insertion sort is adaptive by nature : while bubble sort is modified to be adaptive 
// min swap On1 max On2 
// stable too 