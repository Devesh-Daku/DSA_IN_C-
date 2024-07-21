

//not while using some data type T define a default value of T below as 
#define DEFAULT_T 0; // If T is integer , or long integer ...


template <class T>
class SLLNode {
    public :
    T data ;
    SLLNode *next = NULL;
    SLLNode() {this->data = DEFAULT_T;}
    SLLNode(T data ) { this->data = data;}
};

template <class T>
class SinglyLL {
    SLLNode<T>* first = NULL;
    SLLNode<T>* last = NULL;
    int length = 0;
    
    public: 
    SinglyLL( T A[] ,int n);
    ~SinglyLL();
    void Display();

    void InsertFirst( T );
    void InsertLast ( T );
    void Insert (T ,int );
    T DeleteFirst() ;
    T DeleteLast () ;
    T Delete( int ) ;


    int Lenght() {return length;}
};


template <class T>
SinglyLL<T> :: SinglyLL(T A[],int n) {
    last = first = new SLLNode<T>(A[0]);
    for(int i=1 ; i< n; i++ ) {
        SLLNode<T> *t = new SLLNode<T>(A[i]);
        last->next = t;
        last = t;
    }
    length += n;
}
template <class T>
SinglyLL<T> :: ~SinglyLL(){
    SLLNode<T> *p ;
    while(first){
        p = first;
        first = first->next;
        delete p;
    }
    first = last = NULL;
    length = 0;
}
template <class T>
void SinglyLL<T> :: Display(){
    SLLNode<T> *p = first;
    while(p){
        // the below represnetation can be changed according to the need of T
        cout << p->data << " " ;
        p = p->next;
    }
    cout << endl;
}

template <class T>
void SinglyLL<T> :: InsertFirst(T x) {
    SLLNode<T> *t = new SLLNode<T>(x);
    if(!t) {
        cout << "memory error while creating new node" << endl;
        return ;
    }
    t->next = first;
    first = t;
    length++;
}
template <class T>
void SinglyLL<T> :: InsertLast(T x) {
    SLLNode<T> *t = new SLLNode<T>(x);
    if(!t) {
        cout << "memory error while creating new node" << endl;
        return ;
    }
    last->next = t;
    last = t;
    length++;
}
template <class T> 
void SinglyLL<T> :: Insert(T x, int index){
    if(index <0 || index > length  ) {
        cout << "invalid index , Enter index between " << 0 << " to " << length << endl;
        
    }
    else if(index == 0 ) InsertFirst ( x );
    else if(index == length) InsertLast( x );
    else {
        SLLNode<T> *t = new SLLNode<T>(x);
        if(!t) {
            cout << "memory error while creating new node" << endl;
            return ;
        }
        SLLNode<T> *p = first;
        while(--index){
            p = p->next;
        }
        t->next = p->next;
        p->next = t;
        length++;
    }
    
}

template <class T>
T SinglyLL<T> :: DeleteFirst() {
    SLLNode<T> *t = first;
    first = first->next;
    T a = t->data;
    delete t;
    length--;
    return a; 
}
template <class T>
T SinglyLL<T> :: DeleteLast() {
    int i = length -1 ;
    SLLNode<T> *t = first;
    SLLNode<T> *p = last;
    T a = p->data;
    delete p;
    length--;
    while(--i){
        t = t->next;
    }
    last = t;
    last->next = NULL;
    return a;
}
template <class T>
T SinglyLL<T> :: Delete(int i) {
    if( i < 0 || i >= length){
        cout << "Invalid index input , input index from 0 to "<< length-1 << endl;
        return DEFAULT_T;
    }
    if( i==0) return DeleteFirst();
    if( i==length-1) return DeleteLast();
    
    SLLNode<T> *t = first;
    while(--i){
        t = t->next;
    }
    SLLNode<T> *p = t->next;
    t->next = p->next;
    T a = p->data;
    delete p;
    length--;
    return a;

}


