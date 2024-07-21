// we will be first traversing to find smalles element in the given array 
// then keeping it to the top
// then again serching from second to last for smallest
// 8 6 3 2 5 4 
// 2 6 3 8 5 4 
// 2 3 6 8 5 4 
// 2 3 4 8 5 6 
// 2 3 4 5 8 6 
// 2 3 4 5 6 8
// total number of comparisons : n*(n-1)/2 

void SelectionSort ( int A[] , int n){
    int i,j,k;
    for(i=0;i<n;i++){
        j=A[i];
        for(j=k=i ; j< n; j++ ) {
            if(A[j]<A[k]) k = j;
        }
        Swap(&A[i], &A[k]);
    }
}

// Not adaptive . always take n^2 time 
// not stable too  , order of same value data must not be preserverd 
// selection sort do minimum number of swap 
// Selection sort intermediate passes gives useful result  . ie k passes give use k smalles element 
// 