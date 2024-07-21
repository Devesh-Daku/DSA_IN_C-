
#include <bits/stdc++.h>


using namespace std;
#define love false
#define pain true
#define isEven(x) ( (x%2==0) ? pain : love ) 

class Node {
    public: 
    int data;
    class Node *next;
    public:
    Node () {
        next = NULL;
    }
   
} *first , *last;

//for Creating a linkedlist from array
void  Create ( int a[] , int n){
    int i;
    class Node *t ;
    first = new Node;
    first->data = a[0];
    
    last = first; // last pointing same as first 
    for( i = 1; i<n ;i++) {
        t = new Node ;
        t->data = a[i];
        last->next = t; // assining the last'next = t 
        last = t; // pointing last to t
    }
}
//IterativeDisplay
void  Display(class Node *p) {
    while ( p!= NULL) {
        cout<< p->data << " ";
        p=p->next;
    }
    cout << endl;
}
//recursive display 
void  RDisplay(class Node *p){
    if(p!=NULL) {
        cout << p->data << endl;
        RDisplay(p->next);
    }
}
//recursive reverse display 
void RRDisplay(class Node *p){
    if(p!=NULL){
        RRDisplay(p->next);
        cout << p->data << endl;
    }
}
// iteratively counting node 
int Count( class Node *p){
    int count = 0;
    while ( p != NULL ){
        count++;
        p = p->next;
    }
    return count; 
}
// Recursively counting node 
int RCount(class Node *p){ return p?1+RCount(p->next):0; }
// Alternative way of recursively counting node
int RACountNode( class Node * p){
    int x = 0;
    if(p){
        x = RACountNode(p->next);
        return x+1;
    }
    else{
        return x;
    }
}
// Sum of all element in a linked list 
int Sum(class Node *p){
    int sum = 0;
    while(p!=NULL){
        sum +=p->data;
        p = p->next;
    }
    return sum;
}
// recursive sun 
int RSum( class Node *p){ return p?p->data+RSum(p->next):0; }
// maximum number in a linkedlist
int maxEle ( class Node *p) {
    int max = INT32_MIN ; 
    while(p){
        if( max < p->data ) max = p->data ; 
        p = p->next ; 
    }
    return max;
}
// recursively finding max element in linked list 
int RmaxEle ( class Node *p) {
    int x =  0 ; 
    if( p==0 ) return INT32_MIN ; 
    x = RmaxEle(p->next);
    if(x > p->data) return x ;
    else return p->data;
}
//searching linearly and recursive linearly
class Node * LinearSearch ( class Node *p , int key ){
    while(p!=NULL){
        if(key == p->data) return p;
        p= p->next;
    }
    return NULL;
}
class Node * RLinearSearch( class Node *p, int key) {
    if(p==NULL) return NULL;
    if(key == p->data) return p;
    return RLinearSearch(p->next ,key);
}

// Improved linear search
class Node * ImprovedLS ( class Node *p , int key) {
    struct Node *q;
    while ( p!=NULL ){
        if(key==p->data){
            q->next = p->next;
            p->next = first ;
            first = p ;
            return p;
        }
        q = p;
        p = q->next;
    }
    return NULL;
}

// Inserting in a node 
void Insert ( int index , int x , class Node *p) {
    if( index <0 || index > CountNode(p)) return ;

    class Node *t;
    t = new Node ;
    if(!index){
        t->next = first;
        first = t;
    }
    else {
        for(int i=0 ; i< index -1; i++ ) {
            p= p->next;
            t->next = p->next;
            p->next = t;
        }
    }
}
// Insering at last 
void InsertLast( class Node *p  , int x) {

    class Node  *t = new Node ;
        t->data = x; 
        t->next = NULL;

    if(first==NULL) {
       first = last ;
       last = t;
    }
    else {
        last->next = t;
        last = t;
        
    }
}
// Insertion in sorted list 
void InsertSortedList ( class Node *p, int x) {
    class Node *t = new Node;
    t->data = x ;
    class Node *tailing = new Node ;
    class Node *looking = new Node ;
    

    if(t->data < p->data) {
        t->next = p;
        first = t;
    }
    else {
        tailing = p;
        looking = p->next ;
        while ( looking->data < t->data){
            looking = looking->next;
            tailing = tailing->next;
        }
        tailing->next = t;
        t->next = looking;
    }
}

