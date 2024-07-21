// Basic concept behind Quick sort 
// element is in sorted position in an array if all the element below than it are smaller : and after that all elemnet are larger 
// example 
// 10 30 20 70 40 90 80 :: 10 is in sorted position 
// 80 70 40 30 20 10 90 :: 90 is in sorted position 
// 40 30 20 50 90 70 80 :: 50 is in sorted position : element before 50 are less than 50 and element after 50 are grater then 50


// coding quick sort 
int partition(int A[] , int l , int h){
    int pivot = A[l] ;
    int i = l , j = h;
    do{
        do{
            i++;
        }while(A[i] <= pivot);
        do{
            j--;
        }while(A[j] < pivot);
        if(i<j) Swap(&A[i],&A[j]);
    }while(i<j);

    Swap(&A[l],&A[j]);
    return j;
}


void QuickSort(int A[], int l , int h){
    int j;
    if(l<h){
        j = partition(A,l,h);
        QuickSort(A,l,j);
        QuickSort(A,j+1,h);
    }
}
