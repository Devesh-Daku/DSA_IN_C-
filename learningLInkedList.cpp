#include<iostream>
using namespace std;

class Node {
    public: 
    int data;
    class Node *next;
    public:
    Node () {
        next = NULL;
    }
   
} *first;
void  Create ( int a[] , int n){
    int i;
    class Node *t, *last ;
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
void  Display(class Node *p) {
    while ( p!= NULL) {
        cout<< p->data << endl;
        p=p->next;
    }
}
int main() {
    int a[] = {3,5,7,10,15};
    
    Create(a,5);
    Display( first);
    return 0;
}