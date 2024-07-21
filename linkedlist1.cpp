#include<iostream>

using namespace std;
class Node {
    public:
    int data;
    class Node *next;

    void Create (int a[] , int n);
    void Display();
};
void Node :: Create ( int a[], int n) {
    this->data = a[0];
    class Node *t,*last;
    last = new Node ;
    
    for(int i=1 ; i< n; i++ ) {
        t=new Node;
        t->data = a[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}
void Node :: Display(){
    while(this){
        cout<< this->data << endl;
        this = this->next;
    }
}
int main () {
    int A[] = {3,5,7,10,15,8,12,20};
    class Node first;
    first.Create(A,8);

    return 0;
}