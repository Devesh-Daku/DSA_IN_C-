#include<iostream>
using namespace std;
#define COMMENTSON if(true)
#define PINC(p) p=p->next

class Node {
    public: 
        int data;
        Node *next;
        Node(int x = 0){this->data = x; next = NULL;}
};

class LinkedList {
    private :
        Node *first;
    public:
        LinkedList(){ first = NULL; COMMENTSON cout << "Linkde List initiated " << endl;}
        LinkedList( int A[] , int n) ;
        ~LinkedList();

        void Display();
        void Insert( int  , int );
        int Delete(int );
        int Length();
        int Sum();
        int MaxElement();
        Node* LSearch(int );
        void InsertSortedList (  int x);
};

LinkedList :: LinkedList(int A[], int n){
    Node *last ,*t;
    
    first = new Node;
    first->data = A[0];
    first->next = NULL;
    last=first;
    for(int i=1 ; i< n; i++ ) {
        t = new Node;
        t->data = A[i];
        last->next = t;
        last=t;
    }
    
    COMMENTSON cout << "LinkedList declared and initilized" << endl;
}
LinkedList :: ~LinkedList () {
    Node *p = first;
    while(first){
        PINC(first);
        delete p ;
        p = first;
    }
    
    COMMENTSON cout << "LinkedList destroyed "<<endl;
}
void LinkedList:: Display() {
    Node *p = first;
    while ( p){
        cout << p->data << " ";
        PINC(p);
    }
    cout<<endl;

}
int LinkedList:: Length(){
    Node *p = first;
    int count =0;
    while(p){
        count++;
        PINC(p);
    }
    return count;
}
int LinkedList:: Delete(int index) {

    Node *p = first ;
    int x = NULL;
    if(index ==1){
        PINC(first);
        x = p->data;
        delete p;

    }
    else if(index >0 && index < Length()){
        Node *t ;
        for(int i=1 ; i< index+1; i++ ) {
            t = p;
            PINC(p);
        }
        t->next = p->next;
        x = p->data;
        delete p;
    }

    return x;
}
void LinkedList:: Insert(int index,int x){
    Node *p = first;
    if( index == 0 ){
        Node *t = new Node;
        t->data = x;
        t->next = first;
        first = t;
        COMMENTSON cout<<"addead a node in front of Linked List"<<endl;
    }
    else if( index > 0 || index < this->Length()) {
        Node *t = new Node;
        for(int i=0 ; i< index; i++ ) {
            t=p;
            PINC(p);
        }
        Node *n = new Node;
        n->data = x;
        t->next = n;
        n->next = p;
        COMMENTSON cout<< "added a node between "<< t->data << " and " << p->data <<endl;
    }
    else {
        cout << "Not valid Index" << endl;
    }
}
int LinkedList:: Sum(){
    Node *p = first;
    int sum =0;
    while(p){
        sum += p->data;
        PINC(p);
    }
    return sum;
}
int LinkedList:: MaxElement(){
    Node *p = first;
    int max = INT32_MIN;
    while(p){
        if(max<p->data){
            max = p->data;
        }
        PINC(p);
    }
    return max;
}
Node* LinkedList:: LSearch(int key){
    Node *p = first;
    while(p){
        if(p->data == key) return p;
        PINC(p);
    }
    return NULL;
}
void LinkedList :: InsertSortedList ( int x) {
    Node *t = new Node(x);
    Node *p = first;
    Node *tailing = new Node ;
    Node *looking = new Node ;
    

    if(t->data < p->data){
        t->next = p;
        first = t;
    }
    else{
        tailing = p;
        looking = p->next ;
        while(looking && looking->data < t->data){
            tailing = looking;
            looking = looking->next;
        }
        tailing->next = t;
        t->next = looking;
    }
}


int main(){

    int A[] = {1,2,3,4,5};
    LinkedList l(A,5);
    l.Display();
    cout << l.Length() << endl;
    cout << l.Delete(2)<< endl;
    l.Display();
    cout << l.Length() << endl;
    l.Insert(2,3);
    l.Display();
    l.Insert(0,10);
    l.Delete(1);
    l.Display();
    l.InsertSortedList(7);
    l.Display();
    l.InsertSortedList(6);
    l.Display();
    cout << l.Sum() <<endl;
    cout << l.MaxElement() <<endl;
    return 0;
}
