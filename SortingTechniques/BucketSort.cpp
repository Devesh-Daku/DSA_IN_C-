// do similar thing like count sort 
// find max element creat an array of pointer of the maximum size element :
// now trace a and find the index : and add a node containing the element and next node wich is null 
// if again found same element then attach to the next of previous element 
// that node called bins 
// time complexity is order of n: 
#include<iostream>
using namespace std;
class Node {
    public:
    int val=0;
    Node* next=0;
    Node(int x =0){
        val = x;
    }
};

void BucketSort(int A[],int n){
    int max = A[0];
    for(int i=1 ; i< n; i++ ) if(A[i]>A[0]) max = A[i];

    Node **Bins;
    Bins = new Node*[max+1];
  
    for(int i=0 ; i< max+1; i++ ) {
        Bins[i] = NULL;
    }

    for(int i=0 ; i<n ; i++ ) {
        Node *t = new Node(A[i]) ;
        Node *p = Bins[A[i]];
        if(!p){p = t;}
        else {
            while(p->next){p= p->next;}
            p->next = t;
        }
    }

    int j=0;
    for(int i=0 ; i< max+1; i++ ) {
        Node *p = Bins[i];
        
        if(p) {
            Node*t = p;
            while(t){
                
                while(t->next){t= t->next;}
                A[j++] = t->val;
                delete t;

            }
        }
    }
}
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