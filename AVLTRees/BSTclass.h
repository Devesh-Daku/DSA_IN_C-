// basic header and defination used for later 
#include<iostream>
using namespace std;
#define Plft(p) p = p->lft
#define Prht(p) p = p->rht

// a template class for circular queues array based implementation
template <class T >
class CQueue {
    private : 
        int size=5;
        int front = 0;
        int rear = 0;
        T *Q;
    public : 
        CQueue(){ this->Q = new T [this->size];}
        CQueue(int size){ this->size = size; Q = new T [this->size]; }
        void Display();
        void enqueue(T);
        T dequeue();
        bool isEmpty(){ return (front==rear);}
};
template<class T>
void CQueue<T> :: Display(){
    int i = front+1;
    do{
        cout << Q[i] << " ";
        i = (i+1)%size;
    }while( i != (rear+1)%size);
    cout << endl;
}
template<class T>
void CQueue<T> :: enqueue(T x) {
    if((rear+1)%size == front ) cout << "Queue is full" << endl;
    else {
        rear = (rear+1)%size;
        Q[rear] = x;
    }
}
template<class T>
T CQueue<T> :: dequeue(){
    T x = NULL;
    if(front == rear) cout << "Queue is empty" << endl;
    else {
        front = (front+1)%size;
        x = Q[front];
    } 
    return x;
}

// A template class for Stack objects array based implementation
template <class T>
class Stack{
    public:
    T *A;
    int length;
    int top ;

    Stack (int len ) {
        length = len;
        A = new T [length];
        top = -1;
    }
    ~Stack(){ delete A;}
    void Display(){
        if(ifEmpty()) return;
        for(int i=0 ; i<= top; i++ ) {cout << A[i] << " ";}
        cout << endl;
    }
    void push(T key){
        if(!ifFull()) A[++top] = key;
        else cout << " not enough space " << endl;
    }
    T pop(){ return (!ifEmpty()) ? A[top--] : 0 ;}
    T stackTop() { return( (top >= 0) ? A[top] : 0 );}
    T peek(int pos) {return (pos <= top+1 && top>=0 && pos > 0 ) ? A[pos-1] : NULL; }
    bool ifEmpty () {return (top == -1);}
    bool ifFull () {return (length-1 == top) ;}
    int Count() { return top + 1;}
} ;

//node structure used for tree representation 
class Node {
    public : 
    int data;
    Node *lft =NULL ,*rht =NULL;
    Node (int x = 0){data =x;}
};

//Class for binary tree representation
class BinTree {
    protected : 
    Node *root; 
    public : 
        BinTree(){root = NULL;}
        void CreateTree();

        void Preorder (Node* p);
        void Preorder () { Preorder (root); cout << endl;}

        void Postorder(Node* p);
        void Postorder() { Postorder(root); cout << endl;}

        void Inorder  (Node* p);
        void Inorder  () { Inorder  (root); cout << endl;}

        void Levelorder();

        int Height (Node*p);
        int Height () { return Height(root);}
        int Count (Node *p);
        int Count () { return Count(root) ;}

        //some more meathods to learn implemnetation 
        //Iterative orders 
        void ITR_Preorder();
        void ITR_Inorder();
        void ITR_Postorder();
        void ITR_Levelorder();
};
void BinTree :: CreateTree () {
    Node *p ,*t;
    int x = 0;
    cout << "Input root Node data "<< endl;
    cin >> x ;
    CQueue<Node*>  q(100);
    root = new Node(x);
    q.enqueue( root );
    while(!q.isEmpty()) {
        p = q.dequeue();

        cout << "Enter left child of " << p->data << " : " ;
        cin >> x ;
        if(x!= -1) {
            t = new Node(x) ;
            p->lft = t;
            q.enqueue(t);
        }
        cout << "Enter right child of "<< p->data << " : " ;
        cin >> x ;
        if(x!= -1) {
            t = new Node(x) ;
            p->rht = t;
            q.enqueue(t);
        }
    }
}
void BinTree :: Preorder( Node *p ){
        if(p){
            cout << p->data << " ";
            Preorder ( p->lft) ;
            Preorder ( p->rht) ;
        }
}
void BinTree :: Postorder( Node *p ){
        if(p){
            Postorder ( p->lft) ;
            Postorder ( p->rht) ;
            cout << p->data << " ";
        }
}
void BinTree :: Inorder( Node *p ){
        if(p){
            Inorder ( p->lft) ;
            cout << p->data << " ";
            Inorder ( p->rht) ;
        }
}
int  BinTree :: Height (Node *p){
    int x = 0 ; int y = 0 ;
    if( !p) return 0;
    x = Height(p->lft);
    y = Height(p->rht);
    if(x>y) return x+1;
    else return y+1;
}
int  BinTree :: Count (Node *p) {return p ? (Count(p->lft) + Count(p->rht) + 1) : 0;}
void BinTree :: Levelorder ( ) {
    CQueue<Node*>  q(100);
    cout << root->data << " ";
    q.enqueue(root);
    Node *t = root ;
    while( !q.isEmpty()) {
        t = q.dequeue ();
        if( t->lft){
            cout << t->lft->data << " ";
            q.enqueue(t->lft) ;
        }
        if( t->rht){
            cout << t->rht->data << " ";
            q.enqueue(t->rht) ;
        }
    }

    cout << endl;
}

