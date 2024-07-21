// easiest : fastest : index based : but consumes a quite good amount of memory 
// create a count array : having size equal to maximum element of array A 
// say A : 6 3 9 10 15 6 8 12 3 6
// So count will be of size 16 initilized with all zeros : (0 to 15)
// just like hash map : traverse through a and inciment count[a[[i]]]++;
// so count will look like : 
// 0 0 0 2 0 0 3 0 1 1 |1  0  1  0  0  1 : 
// 0 1 2 3 4 5 6 7 8 9|10 11 12 13 14 15
// now traverse back through c and rewrite element back to A 
// then will have a sorted array : 
// time taken is O(n)  : 

void CountSort(int A[],int n){
    int max = A[0];
    for(int i=1 ; i< n; i++ ) if(A[i]>A[0]) max = A[i];
    
    int Count[max+1]={0};
    for(int i=0 ; i< n; i++ ) Count[A[i]]++;
    
    int j = 0;
    for(int i=0 ; i< max+1; i++ ) while(Count[i]--){A[j++] = i;}

}