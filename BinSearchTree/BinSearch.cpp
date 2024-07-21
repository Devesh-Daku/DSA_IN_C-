#include"./TemplateBinTree.h"


class BinSearchTree : public BinTree {
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

// //Generating bst from preorder array 
// class BSTPreorder : public BinSearchTree {
//     Node * root;
//     public : 
//     BSTPreorder(int A[] , int n);
//     // TODO: pending 
// };
// BSTPreorder :: BSTpreorder(int A[] , int n) {
//     root = RInsert(A[0]);
//     Stack<Node*> st(100);

//     for(int i=1 ; i< n; i++ ) {
        
//     }
    
// }

int main () {
    BinSearchTree B;
    B.RInsert(10);
    B.RInsert(11);
    B.RInsert(14);
    B.RInsert(7);
    B.RInsert(13);

    B.Inorder();

    if(B.Search(15)) cout << "key element is found" << endl;
    else cout << "key element is not found "<< endl;
    cout << endl;

    // B.Delete(11);
    // B.Inorder();
    // B.Delete(13);
    // B.Inorder();
    
    B.PrintTree();
    return 0;
}