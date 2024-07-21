// combining two list and merging them into sorted order 


#include<iostream>
using namespace std;

int* Merging(int  A[] , int n,int  B[], int m){
    int *c ;
    c = new int [n+m];
    int i=0,j=0,k=0;

    

    while(i<n || j<m){
        if(i>=n && j<m) c[k++] = B[j++];
        else if(j>=m && i<n) c[k++] = A[i++];
        else if(A[i]<B[j]) c[k++] = A[i++];
        else c[k++] = B[j++];

    }

    return c;
}

// function to merge two different array given in one array one by one 
void Merging_one(int A[], int l,int m, int h) {
    // l minimum length :
    // the two array inside a must take differentiate  at the middle :
    int i = l , j = m+1, k = l , B[h+1];
    int mid = m;
    int n = h;
    while( i<=mid && j<=h ){
        if(A[i]<A[j]) B[k++] = A[i++];
        else B[k++] = A[j++];
    }
    for(; i<=mid ;i++) B[k++] = A[i];
    for(; j<=h  ;j++) B[k++] = A[j];
    for(i=l; i<=h ;i++) A[i] = B[i];
}
//recursive merge 

void RecursiveMerge(int A[], int l, int h){
    if(l<h){
        int mid = (l+h)/2;          //1
        RecursiveMerge(A,l,mid);     //2
        RecursiveMerge(A,mid+1,h);   //3
        Merging_one(A,l,mid,h); //4
    }
}
// merging is done in postorder : 
// take nLogn time 


// example merging four list : then merging two tow list then then again merging : called two way merging 
// assume A have 8 element and each   one element form a list having one element  : 
// it is like merging 8 list each of with one element :
// forming pairs from one to two by merging one one lists  : 
// so on till we merge each list : 
// will sort that array A 
// time complexity is nLog(n) : 
// so form a new meathod for sorting called merge sort : 
// Iterative version of merge sort 
void ImergeSort(int A[] , int n){
    int p,i,l,mid,h;
    for(p=2;p<=n;p=p*2){
        for( i=0 ; i+p-1<n; i +=p) {
            l = i;
            h = i+p-1;
            mid = l+h;
            Merging_one(A,l,mid/2,h);
        }
    }
    if(p/2 < n) Merging_one(A,0,p/2-1,n-1);
}






// now merging two list given by just one array A 
// so making this to just tow two elements will lead us to merge sort technique to sort an array 
