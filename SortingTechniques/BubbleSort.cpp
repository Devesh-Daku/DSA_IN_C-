// it will bubble around one element and take it to the end as possible to make its position sorted 

// 8 5 7 3 2 
// 5 8 7 3 2 
// 5 7 8 3 2
// 5 7 3 8 2
// 5 7 3 2 8 now 8 reached end it will pass : the array to beginning : now only one element is sorted 
// 4 swaps performed . 4 comparison done 
// second pass begin 
// 5 3 7 2 8
// 5 3 2 7 8
// now 7 is no more sorted atleast for now : again begin next pass : 
// 3 swap performed : 3 comparison made 
// 3 5 2 7 8
// 3 2 5 7 8 
// 2 comparison 2 swaps 
// 2 3 5 7 8
// 1 comparison 1 swap : 

// look again 
// 8 5 7 3 2 
// 5 8 7 3 2 
// 5 7 8 3 2
// 5 7 3 8 2
// 5 7 3 2 8
// 5 3 7 2 8
// 5 3 2 7 8
// 3 5 2 7 8
// 3 2 5 7 8 
// 2 3 5 7 8

// for n element n-1 passes will possible 
// order of N^2 ( number of swap and comparison are n(n-1)/2 )
// affect is just like bubbles in water , the heaviest stones goes down first as possible as it fond 
// hence bubble sort prefer the largest value to be sorted : ie , sorting order is Descending : 
// so if we need first 3 largest element just perform 3 passes and stop : 
// minimum time taken by bubble sort is order(n) and maximum time taken is order(n*n)
// hence Bubble sort Adaptive by introducing a flag varible 
// Also Buble sort is Stable too . can be checked by any example of array having 
void BubbleSort( int A[] , int n) {
    int flag = 0;
    for( int i =0 ;i<n-1 ;i++){
        for(int j=0 ; j< n-1-i; j++ ) {
            if(A[j]>A[j+1]) {
                Swap(&A[j],&A[j+1]);
                flag++;
            }
        }
        if(!flag)break;
    }
}