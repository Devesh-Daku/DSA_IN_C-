#include<iostream>
using namespace std;
#include "./swap.h"
#include "./BubbleSort.cpp"
#include "./InsertionSort.cpp"
#include "./SelectionSort.cpp"
#include "./QuickSort.cpp" // Todo:: Quick sort is not working , make it work : 
#include "./Merging.cpp"   // Must revice later on : 
#include "./CountSort.cpp"
#include "./BucketSort.cpp" //pending 

int main(){
    int A[] = {11 ,13 ,7 ,12 ,16 ,9 ,24 ,5 ,10 ,3 } ;
    int n = 10 ;
    BucketSort(A ,n) ;

    for(int i=0 ; i< n; i++ ) {
        cout<< A[i] << " " ;
    }
    cout << endl ;

    return 0 ;
}