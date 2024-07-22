// we gonna need queue data structure for generatign a tree
#include<iostream>
using namespace std;
#define Plft(p) p = p->lft
#define Prht(p) p = p->rht
#define ll long int
#include <iomanip>
#include<stack>
#include<queue>
#include<math.h>

class Node {
    public : 
    int data;
    Node *lft =NULL ,*rht =NULL;
    Node (int x = 0){data =x;}
};

class BinTree {
    protected:
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
        int Count () { return Count(root);}

        //some more methods to learn implementation 
        //Iterative orders 
        void ITR_Preorder();
        void ITR_Inorder();
        void ITR_Postorder();
        void ITR_Levelorder();

        // printing the tree : 
        void PrintTree();
};
void BinTree :: CreateTree () {
    Node *p ,*t;
    int x = 0;
    cout << "Input root Node data (-1 for null)  : "<< endl;
    cin >> x ;
    queue<Node*>  q;
    root = new Node(x);
    
    q.push( root );
    while(!q.empty()) {
        p = q.front();
        q.pop();

        cout << "Enter left child of (-1 for null) " << p->data << " : " ;
        cin >> x ;
        if(x!= -1) {
            t = new Node(x) ;
            p->lft = t;
            q.push(t);
        }
        cout << "Enter right child of (-1 for null) "<< p->data << " : " ;
        cin >> x ;
        if(x!= -1) {
            t = new Node(x) ;
            p->rht = t;
            q.push(t);
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
    queue<Node*>  q;
    cout << root->data << " ";
    q.push(root);
    Node *t = root ;
    while( !q.empty()) {
        t = q.front();
        q.pop();
        if( t->lft){
            cout << t->lft->data << " ";
            q.push(t->lft) ;
        }
        if( t->rht){
            cout << t->rht->data << " ";
            q.push(t->rht) ;
        }
    }

    cout << endl;
}

void BinTree :: ITR_Preorder(){
    stack<Node*> st;
    Node *t = root;

    while(t!=NULL || !st.empty()){
        if(t!=NULL){
            cout << t->data << " "; 
            st.push(t);
            Plft(t);
        }
        else {
            t = st.top();
            st.pop();
            Prht(t);
        }
    }
    
}
void BinTree :: ITR_Inorder (){
    Node *t = root ;
    stack<Node*> st;
    while(t!=NULL || !st.empty() ){
        if(t!=NULL){
            st.push(t);
            Plft(t);
        }
        else{
            t = st.top();
            st.pop();
            cout<< t->data << " ";
            Prht(t);
        }
    }
    cout << endl;
}
void BinTree :: ITR_Postorder() {
    //need to be properly implemnted not working actully 
    Node *t = root;
    stack<Node*> st;
    stack<int> h;
    while( t!=NULL && !st.empty()){
        if(t!=NULL){
            st.push(t);
            h.push(1);
            Plft(t);
        }
        else {
            st.pop();
            int x = h.top();
            h.pop();
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
    queue<Node*> q;
    q.push(root);
    Node *p ;
    while( p!=NULL && !q.empty()){
        p = q.front();
        q.pop();
        cout << p->data << " ";
        if(p->lft) q.push(p->lft);
        if(p->rht) q.push(p->rht);
    }
    cout << endl;
}
#define digitSize 2
void BinTree::PrintTree() {
    if (!root) return;

    int height = Height(root) ;
    int h = height;
    // int maxWidth = pow(2, height) - 1; // Maximum width of the tree at the bottom level

    queue<Node*> q;
    q.push(root);
    int maxWidth = pow(2,h);
    
       

    
    int leadingSpaces = maxWidth/2;
    for (int level = 0; level < height; ++level) {

        int levelNodeCount = q.size();
         
        int spacesBetween = maxWidth / pow(2,levelNodeCount); // Calculate spaces between nodes

        // Print leading spaces
        for (int s = 0; s < (leadingSpaces-1)*(digitSize+1) ; ++s) cout << " ";
        h--;

        for (int i = 0; i < levelNodeCount; ++i) {
            Node* currentNode = q.front();
            q.pop();

            // Print node data
            if (currentNode) {
                cout << setw(digitSize) << currentNode->data  ;
                q.push(currentNode->lft);
                q.push(currentNode->rht);
                // if(h>0)
                // for (int s = 0; s < leadingSpaces*2 +h ; ++s) cout << "  ";
                // else 
                for (int s = 0; s < ((int)(( leadingSpaces + (float)h/digitSize )*2.0 ))*(digitSize+1) ; ++s) cout << " ";
            }
            else {
                cout << " ";
                q.push(nullptr);
                q.push(nullptr);
            }




            // Print spaces between nodes
        }
        // cout << endl <<"leading spaces and maxwidth and level node are are " << leadingSpaces  << " " << levelNodeCount ;
        cout << endl;
        // maxWidth /= 2;
            
        leadingSpaces = leadingSpaces/2;
    }
}