void BinTree :: ITR_Preorder(){
    Stack<Node*> st(50);
    Node *t = root;

    while(t!=NULL || !st.ifEmpty()){
        if(t!=NULL){
            cout << t->data << " "; 
            st.push(t);
            Plft(t);
        }
        else {
            t = st.pop();
            Prht(t);
        }
    }
    
}
void BinTree :: ITR_Inorder (){
    Node *t = root ;
    Stack<Node*> st(100);
    while(t!=NULL || !st.ifEmpty() ){
        if(t!=NULL){
            st.push(t);
            Plft(t);
        }
        else{
            t = st.pop();
            cout<< t->data << " ";
            Prht(t);
        }
    }
    cout << endl;
}
void BinTree :: ITR_Postorder() {
    //need to be properly implemnted not working actully 
    Node *t = root;
    Stack<Node*> st(100);
    Stack<int> h(100);
    while( t!=NULL && !st.ifEmpty()){
        if(t!=NULL){
            st.push(t);
            h.push(1);
            Plft(t);
        }
        else {
            st.pop();
            int x = h.pop();
            if(x>0){
                h.push(-1);
                Prht(t);
            }
            else {
                cout << t->data << " ";
                t = NULL;
            }
        }
    }
    cout << endl;
}
void BinTree :: ITR_Levelorder(){
    CQueue<Node*> q(100);
    q.enqueue(root);
    Node *p ;
    while( p!=NULL && !q.isEmpty()){
        p = q.dequeue();
        cout << p->data << " ";
        if(p->lft) q.enqueue(p->lft);
        if(p->rht) q.enqueue(p->rht);
    }
    cout << endl;
}

// Class for Binary Search Trees implementation
class BinSearchTree : private BinTree {
    public : 
    void Insert(int);
    Node* RInsert(int , Node*);
    Node* RInsert(int k) { if(root) return RInsert(k,root); else {
        Node * t = new Node(k);
        root = t;
        return root;
    }}
    void Inorder(Node*);
    void Inorder() {Inorder(root); cout << endl;}
    Node* Search(int);
    Node* Delete(int , Node*);
    Node* Delete(int k) { return Delete(k,root);}
    int Height(Node*p);
    Node* Inpre(Node *);
    Node* InSucc(Node *);
};

void BinSearchTree :: Insert(int key) {
    Node *t,*r,*p = root;
    t = new Node(key);
    if( root == NULL ){
        root = t;
        return ;
    }
    while(p!=NULL){
        r = p;
        if(key < p->data) Plft(p);
        else if(key > p->data) Prht(p);
        else return;
    }
    if(key < r->data) r->lft = t;
    else r->rht = t;
}
Node* BinSearchTree :: RInsert(int key , Node *p ){
    Node *t ;
    if(p==NULL){
        t = new Node(key);
        return t;
    }
    if(key<p->data) p->lft = RInsert(key, p->lft);
    else if ( key > p->data) p->rht = RInsert(key , p->rht);

    return p;
}

void BinSearchTree:: Inorder(Node * p){
    if(p){
        Inorder(p->lft);
        cout << p->data << " ";
        Inorder(p->rht);
    }
}
Node* BinSearchTree :: Search(int key){
    Node *t = root;
    while(t){
        if(key==t->data) return t;
        else if (key < t->data) t= t->lft;
        else t=t->rht;
    }
    return NULL;
}

int BinSearchTree :: Height(Node*p){
    int x,y;
    if(p==NULL) return 0;
    x = Height(p->lft);
    y = Height(p->rht);
    return x>y ? x+1:y+1;
}
Node* BinSearchTree :: Inpre(Node *p){
    while(p!=NULL && p->rht != NULL){
        p = p->rht;
        
    }
    return p;
}
Node* BinSearchTree :: InSucc(Node*p){
    while(p!=NULL && p->lft != NULL){
        p = p->lft;
    }
    return p;
}

Node* BinSearchTree :: Delete(int key , Node*p){

    Node *q ;
    if(p==NULL) return NULL;
    if(p->lft == NULL && p->rht == NULL ){
        if(p==root) root = NULL;
        delete p;
        return NULL;
    }
    if(key < p->data) p->lft = Delete(key,p->lft);
    else if(key > p->data) p->rht = Delete(key,p->rht);
    else{
        //checking height of both side of p
        if(Height(p->lft) > Height(p->rht)) {
            q = Inpre(p->lft);
            p->data = q->data;
            p->lft = Delete(q->data,p->lft);
        }
        else {
            q = InSucc(p->rht);
            p->data = q->data;
            p->rht = Delete(q->data,p->rht);
        }
    }
    
    return p;
}