// Delete operation 
void DeleteNode ( class Node *p , int index) {
    // index start from 1 to n from 1 refer to first node 
    class Node *d = new Node;
    if( index <1 || index > CountNode(p)) {
        cout << "invalid deletion " << endl;

    }   
    else {

    if( index == 1 ) {
        d = p;
        p = p->next ;
        first = p;
        delete d;
    }
    else {
        class Node *tail = new Node;
        tail = p;
        p = p->next;
        d=p;
        p = p->next;
        index--;
        while ( --index ){
            tail = d;
            d = p;
            p = p->next;
            
        }

        tail->next = d ;
        delete d ;

    } 
    }
}
int AlternateDelete( class Node *p , int index) {
    class Node *q;
    int x = -1;
    if( index < 1 || index > CountNode(p)) return -1;
    if( index ==1 ) {
        q = first ;
        x = first->data;
        first = first->next;
        delete q;
        return x;
    }
    else {
        for(int i=0 ; i< index -1 ; i++ ) {
            q = p;
            p = p->next;
        }
        q->next = p->next ;
        x = p->data;
        delete p;
        return x;
    }
}
// check if sorted 
bool ifSorted( class Node *p){
    int x = INT32_MIN;
    while ( p != NULL ){
        if( x > p->data) return love;
        x = p->data;
        p = p->next;
    }
    return pain;
}
// remove duplicate from sorted linked list 
void RemoveDuplicate( class Node *p){
    class Node *q;
    q = p->next ;
    while ( q != NULL ) {
        if(q->data == p->data) {
            q = q->next;
            delete p->next;
            p->next = q;
        }
        else {
            p = p->next;
            q = q->next;
        }
    }
}
// reversing a linked list 
void ReverseListByArray ( class Node *p){
    // by array copying ;
    int A[CountNode(p)];
    int i = 0;
    while(p != NULL) {
        A[i] = p->data;
        p = p->next;
        i++;
    }
    i--;
    p = first;
    while ( p!=NULL ){
        p->data = A[i--];
        p = p->next;
    }
}
void ReverseListByPointer( class Node *p){
    // by sliding pointer ;
    // we will have three contineous pointer pointing on adjacent node 
    class Node *r, *q;
    q = NULL;
    r = NULL;
    last = p;
    while ( p!=NULL) {
        //sliding 
        r = q; 
        q = p;
        p = p->next;
        //reversing the link
        q->next = r;
    }

    first = q;
}
void RecursiveReverse( class Node *q, class Node *p ) {
    if(p!=NULL){
        RecursiveReverse( p , p->next);
        p->next = q;
    }
    else first = q;
}
// Linked List appending , concat 
void Concat(class Node *q, class Node *p){
    while ( q!=NULL) q = q->next;
    q->next = p;
}


int main() {
    int a[] = {1,1,1,2,2, 3, 3, 3,4,5,5,6,6};
    
    Create(a,13);
    // Display( first);
    // RDisplay( first);
    // RRDisplay( first);
    // cout<<endl;
    cout << CountNode( first) ;
    cout << endl << RCountNode( first) <<endl;
    // cout << endl << RACountNode(first);
    // cout << endl;
    // SumOfAllNodeData( first );
    // cout << endl ;
    // cout << RSumOfAllNodeData(first);
    // cout << endl; 
    // cout << maxEle( first ) ; 
    // cout << endl;
    // cout << RmaxEle( first );
    // cout <<endl;
    // class Node * temp;
    // temp = ImprovedLS(first , 7);
    // if(temp) cout<< temp->data <<endl;
    // else cout << "key not found ";

    // cout << endl;

    // Display(first);
    // temp = ImprovedLS(first , 12);
    // cout << endl;
    // InsertLast( first , 2);
    
    // Display(first );
    // InsertSortedList(first, 4);
    // Display(first);

    // AlternateDelete(first , 1);
    // Display(first);

    // cout << ifSorted(first) << endl;
    // Display(first);
    // RemoveDuplicate(first);
    // Display(first);

    // ReverseListByArray(first) ;
    // Display(first);

    // ReverseListByPointer(first);
    // Display(first);
 
    // RecursiveReverse(NULL,first) ;
    // Display(first);
    

    
    return 0;
}